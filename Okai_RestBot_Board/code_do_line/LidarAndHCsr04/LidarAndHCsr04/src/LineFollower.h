#ifndef LINEFOLLOWER_H
#define LINEFOLLOWER_H

#include "Config.h"
#include <ArduinoJson.h>
#include <HardwareSerial.h>

class MotorController;
class SensorManager;

enum FollowerState
{
    STATE_FOLLOW_LINE,
    STATE_SHARP_TURN_LEFT,
    STATE_SHARP_TURN_RIGHT,
    STATE_CORNER_LEFT,
    STATE_CORNER_RIGHT,
    STATE_STOP
};

class LineFollower
{
private:
    MotorController *motor;
    SensorManager *sensor;
    HardwareSerial *lineSerial;
    StaticJsonDocument<200> doc;

    // PID variables
    float lastError;
    float integral;
    float LPF_Error = 0.0f;
    float dFilt = 0.0f;

    FollowerState currentState;

    // Turn tracking
    unsigned long turnStartTime;
    int turnExitStableCount;
    unsigned long exitStabilizeUntil;

    // Intersection tracking
    int intersectionCount;
    bool intersectionLock;
    bool intersectionPendingIncrease;
    unsigned long intersectionWaitUntil;
    int intersectionLeftDebounce;

    // Detect tuning
    static const int DETECT_CONFIRM_FRAMES = 5;
    static const int EXIT_CONFIRM_FRAMES = 4;
    static const float LARGE_ERROR_THRESHOLD;

    // Support functions
    void resetPID();
    bool checkSideObstaclesWhileTurning(bool isTurningLeft);
    bool isLineInCenter(unsigned int pattern);
    bool handleSpecialCases(unsigned int pattern, float linePosition, int activeBits);

    void startTurnLeft(bool isSharp);
    void startTurnRight(bool isSharp);

    void handleTurnLeft(unsigned int pattern);
    void handleTurnRight(unsigned int pattern);

    void processLinePattern(unsigned int pattern);

public:
    LineFollower(MotorController *motorController, SensorManager *sensorManager, HardwareSerial *lineSerialPort);
    void init();
    void update();
};

#endif // LINEFOLLOWER_H
