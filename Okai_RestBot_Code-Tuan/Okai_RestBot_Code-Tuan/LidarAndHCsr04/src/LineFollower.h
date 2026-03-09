// ============================================================================
// LineFollower.h - Header file dò line
// ============================================================================
#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include <ArduinoJson.h>
#include "MotorController.h"
#include "SensorManager.h"

class LineFollower {
private:
    MotorController* motor;
    SensorManager* sensor;
    HardwareSerial* lineSerial;  // UART riêng cho Nuvoton dò line
    StaticJsonDocument<100> doc;
    float lastError = 0.0;
    float integral = 0.0;
    void processLinePattern(unsigned int pattern);
    bool checkSideObstaclesWhileTurning(bool isTurningLeft);
    unsigned int readLinePattern();
    bool isLineInCenter(unsigned int pattern);
    int intersectionCount;
    unsigned long lastIntersectionTime;
     void performSharpTurn(bool isLeftTurn);
    
    
public:
    LineFollower(MotorController* motorController, SensorManager* sensorManager, HardwareSerial* lineSerialPort);
    void init();
    void update();
};

#endif
