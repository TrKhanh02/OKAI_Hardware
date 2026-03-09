#include "LineFollower.h"
#include "Config.h"
#include <Arduino.h>
#include "MotorController.h"
#include "SensorManager.h"

// ---------------- Constants ----------------
static const unsigned long TURN_MIN_TIME = 250;
static const unsigned long TURN_MAX_TIME = 2500; 
static const unsigned long EXIT_STABILIZE_MS = 400;
static const unsigned long INTERSECTION_CLEAR_MS = 400;
static const int INTERSECTION_LEAVE_DEBOUNCE_FRAMES = 3;
static const int DETECT_CONFIRM_FRAMES = 5;
static const int EXIT_CONFIRM_FRAMES = 3;
static const unsigned int FULL_PATTERN = 0b11111111111;
static const float LARGE_ERROR_THRESHOLD = 1.5f;
static bool intersectionActive = false; // true khi robot đang xử lý giao lộ
// ---------------- File-scope variables ----------------
static unsigned long turnStartTime = 0;
static int turnExitStableCount = 0;
static unsigned long exitStabilizeUntil = 0;

static int intersectionCount = 1;
static bool intersectionLock = false;
static bool intersectionPendingIncrease = false;
static unsigned long intersectionWaitUntil = 0;
static int intersectionLeftDebounce = 0;
const float LineFollower::LARGE_ERROR_THRESHOLD = 1.5f;
// ---------------- Constructor ----------------
LineFollower::LineFollower(MotorController *motorController, SensorManager *sensorManager, HardwareSerial *lineSerialPort)
{
    motor = motorController;
    sensor = sensorManager;
    lineSerial = lineSerialPort;
    
    currentState = STATE_FOLLOW_LINE;

    turnStartTime = 0;
    turnExitStableCount = 0;
    exitStabilizeUntil = 0;

    intersectionCount = 1;
    intersectionLock = false;
    intersectionPendingIncrease = false;
    intersectionWaitUntil = 0;
    intersectionLeftDebounce = 0;

    resetPID();
}

// ---------------- Init ----------------
void LineFollower::init()
{
    lineSerial->begin(115200, SERIAL_8N1, Config::LINE_RX_PIN, Config::LINE_TX_PIN);
    Serial.println("Line Follower initialized (optimized turns & smooth curves)");
}

// ---------------- PID Reset ----------------
void LineFollower::resetPID()
{
    lastError = 0.0f;
    integral = 0.0f;
    LPF_Error = 0.0f;
    dFilt = 0.0f;
}

// ---------------- Side Obstacle Check ----------------
bool LineFollower::checkSideObstaclesWhileTurning(bool isTurningLeft)
{
    if (isTurningLeft) return sensor->checkLeftSideObstacle(Config::OBSTACLE_DISTANCE_CM);
    else return sensor->checkRightSideObstacle(Config::OBSTACLE_DISTANCE_CM);
}

// ---------------- Line Center Detection ----------------
bool LineFollower::isLineInCenter(unsigned int pattern)
{
    const unsigned int CM = (1U << 4) | (1U << 5) | (1U << 6);
    return (pattern & CM) == CM;
}

// ---------------- Handle Special Cases ----------------
bool LineFollower::handleSpecialCases(unsigned int pattern, float linePosition, int activeBits)
{
    static int rightDetectCount = 0;
    static int leftDetectCount = 0;

    // 1. Lost line
    if(pattern == 0)
    {
        if(currentState == STATE_FOLLOW_LINE)
        {
            Serial.println(" -> LOST LINE, STOP");
            motor->driveDifferential(0,0);
            currentState = STATE_STOP;
            resetPID();
        }
        return true;
    }

    // 2. Intersection detection
if(pattern == FULL_PATTERN)
{
    if(currentState == STATE_SHARP_TURN_LEFT || currentState == STATE_SHARP_TURN_RIGHT)
        return true;

    // Chỉ xử lý giao lộ khi chưa lock
    if(!intersectionActive)
    {
        intersectionActive = true;  // Lock giao lộ
        intersectionPendingIncrease = true; // đánh dấu sẽ tăng count khi thoát

        intersectionLeftDebounce = 0;
        Serial.print(" -> INTERSECTION DETECTED, COUNT=");
        Serial.println(intersectionCount);

        // Hành động theo lượt giao lộ
        if(intersectionCount == 1)
        {
            Serial.println(" -> GO STRAIGHT (force interval)");
            intersectionWaitUntil = millis() + INTERSECTION_CLEAR_MS;
        }
        else if(intersectionCount == 2)
        {
            Serial.println(" -> TURN RIGHT");
            startTurnRight(true);
        }
        else if(intersectionCount == 3)
        {
            Serial.println(" -> TURN LEFT");
            startTurnLeft(true);
        }
    }

    return true;
}



    // 3. Sharp turn detection (vòng cung)
    if(millis() < exitStabilizeUntil) return false;
    if(!intersectionLock && linePosition >= 6.0f && activeBits >= 6)
    {
        rightDetectCount++;
        leftDetectCount = 0;
        if(rightDetectCount >= DETECT_CONFIRM_FRAMES)
        {
            Serial.println(" -> SHARP RIGHT DETECTED");
            intersectionLock = true;
            intersectionPendingIncrease = false;
            intersectionLeftDebounce = 0;
            startTurnRight(false);
            rightDetectCount = 0;
            return true;
        }
    }
    else if(!intersectionLock && linePosition <= 4.0f && activeBits >= 6)
    {
        leftDetectCount++;
        rightDetectCount = 0;
        if(leftDetectCount >= DETECT_CONFIRM_FRAMES)
        {
            Serial.println(" -> SHARP LEFT DETECTED");
            intersectionLock = true;
            intersectionPendingIncrease = false;
            intersectionLeftDebounce = 0;
            startTurnLeft(false);
            leftDetectCount = 0;
            return true;
        }
    }
    else
    {
        rightDetectCount = 0;
        leftDetectCount = 0;
    }

    return false;
}

// ---------------- Start Turn ----------------
void LineFollower::startTurnLeft(bool isSharp)
{
    Serial.println(" -> START LEFT TURN");
    currentState = STATE_SHARP_TURN_LEFT;
    turnStartTime = millis();
    int leftSpeed = -Config::BASE_SPEED/2;
    int rightSpeed = (int)(Config::BASE_SPEED * (isSharp?1.5f:1.0f));

    if(checkSideObstaclesWhileTurning(true))
    {
        Serial.println("WARNING: Obstacle LEFT! STOP");
        motor->driveDifferential(0,0);
        currentState = STATE_STOP;
    }
    else motor->driveDifferential(leftSpeed,rightSpeed);

    resetPID();
}

void LineFollower::startTurnRight(bool isSharp)
{
    Serial.println(" -> START RIGHT TURN");
    currentState = STATE_SHARP_TURN_RIGHT;
    turnStartTime = millis();
    int leftSpeed = (int)(Config::BASE_SPEED * (isSharp?1.5f:1.0f));
    int rightSpeed = -Config::BASE_SPEED/2;

    if(checkSideObstaclesWhileTurning(false))
    {
        Serial.println("WARNING: Obstacle RIGHT! STOP");
        motor->driveDifferential(0,0);
        currentState = STATE_STOP;
    }
    else motor->driveDifferential(leftSpeed,rightSpeed);

    resetPID();
}

// ---------------- Handle Turn ----------------
void LineFollower::handleTurnLeft(unsigned int pattern)
{
    int leftSpeed = -Config::BASE_SPEED/2;
    int rightSpeed = (int)(Config::BASE_SPEED*1.5f);
    unsigned long now = millis();

    if(now-turnStartTime < TURN_MIN_TIME){ motor->driveDifferential(leftSpeed,rightSpeed); return; }
    if(now-turnStartTime > TURN_MAX_TIME){ Serial.println("TURN LEFT TIMEOUT"); motor->driveDifferential(0,0); currentState=STATE_STOP; return; }

    if(pattern == 0){ motor->driveDifferential(leftSpeed,rightSpeed); turnExitStableCount=0; return; }

    if(isLineInCenter(pattern))
    {
        turnExitStableCount++;
        if(turnExitStableCount>=EXIT_CONFIRM_FRAMES)
        {
            Serial.println("EXIT LEFT TURN -> FOLLOW LINE");
            currentState=STATE_FOLLOW_LINE;
            turnExitStableCount=0;
            intersectionLeftDebounce=0;
            exitStabilizeUntil = millis() + EXIT_STABILIZE_MS;
            resetPID();
            intersectionLock=false;
            if(intersectionPendingIncrease) { intersectionCount=(intersectionCount%3)+1; intersectionPendingIncrease=false; }
            return;
        }
    }
    else turnExitStableCount=0;

    motor->driveDifferential(leftSpeed,rightSpeed);
}

void LineFollower::handleTurnRight(unsigned int pattern)
{
    int leftSpeed = (int)(Config::BASE_SPEED*1.5f);
    int rightSpeed = -Config::BASE_SPEED/2;
    unsigned long now = millis();

    if(now-turnStartTime < TURN_MIN_TIME){ motor->driveDifferential(leftSpeed,rightSpeed); return; }
    if(now-turnStartTime > TURN_MAX_TIME){ Serial.println("TURN RIGHT TIMEOUT"); motor->driveDifferential(0,0); currentState=STATE_STOP; return; }

    if(pattern == 0){ motor->driveDifferential(leftSpeed,rightSpeed); turnExitStableCount=0; return; }

    if(isLineInCenter(pattern))
    {
        turnExitStableCount++;
        if(turnExitStableCount>=EXIT_CONFIRM_FRAMES)
        {
            Serial.println("EXIT RIGHT TURN -> FOLLOW LINE");
            currentState=STATE_FOLLOW_LINE;
            turnExitStableCount=0;
            intersectionLeftDebounce=0;
            exitStabilizeUntil = millis() + EXIT_STABILIZE_MS;
            resetPID();
            intersectionLock=false;
            if(intersectionPendingIncrease) { intersectionCount=(intersectionCount%3)+1; intersectionPendingIncrease=false; }
            return;
        }
    }
    else turnExitStableCount=0;

    motor->driveDifferential(leftSpeed,rightSpeed);
}

// ---------------- PID Line Following ----------------
void LineFollower::processLinePattern(unsigned int pattern)
{
    const float SET_POINT = 5.0f;

    int activeBits=0, weightedSum=0;
    for(int i=0;i<11;i++){ if(pattern & (1<<i)){ activeBits++; weightedSum+=i; } }
    float linePos = (activeBits>0)?((float)weightedSum/activeBits):SET_POINT;

    Serial.print("DEBUG: Pattern="); Serial.print(pattern,BIN); Serial.print(" | Pos="); Serial.println(linePos);

    if(handleSpecialCases(pattern,linePos,activeBits)) return;

    static unsigned long lastPidMillis = millis();
    unsigned long now = millis();
    float dt = (now - lastPidMillis)/1000.0f;
    if(dt<=0.0f) dt=0.01f;
    lastPidMillis=now;

    float rawError = linePos - SET_POINT;
    LPF_Error = 0.6f*LPF_Error + 0.4f*rawError;
    float error = (fabs(LPF_Error)<0.2f)?0.0f:LPF_Error;

    float Kp_eff = Config::Kp;
    float Ki_eff = Config::Ki;
    if(fabs(error) > LARGE_ERROR_THRESHOLD){ Kp_eff*=1.6f; Ki_eff=0.0f; }

    float P = Kp_eff*error;
    if(fabs(error)<2.0f && Ki_eff>0.0f) integral+=error*dt;
    float I = Ki_eff*integral;

    float dRaw = (error - lastError)/dt;
    dFilt = 0.5f*dFilt + 0.5f*dRaw;
    lastError = error;

    float D = Config::Kd*dFilt;
    float correction = P + I + D;
    float ramp = (millis()<exitStabilizeUntil)?0.5f:1.0f;
    correction *= ramp;
    correction = constrain(correction,-Config::MAX_CORRECTION,Config::MAX_CORRECTION);

    int baseSpeed = Config::BASE_SPEED;
    int leftSpeed = constrain(baseSpeed + (int)correction, -Config::MAX_SPEED, Config::MAX_SPEED);
    int rightSpeed = constrain(baseSpeed - (int)correction, -Config::MAX_SPEED, Config::MAX_SPEED);

    motor->driveDifferential(leftSpeed,rightSpeed);

    Serial.print(" | Err="); Serial.print(error);
    Serial.print(" | Corr="); Serial.print(correction);
    Serial.print(" | L="); Serial.print(leftSpeed);
    Serial.print(" | R="); Serial.println(rightSpeed);
}

// ---------------- Main Update ----------------
void LineFollower::update()
{
    if(!lineSerial->available()) return;

    DeserializationError error = deserializeJson(doc, *lineSerial);
    if(error){
        while(lineSerial->available()) lineSerial->read();
        return;
    }

    unsigned int pattern = doc["pattern"];
    unsigned long now = millis();

    // --- Force straight if intersection wait (FULL_PATTERN action) ---
    if(intersectionWaitUntil != 0 && now < intersectionWaitUntil)
    {
        motor->driveDifferential(Config::BASE_SPEED, Config::BASE_SPEED);
        return;
    }

    // --- Handle intersection unlock and count increment ---
    if(intersectionActive && pattern != FULL_PATTERN)
    {
        intersectionLeftDebounce++;
        if(intersectionLeftDebounce >= INTERSECTION_LEAVE_DEBOUNCE_FRAMES)
        {
            if(intersectionPendingIncrease)
            {
                intersectionCount = (intersectionCount % 3) + 1;
                intersectionPendingIncrease = false;
            }
            intersectionActive = false;  // unlock FULL_PATTERN
            intersectionLeftDebounce = 0;
        }
    }
    else if(currentState != STATE_FOLLOW_LINE)
    {
        intersectionLeftDebounce = 0;
    }

    // --- STOP state recovery ---
    if(currentState == STATE_STOP)
    {
        if(pattern != 0)
        {
            currentState = STATE_FOLLOW_LINE;
            resetPID();
        }
        else
        {
            motor->driveDifferential(0,0);
            return;
        }
    }

    // --- State handling ---
    switch(currentState)
    {
        case STATE_FOLLOW_LINE:
            processLinePattern(pattern);
            break;

        case STATE_SHARP_TURN_LEFT:
            handleTurnLeft(pattern);
            break;

        case STATE_SHARP_TURN_RIGHT:
            handleTurnRight(pattern);
            break;

        default:
            motor->driveDifferential(0,0);
            currentState = STATE_STOP;
            break;
    }
}