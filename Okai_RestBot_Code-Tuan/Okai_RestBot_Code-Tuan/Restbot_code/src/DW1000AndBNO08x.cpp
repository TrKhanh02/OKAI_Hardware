// #include <Arduino.h>
// #include <Print.h>
// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <PubSubClient.h>
// #include <ArduinoJson.h>
// #include <Wire.h>
// #include <RCSwitch.h>
// #include "SparkFun_BNO08x_Arduino_Library.h"
// #include "LIDAR_MODULE.h"
// #include <stdarg.h>

// // =================================================================
// // ROBOT TYPE CONFIGURATION
// // =================================================================
// #define ROBOT_TYPE_CARLIKE 1
// #define ROBOT_TYPE_2WHEEL 2

// // #define ROBOT_TYPE ROBOT_TYPE_CARLIKE
// #define ROBOT_TYPE ROBOT_TYPE_2WHEEL

// #if !defined(ROBOT_TYPE)
// #error "select type of robot by defining ROBOT_TYPE"
// #endif

// // =================================================================
// // CONFIGURATION
// // =================================================================
// namespace Config
// {
//     // Network
//     const char *WIFI_SSID = "OKAI2";
//     const char *WIFI_PASSWORD = "prv@101024";
//     const char *MQTT_SERVER = "103.216.117.71";
//     const int MQTT_PORT = 8883;
//     const char *MQTT_USER = "robot";
//     const char *MQTT_PASSWORD = "robot";

//     // MQTT Topics
//     const char *TOPIC_TARGET = "device/command";        // Subscribe: target + auto_mode
//     const char *TOPIC_POSITION_PUB = "device/position"; // Publish: calculated position

//     // Timeouts
//     const unsigned long WIFI_RECONNECT_INTERVAL = 30000;
//     const unsigned long MQTT_RECONNECT_INTERVAL = 5000;
//     const unsigned long RF_TIMEOUT = 1000;
//     const unsigned long STUCK_TIMEOUT = 5000;
//     const unsigned long ANCHOR_TIMEOUT = 2000; // ADDED: Timeout cho dữ liệu anchor
//     const unsigned long POSITION_PUBLISH_INTERVAL = 200; // ADDED: Publish position mỗi 200ms

//     // Navigation
//     const float DISTANCE_TOLERANCE = 50.0f;
//     const float ANGLE_TOLERANCE = 14.0f;
//     const float PROGRESS_THRESHOLD = 5.0f;
//     const float MIN_SAFE_DISTANCE_FRONT = 50.0f;
//     const float halfAngle = 45.0f;

//     // Motor Control
//     const int MAX_SPEED = 80;
//     const int MOVE_SPEED = 25;
//     const int TURN_SPEED = 15;
//     const int AVOID_TURN_SPEED = 10;
//     const int MAX_STEER_ANGLE = 45;
//     const float KP_STEER = 1.8f;
//     const int MIN_TURN_SPEED = 7;
//     const float KP_TURN_2WHEEL = 0.3f;
//     const unsigned long MOTOR_COMMAND_INTERVAL = 50;
//     const float ROBOT_SPEED_CM_S = 15.0;

//     // Recovery
//     const unsigned long RECOVERY_BACKUP_DURATION = 500;
//     const unsigned long RECOVERY_TURN_DURATION = 500;
//     const int MAX_RECOVERY_ATTEMPTS = 5;
// }

// // =================================================================
// // GLOBAL OBJECTS
// // =================================================================
// BNO08x myIMU;
// RCSwitch mySwitch = RCSwitch();
// LidarModule frontLidar(33, -1);
// WiFiClient wifiClient;
// PubSubClient mqttClient(wifiClient);

// #define RF_RECEIVER_PIN 36
// #define NUVOTON_SERIAL Serial2
// #define NUVOTON_TX 19
// #define NUVOTON_RX 39

// #define UWB_SERIAL Serial   
// #define UWB_RX_PIN 4
// #define UWB_TX_PIN -1
// // =================================================================
// // DATA STRUCTURES
// // =================================================================
// enum RobotState
// {
//     IDLE,
//     NAVIGATING_TO_TARGET,
//     OBSTACLE_AVOIDANCE,
//     RECOVERY_STUCK,
//     TARGET_REACHED
// };
// enum ObstacleAvoidancePhase {
//     AVOID_SCANNING,
//     AVOID_TURNING,
//     AVOID_MOVING,
//     AVOID_REALIGN 
// };

// enum NavigationSubState
// {
//     SUB_IDLE,
//     SUB_TURNING,
//     SUB_MOVING
// };

// struct Position
// {
//     float x = 0.0f;
//     float y = 0.0f;
//     unsigned long lastUpdate = 0;

//     bool isValid() const
//     {
//         return (millis() - lastUpdate) < Config::ANCHOR_TIMEOUT * 2;
//     }

//     void update(float newX, float newY)
//     {
//         x = newX;
//         y = newY;
//         lastUpdate = millis();
//     }
// };

// struct RFData
// {
//     uint8_t joy1_x = 0, joy1_y = 0, joy2_x = 0, joy2_y = 0;
//     bool valid = false;
//     unsigned long lastReceived = 0;
// };

// struct TimedAction
// {
//     unsigned long startTime = 0;
//     unsigned long duration = 0;
//     bool active = false;

//     void start(unsigned long durationMs)
//     {
//         startTime = millis();
//         duration = durationMs;
//         active = true;
//     }

//     bool isComplete() const
//     {
//         return active && (millis() - startTime >= duration);
//     }

//     void stop()
//     {
//         active = false;
//     }
// };

// // ADDED: Anchor structure for UWB trilateration
// struct Anchor
// {
//     float x, y, z;
//     float distance;
//     unsigned long lastUpdate;

//     Anchor(float _x, float _y, float _z) : x(_x), y(_y), z(_z), distance(-1.0f), lastUpdate(0) {}

//     bool isValid() const
//     {
//         return (distance > 0 && (millis() - lastUpdate) < Config::ANCHOR_TIMEOUT);
//     }
// };

// // =================================================================
// // GLOBAL STATE
// // =================================================================
// volatile float currentHeading = 0.0f; // Raw heading từ IMU
// float imu_heading_offset = 0.0f;      // Offset để căn chỉnh hướng ban đầu
// Position currentPos, targetPos;       // targetPos giờ là MỤC TIÊU HIỆN TẠI trong lộ trình
// RFData rfData;
// RobotState currentState = IDLE;
// NavigationSubState navSubState = SUB_IDLE;
// bool autoMode = false;
// unsigned long lastMotorCommandTime = 0;
// unsigned long lastActionStopTime = 0;
// unsigned long lastPositionPublish = 0; // ADDED: Tracking cho publish position
// bool positionWasLost = true;

// // ===== MODIFIED FOR ROUTE =====
// #define MAX_ROUTE_TARGETS 10 // Cho phép lưu tối đa 10 điểm trong lộ trình
// Position targetQueue[MAX_ROUTE_TARGETS];
// int currentTargetIndex = -1; // Index của target hiện tại trong lộ trình
// int totalTargetsInQueue = 0; // Tổng số target trong lộ trình
// // ==============================

// // UWB Anchors - vị trí đã biết
// Anchor anchors[3] = {
//     Anchor(0.0f, 5.0f, 0.75f), // A1: x=0m, y=5m, z=0.75m
//     Anchor(5.0f, 0.0f, 0.75f), // A2: x=5m, y=0m, z=0.75m
//     Anchor(5.0f, 5.0f, 0.75f)  // A3: x=5m, y=5m, z=0.75m
// };
// const float TAG_HEIGHT = 0.20f; // 20cm

// // Anti-stuck tracking
// unsigned long lastProgressTime = 0;
// float lastDistanceToTarget = 9999.0f;
// int recoveryAttempts = 0;

// TimedAction timedAction;

// // Network tracking
// unsigned long lastWifiCheck = 0;
// unsigned long lastMqttAttempt = 0;

// // Command caching
// struct
// {
//     int angelA = -999, dutyAngelA = -999;
//     int angelB = -999, dutyAngelB = -999;
//     int m1_dir = -1, m1_duty = -1;
//     int m2_dir = -1, m2_duty = -1;
// } lastCommand;

// // =================================================================
// // UTILITY FUNCTIONS
// // =================================================================
// static inline float normalizeAngleDeg(float ang)
// {
//     while (ang >= 360.0f)
//         ang -= 360.0f;
//     while (ang < 0.0f)
//         ang += 360.0f;
//     return ang;
// }

// static inline float normalizeAngleError(float ang)
// {
//     while (ang > 180.0f)
//         ang -= 360.0f;
//     while (ang < -180.0f)
//         ang += 360.0f;
//     return ang;
// }

// const char *getStateName(RobotState state)
// {
//     static const char *names[] = {
//         "IDLE", "NAVIGATING", "OBSTACLE_AVOID", "RECOVERY", "TARGET_REACHED"};
//     return names[state];
// }

// void logToSerialAndMqtt(const char *format, ...)
// {
//     char buf[256];
//     va_list args;
//     va_start(args, format);
//     vsnprintf(buf, sizeof(buf), format, args);
//     va_end(args);

//     Serial.println(buf);

//     if (mqttClient.connected())
//     {
//         const char *DEBUG_TOPIC = "robot/debug_log";
//         mqttClient.publish(DEBUG_TOPIC, buf);
//     }
// }

// // =================================================================
// // UWB TRILATERATION
// // =================================================================


// bool allAnchorsReady()
// {
//     return anchors[0].isValid() && anchors[1].isValid() && anchors[2].isValid();
// }

// bool computeTrilateration(float &x, float &y)
// {
//     if (!allAnchorsReady())
//     {
//         return false;
//     }

//     float x1 = anchors[0].x, y1 = anchors[0].y, z1 = anchors[0].z;
//     float x2 = anchors[1].x, y2 = anchors[1].y, z2 = anchors[1].z;
//     float x3 = anchors[2].x, y3 = anchors[2].y, z3 = anchors[2].z;

//     // Tính khoảng cách thực tế trên mặt phẳng (loại bỏ thành phần z)
//     float dz1 = z1 - TAG_HEIGHT;
//     float dz2 = z2 - TAG_HEIGHT;
//     float dz3 = z3 - TAG_HEIGHT;

//     float d1_sq = anchors[0].distance * anchors[0].distance;
//     float d2_sq = anchors[1].distance * anchors[1].distance;
//     float d3_sq = anchors[2].distance * anchors[2].distance;

//     float r1_sq = d1_sq - dz1 * dz1;
//     float r2_sq = d2_sq - dz2 * dz2;
//     float r3_sq = d3_sq - dz3 * dz3;

//     if (r1_sq < 0 || r2_sq < 0 || r3_sq < 0)
//     {
//         logToSerialAndMqtt("[UWB] Error: Invalid distance calculation");
//         return false;
//     }

//     // Phương trình trilateration
//     float A = 2 * (x2 - x1);
//     float B = 2 * (y2 - y1);
//     float C = r1_sq - r2_sq - x1 * x1 + x2 * x2 - y1 * y1 + y2 * y2;

//     float D = 2 * (x3 - x1);
//     float E = 2 * (y3 - y1);
//     float F = r1_sq - r3_sq - x1 * x1 + x3 * x3 - y1 * y1 + y3 * y3;

//     float denom = (A * E - B * D);
//     if (fabs(denom) < 1e-6)
//     {
//         logToSerialAndMqtt("[UWB] Error: Singular matrix (anchors collinear?)");
//         return false;
//     }

//     x = (C * E - B * F) / denom;
//     y = (A * F - C * D) / denom;

//     return true;
// }

// void updateRobotPosition()
// {
//     float x, y;
//     if (computeTrilateration(x, y))
//     {
//         currentPos.update(x * 100.0f, y * 100.0f);
//     }
//     else
//     {
//         logToSerialAndMqtt("[UWB] Failed to compute position");
//     }
// }
// void handleUWBInput()
// {
//     if (UWB_SERIAL.available())
//     {
//         String data = UWB_SERIAL.readStringUntil('\n');
//         JsonDocument doc;
//         if (deserializeJson(doc, data).code() == DeserializationError::Ok)
//         {
//             if (doc.containsKey("d1") && doc.containsKey("d2") && doc.containsKey("d3"))
//             {
//                 anchors[0].distance = doc["d1"];
//                 anchors[0].lastUpdate = millis();   
//                 anchors[1].distance = doc["d2"];
//                 anchors[1].lastUpdate = millis();
//                 anchors[2].distance = doc["d3"];
//                 anchors[2].lastUpdate = millis();
//                 updateRobotPosition();
//             }
//         }
//     }
// }
// void publishPosition()
// {
//     if (!mqttClient.connected() || !currentPos.isValid())
//     {
//         return;
//     }

//     unsigned long now = millis();
//     if (now - lastPositionPublish < Config::POSITION_PUBLISH_INTERVAL)
//     {
//         return;
//     }
//     lastPositionPublish = now;

//     JsonDocument doc;
//     doc["x"] = currentPos.x;
//     doc["y"] = currentPos.y;
//     doc["timestamp"] = now;

//     char buffer[128];
//     size_t n = serializeJson(doc, buffer);

//     mqttClient.publish(Config::TOPIC_POSITION_PUB, buffer, n);
// }

// // =================================================================
// // MOTOR CONTROL
// // =================================================================
// void sendCarLikeCommand(int angelA, int dutyAngelA, int angelB, int dutyAngelB, int dirMotorA, int dutyMotorA, int dirMotorB, int dutyMotorB)
// {
//     bool isSameCommand = (angelA == lastCommand.angelA && dutyAngelA == lastCommand.dutyAngelA &&
//                           angelB == lastCommand.angelB && dutyAngelB == lastCommand.dutyAngelB &&
//                           dirMotorA == lastCommand.m1_dir && dutyMotorA == lastCommand.m1_duty &&
//                           dirMotorB == lastCommand.m2_dir && dutyMotorB == lastCommand.m2_duty);

//     if (isSameCommand)
//         return;

//     char buf[128];
//     snprintf(buf, sizeof(buf), "%d,%d,%d,%d,%d,%d,%d,%d|\n",
//              angelA, dutyAngelA, angelB, dutyAngelB,
//              dirMotorA, dutyMotorA, dirMotorB, dutyMotorB);
//     NUVOTON_SERIAL.print(buf);

//     lastCommand.angelA = angelA;
//     lastCommand.dutyAngelA = dutyAngelA;
//     lastCommand.angelB = angelB;
//     lastCommand.dutyAngelB = dutyAngelB;
//     lastCommand.m1_dir = dirMotorA;
//     lastCommand.m1_duty = dutyMotorA;
//     lastCommand.m2_dir = dirMotorB;
//     lastCommand.m2_duty = dutyMotorB;
// }

// void stopAll()
// {
//     sendCarLikeCommand(0, 0, 0, 0, 0, 0, 0, 0);
// }

// void driveCarLike(int angle, int speed)
// {
//     int dir = (speed >= 0) ? 1 : 0;
//     int motorDuty = abs(speed);
//     sendCarLikeCommand(angle, 50, angle, 50, dir, motorDuty, dir, motorDuty);
// }

// void driveDifferential(int leftSpeed, int rightSpeed)
// {
//     leftSpeed = constrain(leftSpeed, -Config::MAX_SPEED, Config::MAX_SPEED);
//     rightSpeed = constrain(rightSpeed, -Config::MAX_SPEED, Config::MAX_SPEED);

//     int leftDir = (leftSpeed >= 0) ? 1 : 0;
//     int leftDuty = abs(leftSpeed);

//     int rightDir = (rightSpeed >= 0) ? 1 : 0;
//     int rightDuty = abs(rightSpeed);

//     sendCarLikeCommand(0, 0, 0, 0, leftDir, leftDuty, rightDir, rightDuty);
// }

// // =================================================================
// // SENSOR HANDLERS
// // =================================================================
// void updateIMU()
// {
//     if (myIMU.getSensorEvent() &&
//         myIMU.getSensorEventID() == SENSOR_REPORTID_ROTATION_VECTOR)
//     {
//         // Lấy giá trị raw yaw và áp dụng offset
//         float raw_yaw = -(myIMU.getYaw()) * 180.0 / PI;
//         currentHeading = normalizeAngleDeg(raw_yaw + imu_heading_offset);
//     }
// }

// void calibrateIMUHeading(float true_heading)
// {
//     Serial.println("Calibrating IMU... Please wait.");
//     float sum_raw_yaw = 0;
//     int samples = 100;
//     for (int i = 0; i < samples; i++)
//     {
//         if (myIMU.getSensorEvent() && myIMU.getSensorEventID() == SENSOR_REPORTID_ROTATION_VECTOR)
//         {
//             sum_raw_yaw += (-(myIMU.getYaw()) * 180.0 / PI);
//         }
//         delay(10);
//     }
//     float avg_raw_yaw = sum_raw_yaw / samples;
//     imu_heading_offset = true_heading - avg_raw_yaw;
//     imu_heading_offset = normalizeAngleDeg(imu_heading_offset);

//     Serial.printf("Calibration complete. Raw Yaw: %.2f, True Heading: %.2f, Offset: %.2f\n",
//                   avg_raw_yaw, true_heading, imu_heading_offset);
// }

// void handleRFInput()
// {
//     if (!mySwitch.available())
//         return;

//     uint32_t val = mySwitch.getReceivedValue();
//     mySwitch.resetAvailable();

//     static uint32_t lastDataValue = 0;
//     if (val == 0 || val == lastDataValue)
//         return;
//     lastDataValue = val;

//     rfData.joy1_x = (val >> 16) & 0x0F;
//     rfData.joy1_y = (val >> 12) & 0x0F;
//     rfData.joy2_x = (val >> 6) & 0x0F;
//     rfData.joy2_y = (val >> 2) & 0x0F;
//     rfData.valid = true;
//     rfData.lastReceived = millis();
// }

// // =================================================================
// // NETWORK MANAGEMENT
// // =================================================================
// void setupWiFi()
// {
//     WiFi.mode(WIFI_STA);
//     WiFi.setAutoReconnect(true);
//     WiFi.begin(Config::WIFI_SSID, Config::WIFI_PASSWORD);

//     Serial.print("Connecting to WiFi");
//     int attempts = 0;
//     while (WiFi.status() != WL_CONNECTED && attempts < 20)
//     {
//         delay(500);
//         Serial.print(".");
//         attempts++;
//     }

//     if (WiFi.status() == WL_CONNECTED)
//     {
//         Serial.println("\n✓ WiFi connected! IP: " + WiFi.localIP().toString());
//     }
//     else
//     {
//         Serial.println("\n✗ WiFi connection failed");
//     }
// }

// void checkWiFiConnection()
// {
//     if (millis() - lastWifiCheck < Config::WIFI_RECONNECT_INTERVAL)
//         return;
//     lastWifiCheck = millis();

//     if (WiFi.status() != WL_CONNECTED)
//     {
//         Serial.println("⚠ WiFi disconnected. Reconnecting...");
//         WiFi.reconnect();
//     }
// }

// void reconnectMQTT()
// {
//     if (millis() - lastMqttAttempt < Config::MQTT_RECONNECT_INTERVAL)
//         return;
//     lastMqttAttempt = millis();

//     if (WiFi.status() != WL_CONNECTED)
//         return;

//     Serial.print("Attempting MQTT connection...");
//     String clientId = "ESP32-Robot-" + String(random(0xffff), HEX);

//     if (mqttClient.connect(clientId.c_str(), Config::MQTT_USER, Config::MQTT_PASSWORD))
//     {
//         Serial.println("✓ MQTT connected!");

//         mqttClient.subscribe(Config::TOPIC_TARGET);

//         Serial.println("✓ Subscribed to target topic"); // Cập nhật lại log
//     }
//     else
//     {
//         Serial.printf("✗ failed, rc=%d\n", mqttClient.state());
//     }
// }

// // =================================================================
// // MQTT CALLBACK
// // =================================================================
// void mqttCallback(char *topic, byte *payload, unsigned int length)
// {
//     if (strcmp(topic, Config::TOPIC_TARGET) != 0)
//         return;
//     JsonDocument doc;
//     if (deserializeJson(doc, payload, length).code() != DeserializationError::Ok)
//         return;
//     bool targetChanged = false;
//     bool autoModeChanged = false;
//     if (doc["auto_mode"].is<bool>())
//     {
//         bool newAutoMode = doc["auto_mode"];
//         if (newAutoMode != autoMode)
//         {
//             autoMode = newAutoMode;
//             autoModeChanged = true;
//             logToSerialAndMqtt("[Command] Auto mode: %s", autoMode ? "ON" : "OFF");
//             if (!autoMode)
//             {
//                 currentState = IDLE;
//                 navSubState = SUB_IDLE;
//                 timedAction.stop();
//                 stopAll();
//                 recoveryAttempts = 0;
//                 totalTargetsInQueue = 0;
//                 currentTargetIndex = -1;
//                 logToSerialAndMqtt("[Command] Auto mode OFF - Robot stopped");
//                 return;
//             }
//         }
//     }
//     if (doc.containsKey("targets") && doc["targets"].is<JsonArray>())
//     {
//         JsonArray newTargets = doc["targets"].as<JsonArray>();
//         int newTargetCount = newTargets.size();
//         if (newTargetCount == 0)
//         {
//             currentState = IDLE;
//             navSubState = SUB_IDLE;
//             stopAll();
//             totalTargetsInQueue = 0;
//             currentTargetIndex = -1;
//         }
//         else if (newTargetCount <= MAX_ROUTE_TARGETS)
//         {
//             logToSerialAndMqtt("[Route] *** NEW ROUTE RECEIVED *** (%d targets)", newTargetCount);
//             if (autoMode)
//             {
//                 if (timedAction.active)
//                     timedAction.stop();
//                 recoveryAttempts = 0;
//             }
//             totalTargetsInQueue = 0;
//             for (JsonObject targetJson : newTargets)
//             {
//                 if (targetJson.containsKey("x") && targetJson.containsKey("y"))
//                 {
//                     targetQueue[totalTargetsInQueue].update(targetJson["x"], targetJson["y"]);
//                     totalTargetsInQueue++;
//                 }
//             }
//             if (totalTargetsInQueue > 0)
//             {
//                 currentTargetIndex = 0;
//                 targetPos.update(targetQueue[0].x, targetQueue[0].y);
//                 targetChanged = true;
//             }
//         }
//     }
//     bool isRouteActive = (totalTargetsInQueue > 0 && currentTargetIndex >= 0);
//     if (autoMode && (targetChanged || autoModeChanged) && currentPos.isValid() && isRouteActive)
//     {
//         currentState = NAVIGATING_TO_TARGET;
//         navSubState = SUB_MOVING;
//         lastProgressTime = millis();
//         lastDistanceToTarget = 9999.0f;
//         logToSerialAndMqtt("[Route] ====== STARTING NAVIGATION TO TARGET %d ======", currentTargetIndex);
//     }
// }

// // =================================================================
// // ROBOT STATUS PUBLISHING
// // =================================================================
// void publishRobotStatus()
// {
//     if (!mqttClient.connected())
//     {
//         return;
//     }

//     static unsigned long lastPublishTime = 0;
//     const unsigned long PUBLISH_INTERVAL = 1000;

//     if (millis() - lastPublishTime < PUBLISH_INTERVAL)
//     {
//         return;
//     }
//     lastPublishTime = millis();

//     float heading = currentHeading;
//     const char *state = getStateName(currentState);
//     float distance = -1.0f;

//     // ===== MODIFIED FOR ROUTE =====
//     bool isRouteActive = (totalTargetsInQueue > 0 && currentTargetIndex >= 0);
//     if (autoMode && isRouteActive)
//     {
//         float dx = targetPos.x - currentPos.x;
//         float dy = -(targetPos.y - currentPos.y);
//         distance = sqrtf(dx * dx + dy * dy);
//     }

//     JsonDocument doc;
//     doc["heading"] = heading;
//     doc["state"] = state;
//     doc["distance_to_target_cm"] = distance;
//     // ===== MODIFIED FOR ROUTE (Thêm thông tin lộ trình) =====
//     doc["route_active"] = isRouteActive;
//     doc["current_target_index"] = currentTargetIndex;
//     doc["total_targets"] = totalTargetsInQueue;
//     // ==================================
//     doc["anchor1_valid"] = anchors[0].isValid();
//     doc["anchor2_valid"] = anchors[1].isValid();
//     doc["anchor3_valid"] = anchors[2].isValid();

//     char buffer[256];
//     size_t n = serializeJson(doc, buffer);

//     const char *STATUS_TOPIC = "robot/status";
//     mqttClient.publish(STATUS_TOPIC, buffer, n);
// }

// // =================================================================
// // MANUAL CONTROL
// // =================================================================
// void controlManual()
// {
//     const uint8_t JOY_CENTER = 7, JOY_DEADZONE = 2;

// #if ROBOT_TYPE == ROBOT_TYPE_CARLIKE
//     int steer = (abs(JOY_CENTER - rfData.joy2_x) > JOY_DEADZONE)
//                     ? map(JOY_CENTER - rfData.joy2_x, -JOY_CENTER, JOY_CENTER, -Config::MAX_STEER_ANGLE, Config::MAX_STEER_ANGLE)
//                     : 0;
//     int speed = (abs(JOY_CENTER - rfData.joy1_y) > JOY_DEADZONE)
//                     ? map(JOY_CENTER - rfData.joy1_y, -JOY_CENTER, JOY_CENTER, -Config::MAX_SPEED, Config::MAX_SPEED)
//                     : 0;
//     if (steer == 0 && speed == 0)
//         stopAll();
//     else
//         driveCarLike(steer, speed);

// #elif ROBOT_TYPE == ROBOT_TYPE_2WHEEL
//     int forward = (abs(JOY_CENTER - rfData.joy1_y) > JOY_DEADZONE)
//                       ? map(JOY_CENTER - rfData.joy1_y, -JOY_CENTER, JOY_CENTER, -Config::MAX_SPEED, Config::MAX_SPEED)
//                       : 0;
//     int turn = (abs(JOY_CENTER - rfData.joy2_x) > JOY_DEADZONE)
//                    ? map(JOY_CENTER - rfData.joy2_x, -JOY_CENTER, JOY_CENTER, -Config::TURN_SPEED, Config::TURN_SPEED)
//                    : 0;
//     if (forward == 0 && turn == 0)
//         stopAll();
//     else
//         driveDifferential(forward - turn, forward + turn);
// #endif
// }

// // =================================================================
// // AUTONOMOUS CONTROL
// // =================================================================
// bool isPathClear()
// {
//     return frontLidar.isPathClear(Config::halfAngle, Config::MIN_SAFE_DISTANCE_FRONT);
// }

// void controlAuto()
// {
//     bool isRouteActive = (totalTargetsInQueue > 0 && currentTargetIndex >= 0 && currentTargetIndex < totalTargetsInQueue);

//     // --- LOGIC XỬ LÝ MẤT/CÓ TÍN HIỆU ---
//     if (!currentPos.isValid())
//     {
//         if (!positionWasLost)
//         {
//             logToSerialAndMqtt("[Nav] Position data lost! Pausing navigation.");
//             positionWasLost = true;
//             stopAll();
//             currentState = IDLE;
//         }
//         return;
//     }

//     // --- LOGIC TÁI ĐỊNH VỊ TRÊN LỘ TRÌNH ---
//     if (positionWasLost && isRouteActive)
//     {
//         logToSerialAndMqtt("[Nav] Position RE-ACQUIRED. Finding best next target...");
//         positionWasLost = false;

//         int bestTargetIndex = -1;
//         float minDistance = 99999.9f;

//         for (int i = currentTargetIndex; i < totalTargetsInQueue; i++)
//         {
//             float dx = targetQueue[i].x - currentPos.x;
//             float dy = -(targetQueue[i].y - currentPos.y);
//             float dist = sqrtf(dx * dx + dy * dy);

//             if (dist < minDistance)
//             {
//                 minDistance = dist;
//                 bestTargetIndex = i;
//             }
//         }

//         if (bestTargetIndex != -1 && bestTargetIndex != currentTargetIndex)
//         {
//             logToSerialAndMqtt("[Nav] Path jump detected! New target is index %d (was %d).", bestTargetIndex, currentTargetIndex);
//             currentTargetIndex = bestTargetIndex;
//         }
//         else if (bestTargetIndex != -1)
//         {
//             logToSerialAndMqtt("[Nav] Confirmed current target index %d is still the closest.", currentTargetIndex);
//         }

//         targetPos.update(targetQueue[currentTargetIndex].x, targetQueue[currentTargetIndex].y);
//         currentState = NAVIGATING_TO_TARGET;
//         navSubState = SUB_MOVING; // Bắt đầu lại bằng việc kiểm tra hướng
//     }

//     if (!isRouteActive)
//     {
//         if (currentState != IDLE && currentState != TARGET_REACHED)
//         {
//             logToSerialAndMqtt("[Nav] No active route. Entering IDLE.");
//             currentState = IDLE;
//             stopAll();
//         }
//         return;
//     }
//     if (timedAction.active)
//     {
//         if (timedAction.isComplete())
//         {
//             timedAction.stop();
//             stopAll();
//             currentState = NAVIGATING_TO_TARGET;
//             navSubState = SUB_MOVING; // Sau khi phục hồi, luôn kiểm tra lại hướng
//             lastProgressTime = millis();
//         }
//         return;
//     }

//     float dx = targetPos.x - currentPos.x;
//     float dy = -(targetPos.y - currentPos.y);
//     float distance = sqrtf(dx * dx + dy * dy);
//     float targetAngle = normalizeAngleDeg(atan2f(dy, dx) * 180.0f / PI);
//     float angleError = normalizeAngleError(targetAngle - currentHeading);

//     // Logic bỏ qua điểm nếu đã ở gần điểm tiếp theo (giữ nguyên)
//     if (currentTargetIndex < totalTargetsInQueue - 1)
//     {
//         Position nextTargetPos = targetQueue[currentTargetIndex + 1];
//         float dx_next = nextTargetPos.x - currentPos.x;
//         float dy_next = -(nextTargetPos.y - currentPos.y);
//         float distanceToNextTarget = sqrtf(dx_next * dx_next + dy_next * dy_next);

//         if (distanceToNextTarget < distance)
//         {
//             logToSerialAndMqtt("[Nav] Closer to next target (%.1f cm). Skipping ahead!", distanceToNextTarget);
//             currentTargetIndex++;
//             targetPos.update(nextTargetPos.x, nextTargetPos.y);
//             // Sau khi bỏ qua, tính toán lại và chuyển sang quay để định hướng lại
//             distance = distanceToNextTarget;
//             targetAngle = normalizeAngleDeg(atan2f(dy_next, dx_next) * 180.0f / PI);
//             angleError = normalizeAngleError(targetAngle - currentHeading);
//           //  navSubState = SUB_TURNING; 
//             navSubState = SUB_MOVING; 
//         }
//     }

//     switch (currentState)
//     {
//     case IDLE:
//         stopAll();
//         break;

//     case NAVIGATING_TO_TARGET:
//     {
//         // Logic xử lý khi đến target
//         if (distance < Config::DISTANCE_TOLERANCE)
//         {
//             logToSerialAndMqtt("[Route] ✓ Reached Target %d! (%.1f, %.1f)", currentTargetIndex, targetPos.x, targetPos.y);
//             currentTargetIndex++;

//             if (currentTargetIndex < totalTargetsInQueue)
//             {
//                 logToSerialAndMqtt("[Route] --> Now navigating to Target %d", currentTargetIndex);
//                 targetPos.update(targetQueue[currentTargetIndex].x, targetQueue[currentTargetIndex].y);
                
//                 // QUYẾT ĐỊNH NGAY LẬP TỨC HÀNH ĐỘNG TIẾP THEO
//                 // Tính toán lại góc cho mục tiêu mới
//                 float new_dx = targetPos.x - currentPos.x;
//                 float new_dy = -(targetPos.y - currentPos.y);
//                 float new_targetAngle = normalizeAngleDeg(atan2f(new_dy, new_dx) * 180.0f / PI);
//                 float new_angleError = normalizeAngleError(new_targetAngle - currentHeading);
//                 navSubState = SUB_MOVING;      
//                 // if (abs(new_angleError) < Config::ANGLE_TOLERANCE) {
                    
//                 // } else {
                   
//                 //     navSubState = SUB_TURNING;
//                 // }
                
//                 lastProgressTime = millis();
//                 lastDistanceToTarget = 9999.0f;
//                 recoveryAttempts = 0;
//             }
//             else
//             {
//                 logToSerialAndMqtt("[Route] *** ROUTE COMPLETE *** All targets reached.");
//                 currentState = TARGET_REACHED;
//                 navSubState = SUB_IDLE;
//                 stopAll();
//             }
//             break; // Kết thúc vòng lặp này, vòng lặp sau sẽ thực hiện hành động mới
//         }

//         // Logic chống kẹt
//         if (millis() - lastProgressTime > Config::STUCK_TIMEOUT)
//         {
//             if (abs(distance - lastDistanceToTarget) < Config::PROGRESS_THRESHOLD)
//             {
//                 logToSerialAndMqtt("[Nav] ⚠ Robot stuck, entering recovery.");
//                 currentState = RECOVERY_STUCK;
//                 break;
//             }
//             lastProgressTime = millis();
//             lastDistanceToTarget = distance;
//         }

//         // Logic tránh vật cản
//         if (navSubState == SUB_MOVING && !isPathClear())
//         {
//             logToSerialAndMqtt("[Nav] ⚠ Obstacle detected, entering recovery.");
//             currentState = OBSTACLE_AVOIDANCE; // Có thể đổi sang OBSTACLE_AVOIDANCE nếu đã cài đặt logic
//             break;
//         }

//         switch (navSubState)
//         {
        
//         case SUB_MOVING:
//         {
//             if (abs(angleError) < Config::ANGLE_TOLERANCE )
//             {
//                 driveDifferential(Config::MOVE_SPEED, Config::MOVE_SPEED);
//                 break;
//             }
//                logToSerialAndMqtt(" -> Angle drifted (Err: %.1f). Re-orienting.", angleError);
//                 float dynamicTurnSpeed_f = abs(angleError) * Config::KP_TURN_2WHEEL;
//                 int dynamicTurnSpeed = constrain((int)dynamicTurnSpeed_f, Config::MIN_TURN_SPEED, Config::TURN_SPEED);
//                 if (angleError > 0) {
//                     driveDifferential(-dynamicTurnSpeed, dynamicTurnSpeed);
//                 } else {
//                     driveDifferential(dynamicTurnSpeed, -dynamicTurnSpeed);
//                 }
//                 break;
//         }
//         case SUB_IDLE:
//             // Nếu đang ở trạng thái này và có lộ trình, nó sẽ tự được kích hoạt
//             // lại bằng các logic ở trên. Nếu không thì robot sẽ đứng yên.
//             break;
//         }
//         break;
//     }

// case OBSTACLE_AVOIDANCE:
// {
//     static ObstacleAvoidancePhase avoidPhase = AVOID_SCANNING;
//     static unsigned long avoidStartTime = 0;
//     static float chosenGapAngle = 0.0f;
//     static float originalTargetAngle = 0.0f; // Lưu hướng gốc đến target
    
//     // Khởi tạo lần đầu
//     if (avoidStartTime == 0) {
//         avoidStartTime = millis();
//         avoidPhase = AVOID_SCANNING;
//         driveDifferential(0, 0);
        
//         // Lưu hướng gốc đến target
//         float dx = targetPos.x - currentPos.x;
//         float dy = -(targetPos.y - currentPos.y);
//         originalTargetAngle = normalizeAngleDeg(atan2f(dy, dx) * 180.0f / PI);
        
//         logToSerialAndMqtt("[Obstacle] Starting avoidance (target: %.1f°)", originalTargetAngle);
//     }
    
//     unsigned long elapsed = millis() - avoidStartTime;
    
//     switch (avoidPhase) {
//         case AVOID_SCANNING:
//         {
//             driveDifferential(0, 0);
            
//             if (elapsed > 200) { // Giảm từ 300ms xuống 200ms
//                 const float MIN_GAP_WIDTH = 300.0f; 
//                 const float ANGLE_PENALTY = 2.0f;
                
//                 LidarModule::GapInfo bestGap = frontLidar.findBestGap(
//                     originalTargetAngle,
//                     -90,
//                     90,
//                     MIN_GAP_WIDTH,
//                     ANGLE_PENALTY
//                 );
                
//                 if (bestGap.isValid) {
//                     chosenGapAngle = bestGap.angle_deg;
//                     avoidPhase = AVOID_TURNING;
//                     avoidStartTime = millis();
                    
//                     logToSerialAndMqtt("[Obstacle] Gap at %.1f° (width: %.0fmm)", 
//                                        bestGap.angle_deg, bestGap.width_mm);
//                 } else {
//                     logToSerialAndMqtt("[Obstacle] No gap, switching to recovery");
//                     currentState = RECOVERY_STUCK;
//                     avoidStartTime = 0;
//                     avoidPhase = AVOID_SCANNING;
//                 }
//             }
//             break;
//         }
        
//         case AVOID_TURNING:
//         {
//             float angleError = normalizeAngleError(chosenGapAngle - currentHeading);
            
//             if (abs(angleError) < 15.0f) { // Giảm tolerance xuống 15° để rẽ dứt khoát
//                 driveDifferential(0, 0);
//                 delay(100);
                
//                 avoidPhase = AVOID_MOVING;
//                 avoidStartTime = millis();
//                 logToSerialAndMqtt("[Obstacle] Aligned to gap, charging through!");
//             } else {
//                 // RẼ DỨT KHOÁT - tốc độ cao
//                 int turnSpeed = (int)(abs(angleError) * Config::KP_TURN_2WHEEL); 
//                 turnSpeed = constrain(turnSpeed, Config::AVOID_TURN_SPEED , Config::AVOID_TURN_SPEED);
                
//                 if (angleError > 0) {
//                     driveDifferential(-turnSpeed, turnSpeed);
//                 } else {
//                     driveDifferential(turnSpeed, -turnSpeed);
//                 }
//             }
            
//             if (elapsed > 5000) { // Giảm timeout từ 3000ms
//                 logToSerialAndMqtt("[Obstacle] Turn timeout, recovery");
//                 currentState = RECOVERY_STUCK;
//                 avoidStartTime = 0;
//                 avoidPhase = AVOID_SCANNING;
//             }
//             break;
//         }
        
//         case AVOID_MOVING:
//         {
//             // **ĐI THẲNG QUA GAP - KHÔNG KIỂM TRA LIÊN TỤC**
//             if (elapsed < 2500) {
//                 driveDifferential(Config::MOVE_SPEED, Config::MOVE_SPEED);
//             }
//             else if (elapsed < 1500) {
//                 // 500ms tiếp theo: Kiểm tra đã thoát chưa
//                 if (isPathClear()) {
//                     // Đã thoát vật cản, CHUYỂN SANG REALIGN
//                     driveDifferential(0, 0);
//                     delay(100);
                    
//                     avoidPhase = AVOID_REALIGN; // State mới
//                     avoidStartTime = millis();
//                     logToSerialAndMqtt("[Obstacle] Cleared, realigning to target");
//                 } else {
//                     // Vẫn chưa thoát, tiếp tục đi
//                     driveDifferential(Config::MOVE_SPEED, Config::MOVE_SPEED);
//                 }
//             }
//             else {
//                 // Quá 1.5s vẫn không thoát → Quét lại hoặc recovery
//                 if (isPathClear()) {
//                     avoidPhase = AVOID_REALIGN;
//                     avoidStartTime = millis();
//                 } else {
//                     logToSerialAndMqtt("[Obstacle] Still blocked, re-scanning");
//                     avoidPhase = AVOID_SCANNING;
//                     avoidStartTime = millis();
//                     driveDifferential(0, 0);
//                 }
//             }
            
//             // Timeout tổng thể
//             if (elapsed > 5000) {
//                 logToSerialAndMqtt("[Obstacle] Movement timeout, recovery");
//                 currentState = RECOVERY_STUCK;
//                 avoidStartTime = 0;
//                 avoidPhase = AVOID_SCANNING;
//             }
//             break;
//         }
        
//         case AVOID_REALIGN:
//         {
//             // **QUAY LẠI HƯỚNG TARGET**
//             float dx = targetPos.x - currentPos.x;
//             float dy = -(targetPos.y - currentPos.y);
//             float currentTargetAngle = normalizeAngleDeg(atan2f(dy, dx) * 180.0f / PI);
//             float angleError = normalizeAngleError(currentTargetAngle - currentHeading);
            
//             if (abs(angleError) < Config::ANGLE_TOLERANCE) {
//                 // Đã quay xong, trở về navigation
//                 driveDifferential(0, 0);
//                 delay(100);
                
//                 logToSerialAndMqtt("[Obstacle] ✓ Realigned, resuming navigation");
//                 currentState = NAVIGATING_TO_TARGET;
//                 navSubState = SUB_MOVING;
//                 avoidStartTime = 0;
//                 avoidPhase = AVOID_SCANNING;
//                 recoveryAttempts = 0;
//                 lastProgressTime = millis(); // Reset stuck detection
//             } else {
//                 // Tiếp tục quay về hướng target
//                 int turnSpeed = (int)(abs(angleError) * Config::KP_TURN_2WHEEL);
//                 turnSpeed = constrain(turnSpeed, Config::MIN_TURN_SPEED, Config::TURN_SPEED);
                
//                 if (angleError > 0) {
//                     driveDifferential(-turnSpeed, turnSpeed);
//                 } else {
//                     driveDifferential(turnSpeed, -turnSpeed);
//                 }
//             }
            
//             // Timeout realign
//             if (elapsed > 2000) {
//                 logToSerialAndMqtt("[Obstacle] Realign timeout, forcing resume");
//                 currentState = NAVIGATING_TO_TARGET;
//                 navSubState = SUB_MOVING;
//                 avoidStartTime = 0;
//                 avoidPhase = AVOID_SCANNING;
//             }
//             break;
//         }
//     }
//     break;
// }

//     case RECOVERY_STUCK:
//     {
//         logToSerialAndMqtt("[Recovery] Attempt %d/%d", recoveryAttempts + 1, Config::MAX_RECOVERY_ATTEMPTS);
//         if (++recoveryAttempts >= Config::MAX_RECOVERY_ATTEMPTS)
//         {
//             logToSerialAndMqtt("[Recovery] Max attempts reached. Stopping.");
//             currentState = IDLE;
//             autoMode = false;
//             totalTargetsInQueue = 0;
//             currentTargetIndex = -1;
//             break;
//         }
//         driveDifferential(-Config::MOVE_SPEED, -Config::MOVE_SPEED);
//         delay(Config::RECOVERY_BACKUP_DURATION);
//         driveDifferential(Config::TURN_SPEED, -Config::TURN_SPEED);
//         timedAction.start(Config::RECOVERY_TURN_DURATION);
//         break;
//     }

//     case TARGET_REACHED:
//         stopAll();
//         navSubState = SUB_IDLE;
//         break;
//     }
// }

// // =================================================================
// // SETUP
// // =================================================================
// void setup()
// {
//     Serial.begin(115200);
//     delay(1000);
//     UWB_SERIAL.begin(115200, SERIAL_8N1, UWB_RX_PIN, UWB_TX_PIN);
//     Serial.println("\n=== ESP32 Robot Controller v4.1 (Route Following) ==="); // Cập nhật phiên bản
// #if ROBOT_TYPE == ROBOT_TYPE_CARLIKE
//     Serial.println("Robot Type: Car-Like Vehicle");
// #elif ROBOT_TYPE == ROBOT_TYPE_2WHEEL
//     Serial.println("Robot Type: 2-Wheel Differential Drive");
// #endif

//     NUVOTON_SERIAL.begin(115200, SERIAL_8N1, NUVOTON_RX, NUVOTON_TX);
//     //ySwitch.enableReceive(RF_RECEIVER_PIN);

//     Wire.begin();
//     if (!myIMU.begin(0x4B, Wire))
//     {
//         Serial.println("✗ IMU not detected. Halting.");
//         while (1)
//             delay(100);
//     }
//     Wire.setClock(400000);

//     if (myIMU.enableRotationVector(10))
//     {
//         Serial.println("✓ IMU rotation vector enabled");
//     }

//     // Calibrate IMU: Đặt hướng ban đầu của robot
//     // 0° = Bắc, 90° = Đông, 180° = Nam, 270° = Tây
//     calibrateIMUHeading(0.0f); // Thay đổi giá trị này nếu robot hướng khác

//     frontLidar.begin();
//     Serial.println("✓ LIDAR initialized");

//     setupWiFi();
//     // wifiClient.setInsecure();
//     mqttClient.setServer(Config::MQTT_SERVER, Config::MQTT_PORT);
//     mqttClient.setCallback(mqttCallback);
//     mqttClient.setBufferSize(512); // Tăng buffer size để nhận JSON dài hơn

//     stopAll();

//     Serial.println("\n=== UWB Anchor Configuration ===");
//     Serial.println("Anchor 1: (0.0m, 5.0m, 0.75m)");
//     Serial.println("Anchor 2: (5.0m, 0.0m, 0.75m)");
//     Serial.println("Anchor 3: (5.0m, 5.0m, 0.75m)");
//     Serial.printf("Tag Height: %.2fm\n", TAG_HEIGHT);
//     Serial.println("=== Robot Ready - Waiting for UWB data ===\n");
// }

// // =================================================================
// // MAIN LOOP
// // =================================================================
// void loop()
// {
//     handleUWBInput();
//     checkWiFiConnection();
//     if (!mqttClient.connected())
//         reconnectMQTT();
//     else
//         mqttClient.loop();

//     updateIMU();
//     //handleRFInput();
//     frontLidar.loop();
//     publishRobotStatus();
//     publishPosition();

//     unsigned long now = millis();
//     bool rfActive = rfData.valid && (now - rfData.lastReceived <= Config::RF_TIMEOUT);

//     if (rfActive)
//     {
//         if (autoMode)
//         {
//             autoMode = false;
//             currentState = IDLE;
//             stopAll();
//             totalTargetsInQueue = 0;
//             currentTargetIndex = -1;
//             logToSerialAndMqtt("[Control] RF input detected. Auto mode OFF.");
//         }
//         controlManual();
//     }
//     else if (autoMode)
//     {
//         controlAuto();
//     }
//     else
//     {
//         if (currentState != IDLE)
//         {
//             currentState = IDLE;
//             stopAll();
//         }
//     }
// }
