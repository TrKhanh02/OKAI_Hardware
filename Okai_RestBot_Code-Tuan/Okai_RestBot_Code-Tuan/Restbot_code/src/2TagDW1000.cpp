#include <Arduino.h>
#include <Print.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <RCSwitch.h>
#include "SoftwareSerial.h"
#include "LIDAR_MODULE.h"
#include <stdarg.h>
#include <math.h> 

// =================================================================
// ROBOT TYPE CONFIGURATION
// =================================================================
#define ROBOT_TYPE_CARLIKE 1
#define ROBOT_TYPE_2WHEEL 2

#define ROBOT_TYPE ROBOT_TYPE_2WHEEL

#if !defined(ROBOT_TYPE)
#error "select type of robot by defining ROBOT_TYPE"
#endif

// =================================================================
// CONFIGURATION
// =================================================================
namespace Config
{
    // Network
    const char *WIFI_SSID = "OKAI2";
    const char *WIFI_PASSWORD = "prv@101024";
    const char *MQTT_SERVER = "103.216.117.71";
    const int MQTT_PORT = 8883;
    const char *MQTT_USER = "robot";
    const char *MQTT_PASSWORD = "robot";

    // MQTT Topics
    const char *TOPIC_TARGET = "device/command";        
    const char *TOPIC_POSITION_PUB = "device/position"; 

    // Timeouts
    const unsigned long WIFI_RECONNECT_INTERVAL = 30000;
    const unsigned long MQTT_RECONNECT_INTERVAL = 5000;
    const unsigned long RF_TIMEOUT = 1000;
    const unsigned long STUCK_TIMEOUT = 5000;
    const unsigned long ANCHOR_TIMEOUT = 2000; 
    const unsigned long POSITION_PUBLISH_INTERVAL = 200; 

    // Navigation
    const float DISTANCE_TOLERANCE = 50.0f;
    const float ANGLE_TOLERANCE = 14.0f;
    const float PROGRESS_THRESHOLD = 5.0f;
    const float MIN_SAFE_DISTANCE_FRONT = 50.0f;
    const float halfAngle = 45.0f;

    // Motor Control
    const int MAX_SPEED = 80;
    const int MOVE_SPEED = 25;
    const int TURN_SPEED = 15;
    const int AVOID_TURN_SPEED = 10;
    const int MAX_STEER_ANGLE = 45;
    const float KP_STEER = 1.8f;
    const int MIN_TURN_SPEED = 7;
    const float KP_TURN_2WHEEL = 0.3f;

    // Recovery
    const unsigned long RECOVERY_BACKUP_DURATION = 500;
    const unsigned long RECOVERY_TURN_DURATION = 500;
    const int MAX_RECOVERY_ATTEMPTS = 5;
    
    // Heading Configuration (Multi-Anchor)
    const float TAG_SEPARATION_CM = 30.0f;
    const float HEADING_SMOOTHING_FACTOR = 0.7f; // EMA smoothing
}

// =================================================================
// GLOBAL OBJECTS
// =================================================================
RCSwitch mySwitch = RCSwitch();
LidarModule frontLidar(33, -1);
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

#define RF_RECEIVER_PIN 36
// Serial for Nuvoton MCU
#define NUVOTON_RX 39
#define NUVOTON_TX 19
SoftwareSerial NUVOTON_SERIAL(NUVOTON_RX, NUVOTON_TX);  // RX, TX
// UWB Serial for Tag 6
#define UWB_SERIAL_TAG6 Serial2
#define UWB_RX_PIN_TAG6 35      
#define UWB_TX_PIN_TAG6 -1

// Serial for Tag 5
#define UWB_SERIAL_TAG5 Serial   
#define UWB_RX_PIN_TAG5 4
#define UWB_TX_PIN_TAG5 -1
#define NUM_ANCHORS 3
#define TAG_HEIGHT 0.0f // 20cm

// =================================================================
// DATA STRUCTURES
// =================================================================
enum RobotState
{
    IDLE,
    NAVIGATING_TO_TARGET,
    OBSTACLE_AVOIDANCE,
    RECOVERY_STUCK,
    TARGET_REACHED
};
enum ObstacleAvoidancePhase {
    AVOID_SCANNING,
    AVOID_MOVING,
};

enum NavigationSubState
{
    SUB_IDLE,
    SUB_TURNING,
    SUB_MOVING
};

struct Position
{
    float x = 0.0f;
    float y = 0.0f;
    unsigned long lastUpdate = 0;

    bool isValid() const
    {
        return (millis() - lastUpdate) < Config::ANCHOR_TIMEOUT * 2;
    }

    void update(float newX, float newY)
    {
        x = newX;
        y = newY;
        lastUpdate = millis();
    }
};

struct RFData
{
    uint8_t joy1_x = 0, joy1_y = 0, joy2_x = 0, joy2_y = 0;
    bool valid = false;
    unsigned long lastReceived = 0;
};

struct TimedAction
{
    unsigned long startTime = 0;
    unsigned long duration = 0;
    bool active = false;

    void start(unsigned long durationMs)
    {
        startTime = millis();
        duration = durationMs;
        active = true;
    }

    bool isComplete() const
    {
        return active && (millis() - startTime >= duration);
    }

    void stop()
    {
        active = false;
    }
};

struct Anchor
{
    float x, y, z;
    float distance;
    unsigned long lastUpdate;

    Anchor(float _x, float _y, float _z) : x(_x), y(_y), z(_z), distance(-1.0f), lastUpdate(0) {}

    bool isValid() const
    {
        return (distance > 0 && (millis() - lastUpdate) < Config::ANCHOR_TIMEOUT);
    }
};

struct TagRangeData
{
    uint16_t addr = 0;
    float distances[3] = {0.0f, 0.0f, 0.0f}; // d1, d2, d3
    unsigned long lastUpdate = 0;

    void update(float d1, float d2, float d3)
    {
        distances[0] = d1;
        distances[1] = d2;
        distances[2] = d3;
        lastUpdate = millis();
    }

    bool isValid() const
    {
        return (millis() - lastUpdate) < Config::ANCHOR_TIMEOUT;
    }
};

struct HeadingData
{
    float angle = 0.0f;
    float rawAngle = 0.0f; // Góc chưa smooth
    bool valid = false;
    unsigned long lastUpdate = 0;
    float totalConfidence = 0.0f; // Tổng confidence từ các anchor
    int validAnchorCount = 0; // Số anchor valid

    void update(float absoluteAngle, bool isValid, float confidence = 0.0f, int anchorCount = 0)
    {
        rawAngle = absoluteAngle;
        
        // Exponential Moving Average smoothing
        if (valid && isValid) {
            // Xử lý circular averaging qua 0°/360°
            float diff = absoluteAngle - angle;
            if (diff > 180.0f) diff -= 360.0f;
            if (diff < -180.0f) diff += 360.0f;
            
            angle = angle + Config::HEADING_SMOOTHING_FACTOR * diff;
            if (angle < 0.0f) angle += 360.0f;
            if (angle >= 360.0f) angle -= 360.0f;
        } else {
            angle = absoluteAngle;
        }
        
        valid = isValid;
        totalConfidence = confidence;
        validAnchorCount = anchorCount;
        lastUpdate = millis();
    }
};

struct HeadingResult {
    float angle;
    float confidence;
    bool valid;
};

// =================================================================
// GLOBAL STATE
// =================================================================
HeadingData currentHeadingState;
Position currentPos, targetPos;   
RFData rfData;
RobotState currentState = IDLE;
NavigationSubState navSubState = SUB_IDLE;
bool autoMode = false;
unsigned long lastPositionPublish = 0; 
bool positionWasLost = true;

// Dữ liệu Ranging của 2 Tag
TagRangeData tag5Data; // Tag 5 (MY_ADDRESS = 5)
TagRangeData tag6Data; // Tag 6 (SLAVE_TAG_ADDR = 6)

// ===== MODIFIED FOR ROUTE =====
#define MAX_ROUTE_TARGETS 10 
Position targetQueue[MAX_ROUTE_TARGETS];
int currentTargetIndex = -1; 
int totalTargetsInQueue = 0; 
// ==============================


Anchor anchors[3] = {
    Anchor(0.0f, 0.0f, 2.1f),
    Anchor(0.0f, 3.0f, 1.8f),
    Anchor(5.0f, 0.0f, 2.1f)
};
// Anti-stuck tracking
unsigned long lastProgressTime = 0;
float lastDistanceToTarget = 9999.0f;
int recoveryAttempts = 0;

TimedAction timedAction;

// Network tracking
unsigned long lastWifiCheck = 0;
unsigned long lastMqttAttempt = 0;

// Command caching
struct
{
    int angelA = -999, dutyAngelA = -999;
    int angelB = -999, dutyAngelB = -999;
    int m1_dir = -1, m1_duty = -1;
    int m2_dir = -1, m2_duty = -1;
} lastCommand;

// =================================================================
// UTILITY FUNCTIONS
// =================================================================
static inline float normalizeAngleDeg(float ang)
{
    while (ang >= 360.0f)
        ang -= 360.0f;
    while (ang < 0.0f)
        ang += 360.0f;
    return ang;
}

static inline float normalizeAngleError(float ang)
{
    while (ang > 180.0f)
        ang -= 360.0f;
    while (ang < -180.0f)
        ang += 360.0f;
    return ang;
}

const char *getStateName(RobotState state)
{
    static const char *names[] = {
        "IDLE", "NAVIGATING", "OBSTACLE_AVOID", "RECOVERY", "TARGET_REACHED"};
    return names[state];
}

void logToSerialAndMqtt(const char *format, ...)
{
    char buf[256];
    va_list args;
    va_start(args, format);
    vsnprintf(buf, sizeof(buf), format, args);
    va_end(args);

    Serial.println(buf);

    if (mqttClient.connected())
    {
        const char *DEBUG_TOPIC = "robot/debug_log";
        mqttClient.publish(DEBUG_TOPIC, buf);
    }
}

// =================================================================
// UWB HANDLING & MULTI-ANCHOR HEADING CALCULATION
// =================================================================

bool setAnchorDistancesForTrilateration() {
    if (!tag5Data.isValid()) return false;
    
    for (int i = 0; i < NUM_ANCHORS; i++) {
        anchors[i].distance = tag5Data.distances[i];
        anchors[i].lastUpdate = tag5Data.lastUpdate;
    }
    return true;
}

bool allAnchorsReady()
{
    return anchors[0].isValid() && anchors[1].isValid() && anchors[2].isValid();
}

bool computeTrilateration(float &x, float &y)
{
    if (!allAnchorsReady())
    {
        return false;
    }

    float x1 = anchors[0].x, y1 = anchors[0].y, z1 = anchors[0].z;
    float x2 = anchors[1].x, y2 = anchors[1].y, z2 = anchors[1].z;
    float x3 = anchors[2].x, y3 = anchors[2].y, z3 = anchors[2].z;

    float dz1 = z1 - TAG_HEIGHT;
    float dz2 = z2 - TAG_HEIGHT;
    float dz3 = z3 - TAG_HEIGHT;

    float d1_sq = anchors[0].distance * anchors[0].distance;
    float d2_sq = anchors[1].distance * anchors[1].distance;
    float d3_sq = anchors[2].distance * anchors[2].distance;

    float r1_sq = d1_sq - dz1 * dz1;
    float r2_sq = d2_sq - dz2 * dz2;
    float r3_sq = d3_sq - dz3 * dz3;

    if (r1_sq < 0 || r2_sq < 0 || r3_sq < 0)
    {
        return false;
    }

    float A = 2 * (x2 - x1);
    float B = 2 * (y2 - y1);
    float C = r1_sq - r2_sq - x1 * x1 + x2 * x2 - y1 * y1 + y2 * y2;

    float D = 2 * (x3 - x1);
    float E = 2 * (y3 - y1);
    float F = r1_sq - r3_sq - x1 * x1 + x3 * x3 - y1 * y1 + y3 * y3;

    float denom = (A * E - B * D);
    if (fabs(denom) < 1e-6)
    {
        return false;
    }

    x = (C * E - B * F) / denom;
    y = (A * F - C * D) / denom;

    return true;
}

void updateRobotPosition()
{
    float x, y;
    if (setAnchorDistancesForTrilateration() && computeTrilateration(x, y))
    {
        currentPos.update(x * 100.0f, y * 100.0f); // cm
        positionWasLost = false;
    }
    else
    {
        positionWasLost = true;
    }
}

// =================================================================
// MULTI-ANCHOR HEADING CALCULATION
// =================================================================

/**
 * Tính heading từ 1 anchor cụ thể
 */
HeadingResult calculateHeadingFromAnchor(uint8_t anchorIdx) {
    HeadingResult result = {0.0f, 0.0f, false};
    
    if (!tag5Data.isValid() || !tag6Data.isValid() || !currentPos.isValid()) {
        return result;
    }
    
    if (!anchors[anchorIdx].isValid()) {
        return result;
    }
    
    // Khoảng cách 3D từ mỗi tag đến anchor
    float D1 = tag5Data.distances[anchorIdx]; // Tag 5 (mét)
    float D2 = tag6Data.distances[anchorIdx]; // Tag 6 (mét)
    float L = Config::TAG_SEPARATION_CM / 100.0f; // Baseline length (mét)
    
    // Vị trí anchor và robot (cm -> m)
    float anchor_x = anchors[anchorIdx].x;
    float anchor_y = anchors[anchorIdx].y;
    float anchor_z = anchors[anchorIdx].z;
    
    float robot_x = currentPos.x / 100.0f;
    float robot_y = currentPos.y / 100.0f;
    
    // Loại bỏ thành phần Z
    float dZ = anchor_z - TAG_HEIGHT;
    
    float R1_sq = D1 * D1 - dZ * dZ;
    float R2_sq = D2 * D2 - dZ * dZ;

    if (R1_sq < 0 || R2_sq < 0) {
        return result;
    }
    
    float R1 = sqrtf(R1_sq);
    float R2 = sqrtf(R2_sq);
    
    // Vector từ robot đến anchor
    float dx_anchor = anchor_x - robot_x;
    float dy_anchor = anchor_y - robot_y;
    float dist_to_anchor = sqrtf(dx_anchor * dx_anchor + dy_anchor * dy_anchor);
    
    if (dist_to_anchor < 0.1f) {
        return result; // Quá gần anchor
    }
    
    // Unit vector đến anchor
    float ux_anchor = dx_anchor / dist_to_anchor;
    float uy_anchor = dy_anchor / dist_to_anchor;
    
    // Tính delta R và perpendicular
    float delta_R = R1 - R2;
    
    if (fabs(delta_R) > L) {
        delta_R = (delta_R > 0) ? L : -L;
    }
    
    float perpendicular_sq = L * L - delta_R * delta_R;
    if (perpendicular_sq < 0) {
        perpendicular_sq = 0;
    }
    float perpendicular = sqrtf(perpendicular_sq);
    
    // Vector vuông góc
    float ux_perp = -uy_anchor;
    float uy_perp = ux_anchor;
    
    // 2 candidate vectors
    float bx_candidate1 = ux_anchor * delta_R + ux_perp * perpendicular;
    float by_candidate1 = uy_anchor * delta_R + uy_perp * perpendicular;
    
    float bx_candidate2 = ux_anchor * delta_R - ux_perp * perpendicular;
    float by_candidate2 = uy_anchor * delta_R - uy_perp * perpendicular;
    
    // Chuẩn hóa
    float len1 = sqrtf(bx_candidate1 * bx_candidate1 + by_candidate1 * by_candidate1);
    float len2 = sqrtf(bx_candidate2 * bx_candidate2 + by_candidate2 * by_candidate2);
    
    if (len1 > 0.001f) {
        bx_candidate1 = (bx_candidate1 / len1) * L;
        by_candidate1 = (by_candidate1 / len1) * L;
    }
    
    if (len2 > 0.001f) {
        bx_candidate2 = (bx_candidate2 / len2) * L;
        by_candidate2 = (by_candidate2 / len2) * L;
    }
    
    // Chọn candidate tốt nhất
    float tag6_x1 = robot_x + bx_candidate1;
    float tag6_y1 = robot_y + by_candidate1;
    
    float tag6_x2 = robot_x + bx_candidate2;
    float tag6_y2 = robot_y + by_candidate2;
    
    float dist_tag6_1 = sqrtf((anchor_x - tag6_x1) * (anchor_x - tag6_x1) + 
                               (anchor_y - tag6_y1) * (anchor_y - tag6_y1));
    
    float dist_tag6_2 = sqrtf((anchor_x - tag6_x2) * (anchor_x - tag6_x2) + 
                               (anchor_y - tag6_y2) * (anchor_y - tag6_y2));
    
    float error1 = fabs(dist_tag6_1 - R2);
    float error2 = fabs(dist_tag6_2 - R2);
    
    float baseline_x, baseline_y, geometric_error;
    
    if (error1 < error2) {
        baseline_x = bx_candidate1;
        baseline_y = by_candidate1;
        geometric_error = error1;
    } else {
        baseline_x = bx_candidate2;
        baseline_y = by_candidate2;
        geometric_error = error2;
    }
    
    // Tính heading
    float baseline_angle = atan2f(baseline_x, baseline_y) * 180.0f / PI;
    baseline_angle = normalizeAngleDeg(baseline_angle);
    
    float absolute_heading = baseline_angle + 180.0f;
    absolute_heading = normalizeAngleDeg(absolute_heading);
    
    // Tính độ tin cậy
    float distance_factor = 1.0f / (1.0f + dist_to_anchor / 5.0f);
    float error_factor = 1.0f / (1.0f + geometric_error * 10.0f);
    float geometry_factor = perpendicular / L;
    
    result.angle = absolute_heading;
    result.confidence = distance_factor * error_factor * geometry_factor;
    result.valid = true;
    
    return result;
}

/**
 * Tính trung bình có trọng số từ nhiều góc (Circular Mean)
 */
float weightedCircularMean(HeadingResult* results, int count) {
    if (count == 0) return 0.0f;
    
    float sum_x = 0.0f;
    float sum_y = 0.0f;
    float total_weight = 0.0f;
    
    for (int i = 0; i < count; i++) {
        if (!results[i].valid) continue;
        
        float rad = results[i].angle * PI / 180.0f;
        float weight = results[i].confidence;
        
        sum_x += cosf(rad) * weight;
        sum_y += sinf(rad) * weight;
        total_weight += weight;
    }
    
    if (total_weight < 0.001f) return 0.0f;
    
    sum_x /= total_weight;
    sum_y /= total_weight;
    
    float mean_angle = atan2f(sum_y, sum_x) * 180.0f / PI;
    return normalizeAngleDeg(mean_angle);
}

/**
 * MAIN FUNCTION: Tính heading từ cả 3 anchor
 */
bool calculateMultiAnchorHeading() {
    if (!tag5Data.isValid() || !tag6Data.isValid() || !currentPos.isValid()) {
        currentHeadingState.update(0.0f, false);
        return false;
    }
    
    // Tính heading từ mỗi anchor
    HeadingResult results[3];
    int valid_count = 0;
    
    for (int i = 0; i < 3; i++) {
        results[i] = calculateHeadingFromAnchor(i);
        if (results[i].valid) {
            valid_count++;
            logToSerialAndMqtt("[Heading] A%d: %.1f° conf:%.3f", 
                             i+1, results[i].angle, results[i].confidence);
        }
    }
    
    if (valid_count == 0) {
        currentHeadingState.update(0.0f, false);
        return false;
    }
    
    // Tính trung bình có trọng số
    float final_heading = weightedCircularMean(results, 3);
    
    // Tính tổng confidence
    float total_confidence = 0.0f;
    for (int i = 0; i < 3; i++) {
        if (results[i].valid) {
            total_confidence += results[i].confidence;
        }
    }
    
    currentHeadingState.update(final_heading, true, total_confidence, valid_count);
    
    logToSerialAndMqtt("[Heading] FINAL: %.1f° (smooth:%.1f°, %d anchors, conf:%.3f)", 
                      currentHeadingState.rawAngle, currentHeadingState.angle, 
                      valid_count, total_confidence);
    
    return true;
}

void handleUWBInput()
{
    bool positionUpdated = false;
    
    // ========== ĐỌC TỪ TAG 5 ==========
    if (UWB_SERIAL_TAG5.available())
    {
        String data = UWB_SERIAL_TAG5.readStringUntil('\n');
        JsonDocument doc;

        if (deserializeJson(doc, data).code() == DeserializationError::Ok)
        {
            if (doc.containsKey("addr") && doc["addr"] == 5)
            {
                if (doc.containsKey("d1") && doc.containsKey("d2") && doc.containsKey("d3"))
                {
                    float d1 = doc["d1"];
                    float d2 = doc["d2"];
                    float d3 = doc["d3"];
                    
                    tag5Data.addr = 5;
                    tag5Data.update(d1, d2, d3);
                    positionUpdated = true;
                }
            }
        }
    }
    
    // ========== ĐỌC TỪ TAG 6 ==========
    if (UWB_SERIAL_TAG6.available())
    {
        String data = UWB_SERIAL_TAG6.readStringUntil('\n');
        JsonDocument doc;

        if (deserializeJson(doc, data).code() == DeserializationError::Ok)
        {
            if (doc.containsKey("addr") && doc["addr"] == 6)
            {
                if (doc.containsKey("d1") && doc.containsKey("d2") && doc.containsKey("d3"))
                {
                    float d1 = doc["d1"];
                    float d2 = doc["d2"];
                    float d3 = doc["d3"];
                    
                    tag6Data.addr = 6;
                    tag6Data.update(d1, d2, d3);
                    positionUpdated = true;
                }
            }
        }
    }
    
    // ========== TÍNH TOÁN POSITION & HEADING ==========
    if (positionUpdated)
    {
        updateRobotPosition(); // Dùng Tag 5 để tính vị trí
        if (currentPos.isValid()) {
            calculateMultiAnchorHeading(); // Dùng cả 3 anchor
        }
    }
}

void publishPosition()
{
    if (!mqttClient.connected() || !currentPos.isValid())
    {
        return;
    }

    unsigned long now = millis();
    if (now - lastPositionPublish < Config::POSITION_PUBLISH_INTERVAL)
    {
        return;
    }
    lastPositionPublish = now;

    JsonDocument doc;
    doc["x"] = currentPos.x;
    doc["y"] = currentPos.y;
    doc["timestamp"] = now;

    char buffer[128];
    size_t n = serializeJson(doc, buffer);

    mqttClient.publish(Config::TOPIC_POSITION_PUB, buffer, n);
}

// =================================================================
// MOTOR CONTROL
// =================================================================
void sendCarLikeCommand(int angelA, int dutyAngelA, int angelB, int dutyAngelB, int dirMotorA, int dutyMotorA, int dirMotorB, int dutyMotorB)
{
    bool isSameCommand = (angelA == lastCommand.angelA && dutyAngelA == lastCommand.dutyAngelA &&
                          angelB == lastCommand.angelB && dutyAngelB == lastCommand.dutyAngelB &&
                          dirMotorA == lastCommand.m1_dir && dutyMotorA == lastCommand.m1_duty &&
                          dirMotorB == lastCommand.m2_dir && dutyMotorB == lastCommand.m2_duty);

    if (isSameCommand)
        return;

    char buf[128];
    snprintf(buf, sizeof(buf), "%d,%d,%d,%d,%d,%d,%d,%d|\n",
             angelA, dutyAngelA, angelB, dutyAngelB,
             dirMotorA, dutyMotorA, dirMotorB, dutyMotorB);
    NUVOTON_SERIAL.print(buf);

    lastCommand.angelA = angelA;
    lastCommand.dutyAngelA = dutyAngelA;
    lastCommand.angelB = angelB;
    lastCommand.dutyAngelB = dutyAngelB;
    lastCommand.m1_dir = dirMotorA;
    lastCommand.m1_duty = dutyMotorA;
    lastCommand.m2_dir = dirMotorB;
    lastCommand.m2_duty = dutyMotorB;
}

void stopAll()
{
    sendCarLikeCommand(0, 0, 0, 0, 0, 0, 0, 0);
    delay(10);
}

void driveCarLike(int angle, int speed)
{
    int dir = (speed >= 0) ? 1 : 0;
    int motorDuty = abs(speed);
    sendCarLikeCommand(angle, 50, angle, 50, dir, motorDuty, dir, motorDuty);
}

void driveDifferential(int leftSpeed, int rightSpeed)
{
    leftSpeed = constrain(leftSpeed, -Config::MAX_SPEED, Config::MAX_SPEED);
    rightSpeed = constrain(rightSpeed, -Config::MAX_SPEED, Config::MAX_SPEED);

    int leftDir = (leftSpeed >= 0) ? 1 : 0;
    int leftDuty = abs(leftSpeed);

    int rightDir = (rightSpeed >= 0) ? 1 : 0;
    int rightDuty = abs(rightSpeed);

    sendCarLikeCommand(0, 0, 0, 0, leftDir, leftDuty, rightDir, rightDuty);
}

// =================================================================
// SENSOR HANDLERS
// =================================================================

void handleRFInput()
{
    if (!mySwitch.available())
        return;

    uint32_t val = mySwitch.getReceivedValue();
    mySwitch.resetAvailable();

    static uint32_t lastDataValue = 0;
    if (val == 0 || val == lastDataValue)
        return;
    lastDataValue = val;

    rfData.joy1_x = (val >> 16) & 0x0F;
    rfData.joy1_y = (val >> 12) & 0x0F;
    rfData.joy2_x = (val >> 6) & 0x0F;
    rfData.joy2_y = (val >> 2) & 0x0F;
    rfData.valid = true;
    rfData.lastReceived = millis();
}

// =================================================================
// NETWORK MANAGEMENT
// =================================================================
void setupWiFi()
{
    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(true);
    WiFi.begin(Config::WIFI_SSID, Config::WIFI_PASSWORD);

    Serial.print("Connecting to WiFi");
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20)
    {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("\n✓ WiFi connected! IP: " + WiFi.localIP().toString());
    }
    else
    {
        Serial.println("\n✗ WiFi connection failed");
    }
}

void checkWiFiConnection()
{
    if (millis() - lastWifiCheck < Config::WIFI_RECONNECT_INTERVAL)
        return;
    lastWifiCheck = millis();

    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("⚠ WiFi disconnected. Reconnecting...");
        WiFi.reconnect();
    }
}

void reconnectMQTT()
{
    if (millis() - lastMqttAttempt < Config::MQTT_RECONNECT_INTERVAL)
        return;
    lastMqttAttempt = millis();

    if (WiFi.status() != WL_CONNECTED)
        return;

    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32-Robot-" + String(random(0xffff), HEX);

    if (mqttClient.connect(clientId.c_str(), Config::MQTT_USER, Config::MQTT_PASSWORD))
    {
        Serial.println("✓ MQTT connected!");

        mqttClient.subscribe(Config::TOPIC_TARGET);

        Serial.println("✓ Subscribed to target topic"); 
    }
    else
    {
        Serial.printf("✗ failed, rc=%d\n", mqttClient.state());
    }
}

// =================================================================
// MQTT CALLBACK
// =================================================================
void mqttCallback(char *topic, byte *payload, unsigned int length)
{
    if (strcmp(topic, Config::TOPIC_TARGET) != 0)
        return;
    JsonDocument doc;
    if (deserializeJson(doc, payload, length).code() != DeserializationError::Ok)
        return;
    bool targetChanged = false;
    bool autoModeChanged = false;
    if (doc["auto_mode"].is<bool>())
    {
        bool newAutoMode = doc["auto_mode"];
        if (newAutoMode != autoMode)
        {
            autoMode = newAutoMode;
            autoModeChanged = true;
            logToSerialAndMqtt("[Command] Auto mode: %s", autoMode ? "ON" : "OFF");
            if (!autoMode)
            {
                currentState = IDLE;
                navSubState = SUB_IDLE;
                timedAction.stop();
                stopAll();
                recoveryAttempts = 0;
                totalTargetsInQueue = 0;
                currentTargetIndex = -1;
                logToSerialAndMqtt("[Command] Auto mode OFF - Robot stopped");
                return;
            }
        }
    }
    if (doc.containsKey("targets") && doc["targets"].is<JsonArray>())
    {
        JsonArray newTargets = doc["targets"].as<JsonArray>();
        int newTargetCount = newTargets.size();
        if (newTargetCount == 0)
        {
            currentState = IDLE;
            navSubState = SUB_IDLE;
            stopAll();
            totalTargetsInQueue = 0;
            currentTargetIndex = -1;
        }
        else if (newTargetCount <= MAX_ROUTE_TARGETS)
        {
            logToSerialAndMqtt("[Route] *** NEW ROUTE RECEIVED *** (%d targets)", newTargetCount);
            if (autoMode)
            {
                if (timedAction.active)
                    timedAction.stop();
                recoveryAttempts = 0;
            }
            totalTargetsInQueue = 0;
            for (JsonObject targetJson : newTargets)
            {
                if (targetJson.containsKey("x") && targetJson.containsKey("y"))
                {
                    targetQueue[totalTargetsInQueue].update(targetJson["x"], targetJson["y"]);
                    totalTargetsInQueue++;
                }
            }
            if (totalTargetsInQueue > 0)
            {
                currentTargetIndex = 0;
                targetPos.update(targetQueue[0].x, targetQueue[0].y);
                targetChanged = true;
            }
        }
    }
    bool isRouteActive = (totalTargetsInQueue > 0 && currentTargetIndex >= 0);
    if (autoMode && (targetChanged || autoModeChanged) && currentPos.isValid() && isRouteActive)
    {
        currentState = NAVIGATING_TO_TARGET;
        navSubState = SUB_MOVING;
        lastProgressTime = millis();
        lastDistanceToTarget = 9999.0f;
        logToSerialAndMqtt("[Route] ====== STARTING NAVIGATION TO TARGET %d ======", currentTargetIndex);
    }
}

// =================================================================
// ROBOT STATUS PUBLISHING
// =================================================================
void publishRobotStatus()
{
    if (!mqttClient.connected())
    {
        return;
    }

    static unsigned long lastPublishTime = 0;
    const unsigned long PUBLISH_INTERVAL = 1000;

    if (millis() - lastPublishTime < PUBLISH_INTERVAL)
    {
        return;
    }
    lastPublishTime = millis();

    float heading = currentHeadingState.angle;
    float rawHeading = currentHeadingState.rawAngle;
    const char *state = getStateName(currentState);
    float distance = -1.0f;

    bool isRouteActive = (totalTargetsInQueue > 0 && currentTargetIndex >= 0);
    if (autoMode && isRouteActive)
    {
        float dx = targetPos.x - currentPos.x;
        float dy = (targetPos.y - currentPos.y);
        distance = sqrtf(dx * dx + dy * dy);
    }

    JsonDocument doc;
    doc["heading"] = heading;
    doc["heading_raw"] = rawHeading;
    doc["heading_confidence"] = currentHeadingState.totalConfidence;
    doc["heading_anchor_count"] = currentHeadingState.validAnchorCount;
    doc["state"] = state;
    doc["distance_to_target_cm"] = distance;
    doc["route_active"] = isRouteActive;
    doc["current_target_index"] = currentTargetIndex;
    doc["total_targets"] = totalTargetsInQueue;
    
    doc["anchor1_valid"] = anchors[0].isValid();
    doc["anchor2_valid"] = anchors[1].isValid();
    doc["anchor3_valid"] = anchors[2].isValid();
    doc["tag5_valid"] = tag5Data.isValid();
    doc["tag6_valid"] = tag6Data.isValid();


    char buffer[384];
    size_t n = serializeJson(doc, buffer);

    const char *STATUS_TOPIC = "robot/status";
    mqttClient.publish(STATUS_TOPIC, buffer, n);
}

// =================================================================
// MANUAL CONTROL
// =================================================================
void controlManual()
{
    const uint8_t JOY_CENTER = 7, JOY_DEADZONE = 2;

#if ROBOT_TYPE == ROBOT_TYPE_CARLIKE
    int steer = (abs(JOY_CENTER - rfData.joy2_x) > JOY_DEADZONE)
                    ? map(JOY_CENTER - rfData.joy2_x, -JOY_CENTER, JOY_CENTER, -Config::MAX_STEER_ANGLE, Config::MAX_STEER_ANGLE)
                    : 0;
    int speed = (abs(JOY_CENTER - rfData.joy1_y) > JOY_DEADZONE)
                    ? map(JOY_CENTER - rfData.joy1_y, -JOY_CENTER, JOY_CENTER, -Config::MAX_SPEED, Config::MAX_SPEED)
                    : 0;
    if (steer == 0 && speed == 0)
        stopAll();
    else
        driveCarLike(steer, speed);

#elif ROBOT_TYPE == ROBOT_TYPE_2WHEEL
    int forward = (abs(JOY_CENTER - rfData.joy1_y) > JOY_DEADZONE)
                      ? map(JOY_CENTER - rfData.joy1_y, -JOY_CENTER, JOY_CENTER, -Config::MAX_SPEED, Config::MAX_SPEED)
                      : 0;
    int turn = (abs(JOY_CENTER - rfData.joy2_x) > JOY_DEADZONE)
                   ? map(JOY_CENTER - rfData.joy2_x, -JOY_CENTER, JOY_CENTER, -Config::TURN_SPEED, Config::TURN_SPEED)
                   : 0;
    if (forward == 0 && turn == 0)
        stopAll();
    else
        driveDifferential(forward - turn, forward + turn);
#endif
}

// =================================================================
// AUTONOMOUS CONTROL - OPTIMIZED VERSION
// =================================================================

// === HELPER FUNCTIONS ===
bool isPathClear() {
    return frontLidar.isPathClear(Config::halfAngle, Config::MIN_SAFE_DISTANCE_FRONT);
}

bool isRouteActive() {
    return (totalTargetsInQueue > 0 && currentTargetIndex >= 0 && currentTargetIndex < totalTargetsInQueue);
}

struct NavigationData {
    float dx, dy, distance, targetAngle, angleError;
    
    void calculate(const Position& current, const Position& target, float currentHeading) {
        dx = target.x - current.x;
        dy = -(target.y - current.y);
        distance = sqrtf(dx * dx + dy * dy);
        targetAngle = normalizeAngleDeg(atan2f(dy, dx) * 180.0f / PI);
        angleError = normalizeAngleError(targetAngle - currentHeading);
    }
};

// === POSITION RECOVERY ===
void handlePositionLoss() {
    if (!positionWasLost) {
        logToSerialAndMqtt("[Nav] Position data lost! Pausing navigation.");
        positionWasLost = true;
        stopAll();
        currentState = IDLE;
    }
}

void handlePositionRecovery() {
    if (!isRouteActive()) return;
    
    logToSerialAndMqtt("[Nav] Position RE-ACQUIRED. Finding best next target...");
    positionWasLost = false;

    int bestTargetIndex = -1;
    float minDistance = 99999.9f;

    for (int i = currentTargetIndex; i < totalTargetsInQueue; i++) {
        float dx = targetQueue[i].x - currentPos.x;
        float dy = (targetQueue[i].y - currentPos.y);
        float dist = sqrtf(dx * dx + dy * dy);

        if (dist < minDistance) {
            minDistance = dist;
            bestTargetIndex = i;
        }
    }

    if (bestTargetIndex != -1) {
        if (bestTargetIndex != currentTargetIndex) {
            logToSerialAndMqtt("[Nav] Path jump detected! New target is index %d (was %d).", 
                             bestTargetIndex, currentTargetIndex);
            currentTargetIndex = bestTargetIndex;
        } else {
            logToSerialAndMqtt("[Nav] Confirmed current target index %d is still the closest.", 
                             currentTargetIndex);
        }
        
        targetPos.update(targetQueue[currentTargetIndex].x, targetQueue[currentTargetIndex].y);
        currentState = NAVIGATING_TO_TARGET;
        navSubState = SUB_MOVING;
        lastProgressTime = millis();
        lastDistanceToTarget = 9999.0f;
        recoveryAttempts = 0;
    }
}

// === TARGET MANAGEMENT ===
bool shouldSkipToNextTarget(const NavigationData& navData) {
    if (currentTargetIndex >= totalTargetsInQueue - 1) return false;
    
    Position nextTargetPos = targetQueue[currentTargetIndex + 1];
    float dx_next = nextTargetPos.x - currentPos.x;
    float dy_next = (nextTargetPos.y - currentPos.y);
    float distanceToNext = sqrtf(dx_next * dx_next + dy_next * dy_next);

    if (distanceToNext < navData.distance) {
        logToSerialAndMqtt("[Nav] Closer to next target (%.1f cm). Skipping ahead!", distanceToNext);
        currentTargetIndex++;
        targetPos.update(nextTargetPos.x, nextTargetPos.y);
        return true;
    }
    return false;
}

void advanceToNextTarget() {
    logToSerialAndMqtt("[Route] ✓ Reached Target %d! (%.1f, %.1f)", 
                     currentTargetIndex, targetPos.x, targetPos.y);
    currentTargetIndex++;

    if (currentTargetIndex < totalTargetsInQueue) {
        logToSerialAndMqtt("[Route] --> Now navigating to Target %d", currentTargetIndex);
        targetPos.update(targetQueue[currentTargetIndex].x, targetQueue[currentTargetIndex].y);
        navSubState = SUB_MOVING;
        lastProgressTime = millis();
        lastDistanceToTarget = 9999.0f;
        recoveryAttempts = 0;
    } else {
        logToSerialAndMqtt("[Route] *** ROUTE COMPLETE *** All targets reached.");
        currentState = TARGET_REACHED;
        navSubState = SUB_IDLE;
        stopAll();
    }
}

// === STUCK DETECTION ===
bool checkIfStuck(float currentDistance) {
    if (millis() - lastProgressTime > Config::STUCK_TIMEOUT) {
        if (abs(currentDistance - lastDistanceToTarget) < Config::PROGRESS_THRESHOLD) {
            logToSerialAndMqtt("[Nav] ⚠ Robot stuck, entering recovery.");
            currentState = RECOVERY_STUCK;
            return true;
        }
        lastProgressTime = millis();
        lastDistanceToTarget = currentDistance;
    }
    return false;
}

// === MOVEMENT CONTROL ===
void executeMovement(float angleError) {
    if (abs(angleError) < Config::ANGLE_TOLERANCE) {
        driveDifferential(Config::MOVE_SPEED, Config::MOVE_SPEED);
        return;
    }
    
    logToSerialAndMqtt(" -> Angle drifted (Err: %.1f). Re-orienting.", angleError);
    float dynamicTurnSpeed_f = abs(angleError) * Config::KP_TURN_2WHEEL;
    int dynamicTurnSpeed = constrain((int)dynamicTurnSpeed_f, Config::MIN_TURN_SPEED, Config::TURN_SPEED);
    
    if (angleError > 0) {
        driveDifferential(-dynamicTurnSpeed, dynamicTurnSpeed);
    } else {
        driveDifferential(dynamicTurnSpeed, -dynamicTurnSpeed);
    }
}

void handleObstacleScan(unsigned long elapsed, float targetAngle, float& chosenGapAngle, 
                       ObstacleAvoidancePhase& phase, unsigned long& startTime) {
    driveDifferential(0, 0);
    
    if (elapsed > 200) {
        const float MIN_GAP_WIDTH = 300.0f;
        const float ANGLE_PENALTY = 2.0f;
        
        LidarModule::GapInfo bestGap = frontLidar.findBestGap(
            targetAngle, -70, 70, MIN_GAP_WIDTH, ANGLE_PENALTY
        );
        
        if (bestGap.isValid) {
            chosenGapAngle = bestGap.angle_deg;
            phase = AVOID_MOVING;
            startTime = millis();
            logToSerialAndMqtt("[Obstacle] Gap at %.1f° (width: %.0fmm)", 
                             bestGap.angle_deg, bestGap.width_mm);
        } else {
            logToSerialAndMqtt("[Obstacle] No gap, switching to recovery");
            currentState = RECOVERY_STUCK;
            startTime = 0;
            phase = AVOID_SCANNING;
        }
    }
}

void handleObstacleMove(unsigned long elapsed, float gapAngle, 
                       ObstacleAvoidancePhase& phase, unsigned long& startTime) {
    float angleError = normalizeAngleError(gapAngle - currentHeadingState.angle);
    
    // Phase 1: Turning to gap
    if (abs(angleError) > 25.0f) {
        int turnSpeed = (int)(abs(angleError) * Config::KP_TURN_2WHEEL);
        turnSpeed = constrain(turnSpeed, Config::AVOID_TURN_SPEED, Config::AVOID_TURN_SPEED);
        
        if (angleError > 0) {
            driveDifferential(-turnSpeed, turnSpeed);
        } else {
            driveDifferential(turnSpeed, -turnSpeed);
        }
        
        if (elapsed > 4000) {
            logToSerialAndMqtt("[Obstacle] Turn timeout, recovery");
            currentState = RECOVERY_STUCK;
            startTime = 0;
            phase = AVOID_SCANNING;
        }
        return;
    }
    
    // Phase 2: Moving through gap
    logToSerialAndMqtt("[Obstacle] Aligned to gap, moving through!");
    driveDifferential(Config::MOVE_SPEED, Config::MOVE_SPEED);
    
    const unsigned long MIN_MOVE_TIME = 1500;
    
    if (elapsed > MIN_MOVE_TIME) {
        if (isPathClear()) {
            driveDifferential(0, 0);
            delay(100);
            
            logToSerialAndMqtt("[Obstacle] Cleared, resuming navigation");
            currentState = NAVIGATING_TO_TARGET;
            navSubState = SUB_MOVING;
            startTime = 0;
            phase = AVOID_SCANNING;
            recoveryAttempts = 0;
            lastProgressTime = millis();
        } else if (elapsed > 5000) {
            logToSerialAndMqtt("[Obstacle] Movement timeout, recovery");
            currentState = RECOVERY_STUCK;
            startTime = 0;
            phase = AVOID_SCANNING;
        }
    }
}

// === OBSTACLE AVOIDANCE ===
void handleObstacleAvoidance() {
    static ObstacleAvoidancePhase avoidPhase = AVOID_SCANNING;
    static unsigned long avoidStartTime = 0;
    static float chosenGapAngle = 0.0f;
    static float originalTargetAngle = 0.0f;
    
    // Initialization
    if (avoidStartTime == 0) {
        avoidStartTime = millis();
        avoidPhase = AVOID_SCANNING;
        driveDifferential(0, 0);
        
        float dx = targetPos.x - currentPos.x;
        float dy = -(targetPos.y - currentPos.y);
        originalTargetAngle = normalizeAngleDeg(atan2f(dy, dx) * 180.0f / PI);
        
        logToSerialAndMqtt("[Obstacle] Starting avoidance (target: %.1f°)", originalTargetAngle);
    }
    
    unsigned long elapsed = millis() - avoidStartTime;
    
    switch (avoidPhase) {
        case AVOID_SCANNING:
            handleObstacleScan(elapsed, originalTargetAngle, chosenGapAngle, avoidPhase, avoidStartTime);
            break;
            
        case AVOID_MOVING:
            handleObstacleMove(elapsed, chosenGapAngle, avoidPhase, avoidStartTime);
            break;
    }
}

// === RECOVERY ===
void handleRecovery() {
    logToSerialAndMqtt("[Recovery] Attempt %d/%d", recoveryAttempts + 1, Config::MAX_RECOVERY_ATTEMPTS);
    
    if (++recoveryAttempts >= Config::MAX_RECOVERY_ATTEMPTS) {
        logToSerialAndMqtt("[Recovery] Max attempts reached. Stopping.");
        currentState = IDLE;
        autoMode = false;
        totalTargetsInQueue = 0;
        currentTargetIndex = -1;
        return;
    }
    
    driveDifferential(-Config::MOVE_SPEED, -Config::MOVE_SPEED);
    delay(Config::RECOVERY_BACKUP_DURATION);
    timedAction.start(Config::RECOVERY_TURN_DURATION);
}

// === MAIN CONTROL LOOP ===
void controlAuto() {
    // Position validation
    if (!currentPos.isValid()) {
        handlePositionLoss();
        return;
    }
    
    // Position recovery
    if (positionWasLost && isRouteActive()) {
        handlePositionRecovery();
    }
    
    // Route validation
    if (!isRouteActive()) {
        if (currentState != IDLE && currentState != TARGET_REACHED) {
            logToSerialAndMqtt("[Nav] No active route. Entering IDLE.");
            currentState = IDLE;
            stopAll();
        }
        return;
    }
    
    // Timed action handling
    if (timedAction.active) {
        if (timedAction.isComplete()) {
            timedAction.stop();
            stopAll();
            currentState = NAVIGATING_TO_TARGET;
            navSubState = SUB_MOVING;
            lastProgressTime = millis();
        }
        return;
    }
    
    // Calculate navigation data
    NavigationData navData;
    navData.calculate(currentPos, targetPos, currentHeadingState.angle);
    
    // Check for target skip opportunity
    if (shouldSkipToNextTarget(navData)) {
        navData.calculate(currentPos, targetPos, currentHeadingState.angle);
    }
    
    // State machine
    switch (currentState) {
        case IDLE:
            stopAll();
            break;
            
        case NAVIGATING_TO_TARGET:
            // Check if target reached
            if (navData.distance < Config::DISTANCE_TOLERANCE) {
                stopAll(); 
                advanceToNextTarget();
                break;
            }
            
            // Check if stuck
            if (checkIfStuck(navData.distance)) break;
            
            // Check for obstacles
            if (navSubState == SUB_MOVING && !isPathClear()) {
                logToSerialAndMqtt("[Nav] ⚠ Obstacle detected, entering recovery.");
                currentState = OBSTACLE_AVOIDANCE;
                break;
            }
            
            // Execute movement
            if (navSubState == SUB_MOVING) {
                executeMovement(navData.angleError);
            }
            break;
            
        case OBSTACLE_AVOIDANCE:
            handleObstacleAvoidance();
            break;
            
        case RECOVERY_STUCK:
            handleRecovery();
            break;
            
        case TARGET_REACHED:
            driveDifferential(0, 0);
            navSubState = SUB_IDLE;
            break;
    }
}

// =================================================================
// SETUP
// =================================================================
void setup()
{
    Serial.begin(115200);
    delay(1000);
    UWB_SERIAL_TAG5.begin(115200, SERIAL_8N1, UWB_RX_PIN_TAG5, UWB_TX_PIN_TAG5);
    UWB_SERIAL_TAG6.begin(115200, SERIAL_8N1, UWB_RX_PIN_TAG6, UWB_TX_PIN_TAG6); 
   
    NUVOTON_SERIAL.begin(115200);
    //mySwitch.enableReceive(RF_RECEIVER_PIN);
    frontLidar.begin();
    //Serial.println("✓ LIDAR initialized");

    setupWiFi();
    mqttClient.setServer(Config::MQTT_SERVER, Config::MQTT_PORT);
    mqttClient.setCallback(mqttCallback);
    mqttClient.setBufferSize(512); 

    stopAll();
}

// =================================================================
// MAIN LOOP
// =================================================================
void loop()
{
    handleUWBInput();
    checkWiFiConnection();
    if (!mqttClient.connected())
        reconnectMQTT();
    else
        mqttClient.loop();

    handleRFInput();
    frontLidar.loop();
    publishRobotStatus();
    publishPosition();

    unsigned long now = millis();
    bool rfActive = rfData.valid && (now - rfData.lastReceived <= Config::RF_TIMEOUT);

    if (rfActive)
    {
        if (autoMode)
        {
            autoMode = false;
            currentState = IDLE;
            stopAll();
            totalTargetsInQueue = 0;
            currentTargetIndex = -1;
            logToSerialAndMqtt("[Control] RF input detected. Auto mode OFF.");
        }
        controlManual();
    }
    else if (autoMode)
    {
        controlAuto();
    }
    else
    {
        if (currentState != IDLE)
        {
            currentState = IDLE;
            stopAll();
        }
    }
    delay(10);
}