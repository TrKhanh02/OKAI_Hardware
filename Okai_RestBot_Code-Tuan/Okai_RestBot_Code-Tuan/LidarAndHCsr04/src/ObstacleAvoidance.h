// ============================================================================
// ObstacleAvoidance.h - Header file xử lý tránh vật cản
// ============================================================================
#ifndef OBSTACLE_AVOIDANCE_H
#define OBSTACLE_AVOIDANCE_H

#include "MotorController.h"
#include "SensorManager.h"

class ObstacleAvoidance {
private:
    MotorController* motor;
    SensorManager* sensor;
    
    unsigned long stepTimer;
    int currentStepIndex;
    bool isActive;
    
    // Định nghĩa các bước tránh vật cản
    struct AvoidanceStep {
        void (ObstacleAvoidance::*action)();
        unsigned long duration;
    };
    
    static const int TOTAL_STEPS = 12;
    AvoidanceStep steps[TOTAL_STEPS];
    
    // Các hành động cụ thể
    void actionStop();
    void actionMoveBackward();
    void actionTurnLeft();
    void actionMoveForward();
    void actionTurnRight();
    
    // Kiểm tra vật cản động trong khi thực hiện
    bool checkObstacleDuringReverse();
    bool checkObstacleDuringForward();
    bool checkObstacleDuringLeftTurn();
    bool checkObstacleDuringRightTurn();
    
    void executeCurrentStep();
    void nextStep();
    
public:
    ObstacleAvoidance(MotorController* motorController, SensorManager* sensorManager);
    void init();
    void start();
    void stop();
    void update();
    bool isAvoidanceActive();
    bool shouldActivate();
};

#endif