// ============================================================================
// ObstacleAvoidance.cpp - Implementation xử lý tránh vật cản
// ============================================================================
#include "ObstacleAvoidance.h"
#include "Config.h"

ObstacleAvoidance::ObstacleAvoidance(MotorController* motorController, SensorManager* sensorManager) {
    motor = motorController;
    sensor = sensorManager;
    isActive = false;
    currentStepIndex = 0;
    stepTimer = 0;
}

void ObstacleAvoidance::init() {
    // Định nghĩa chuỗi hành động tránh vật cản (không dùng switch-case)
    steps[0] = {&ObstacleAvoidance::actionStop, 300};
    steps[1] = {&ObstacleAvoidance::actionMoveBackward, 300};
    steps[2] = {&ObstacleAvoidance::actionStop, 100};
    steps[3] = {&ObstacleAvoidance::actionTurnLeft, 300};
    steps[4] = {&ObstacleAvoidance::actionStop, 100};
    steps[5] = {&ObstacleAvoidance::actionMoveForward, 500};
    steps[6] = {&ObstacleAvoidance::actionStop, 100};
    steps[7] = {&ObstacleAvoidance::actionTurnRight, 500};
    steps[8] = {&ObstacleAvoidance::actionStop, 100};
    steps[9] = {&ObstacleAvoidance::actionMoveForward, 550};
    steps[10] = {&ObstacleAvoidance::actionStop, 100};
    steps[11] = {&ObstacleAvoidance::actionTurnRight, 400};
    
    Serial.println("Obstacle Avoidance initialized with 12 steps");
}

void ObstacleAvoidance::actionStop() {
    motor->stop();
}

void ObstacleAvoidance::actionMoveBackward() {
    if (checkObstacleDuringReverse()) {
        motor->stop();
        stop(); // Kết thúc tránh vật cản
    } else {
        motor->moveBackward(Config::BASE_SPEED);
    }
}

void ObstacleAvoidance::actionMoveForward() {
    if (checkObstacleDuringForward()) {
        motor->stop();
        stop();
    } else {
        motor->moveForward(Config::BASE_SPEED);
    }
}

void ObstacleAvoidance::actionTurnLeft() {
    if (checkObstacleDuringLeftTurn()) {
        return; // Không tăng step, sẽ thử lại
    }
    motor->turnLeft(Config::BASE_SPEED);
}

void ObstacleAvoidance::actionTurnRight() {
    if (checkObstacleDuringRightTurn()) {
        return;
    }
    motor->turnRight(Config::BASE_SPEED);
}

bool ObstacleAvoidance::checkObstacleDuringReverse() {
    return sensor->checkRearObstacle(Config::OBSTACLE_DISTANCE_CM);
}

bool ObstacleAvoidance::checkObstacleDuringForward() {
    return sensor->checkFrontObstacle(Config::OBSTACLE_DISTANCE_CM);
}

bool ObstacleAvoidance::checkObstacleDuringLeftTurn() {
    // Kiểm tra SIDE_FL
    if (sensor->hasObstacle(SIDE_FL, Config::OBSTACLE_DISTANCE_CM)) {
        if (!checkObstacleDuringReverse()) {
            motor->moveBackward(Config::BASE_SPEED);
            stepTimer = millis() + 200;
            return true;
        } else {
            motor->stop();
            stop();
            return true;
        }
    }
    
    // Kiểm tra SIDE_RR
    if (sensor->hasObstacle(SIDE_RR, Config::OBSTACLE_DISTANCE_CM)) {
        if (!checkObstacleDuringForward()) {
            motor->moveForward(Config::BASE_SPEED);
            stepTimer = millis() + 200;
            return true;
        } else {
            motor->stop();
            stop();
            return true;
        }
    }
    
    return false;
}

bool ObstacleAvoidance::checkObstacleDuringRightTurn() {
    // Kiểm tra SIDE_FR
    if (sensor->hasObstacle(SIDE_FR, Config::OBSTACLE_DISTANCE_CM)) {
        if (!checkObstacleDuringReverse()) {
            motor->moveBackward(Config::BASE_SPEED);
            stepTimer = millis() + 200;
            return true;
        } else {
            motor->stop();
            stop();
            return true;
        }
    }
    
    // Kiểm tra SIDE_RL
    if (sensor->hasObstacle(SIDE_RL, Config::OBSTACLE_DISTANCE_CM)) {
        if (!checkObstacleDuringForward()) {
            motor->moveForward(Config::BASE_SPEED);
            stepTimer = millis() + 200;
            return true;
        } else {
            motor->stop();
            stop();
            return true;
        }
    }
    
    return false;
}

void ObstacleAvoidance::executeCurrentStep() {
    if (currentStepIndex < TOTAL_STEPS) {
        (this->*steps[currentStepIndex].action)();
    }
}

void ObstacleAvoidance::nextStep() {
    currentStepIndex++;
    if (currentStepIndex >= TOTAL_STEPS) {
        stop();
    } else {
        stepTimer = millis() + steps[currentStepIndex].duration;
    }
}

void ObstacleAvoidance::start() {
    isActive = true;
    currentStepIndex = 0;
    stepTimer = 0;
    Serial.println("Starting obstacle avoidance sequence");
}

void ObstacleAvoidance::stop() {
    isActive = false;
    currentStepIndex = 0;
    motor->stop();
    Serial.println("Obstacle avoidance completed");
}

void ObstacleAvoidance::update() {
    if (!isActive) return;
    
    if (millis() < stepTimer) return;
    
    executeCurrentStep();
    nextStep();
}

bool ObstacleAvoidance::isAvoidanceActive() {
    return isActive;
}

bool ObstacleAvoidance::shouldActivate() {
    return sensor->checkFrontObstacle(Config::OBSTACLE_DISTANCE_CM);
}