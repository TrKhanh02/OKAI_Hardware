// ============================================================================
// SensorManager.h - Header file quản lý cảm biến
// ============================================================================
#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <NewPing.h>

#define SONAR_NUM 10
#define MAX_DISTANCE 200
#define PING_INTERVAL 33

enum SensorPosition {
    FRONT_L = 0,
    FRONT_M = 1,
    FRONT_R = 2,
    REAR_L = 3,
    REAR_M = 4,
    REAR_R = 5,
    SIDE_FL = 6,
    SIDE_FR = 7,
    SIDE_RL = 8,
    SIDE_RR = 9
};

class SensorManager {
private:
    NewPing* sonars[SONAR_NUM];
    unsigned long pingTimer[SONAR_NUM];
    unsigned int distances[SONAR_NUM];
    uint8_t currentSensor;
    
    static void echoCheckStatic();
    void echoCheck();
    
public:
    SensorManager();
    void init();
    void update();
    unsigned int getDistance(SensorPosition pos);
    bool hasObstacle(SensorPosition pos, int thresholdCm);
    bool checkFrontObstacle(int thresholdCm);
    bool checkRearObstacle(int thresholdCm);
    bool checkLeftSideObstacle(int thresholdCm);
    bool checkRightSideObstacle(int thresholdCm);
};

#endif