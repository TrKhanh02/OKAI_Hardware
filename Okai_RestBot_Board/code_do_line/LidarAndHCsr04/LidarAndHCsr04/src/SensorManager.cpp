// ============================================================================
// SensorManager.cpp - Implementation quản lý cảm biến
// ============================================================================
#include "SensorManager.h"
#include "Config.h"

static SensorManager* sensorManagerInstance = nullptr;

SensorManager::SensorManager() {
    sensorManagerInstance = this;
    currentSensor = 0;
    
    // Khởi tạo các cảm biến siêu âm
    sonars[0] = new NewPing(25, 26, MAX_DISTANCE); // FRONT_L
    sonars[1] = new NewPing(27, 14, MAX_DISTANCE); // FRONT_M
    sonars[2] = new NewPing(12, 13, MAX_DISTANCE); // FRONT_R
    sonars[3] = new NewPing(5, 18, MAX_DISTANCE);  // REAR_L
    sonars[4] = new NewPing(17, 21, MAX_DISTANCE); // REAR_M
    sonars[5] = new NewPing(22, 23, MAX_DISTANCE); // REAR_R
    sonars[6] = new NewPing(32, 33, MAX_DISTANCE); // SIDE_FL
    sonars[7] = new NewPing(15, 0, MAX_DISTANCE);  // SIDE_FR (Thay đổi từ pin 4)
    sonars[8] = new NewPing(36, 16, MAX_DISTANCE); // SIDE_RL
    sonars[9] = new NewPing(35, 34, MAX_DISTANCE); // SIDE_RR (Thay đổi từ pin 2)
    
    for (int i = 0; i < SONAR_NUM; i++) {
        distances[i] = 0;
    }
}

void SensorManager::init() {
    pingTimer[0] = millis() + 75;
    for (uint8_t i = 1; i < SONAR_NUM; i++) {
        pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
    }
    Serial.println("Sensor Manager initialized with 10 ultrasonic sensors");
}

void SensorManager::echoCheckStatic() {
    if (sensorManagerInstance) {
        sensorManagerInstance->echoCheck();
    }
}

void SensorManager::echoCheck() {
    if (sonars[currentSensor]->check_timer()) {
        distances[currentSensor] = sonars[currentSensor]->ping_result / US_ROUNDTRIP_CM;
    }
}

void SensorManager::update() {
    for (uint8_t i = 0; i < SONAR_NUM; i++) {
        if (millis() >= pingTimer[i]) {
            pingTimer[i] += PING_INTERVAL * SONAR_NUM;
            sonars[currentSensor]->timer_stop();
            currentSensor = i;
            distances[currentSensor] = 0;
            sonars[currentSensor]->ping_timer(echoCheckStatic);
        }
    }
}

unsigned int SensorManager::getDistance(SensorPosition pos) {
    return distances[pos];
}

bool SensorManager::hasObstacle(SensorPosition pos, int thresholdCm) {
    return (distances[pos] > 0 && distances[pos] < thresholdCm);
}

bool SensorManager::checkFrontObstacle(int thresholdCm) {
    return hasObstacle(FRONT_L, thresholdCm) || 
           hasObstacle(FRONT_M, thresholdCm) || 
           hasObstacle(FRONT_R, thresholdCm);
}

bool SensorManager::checkRearObstacle(int thresholdCm) {
    return hasObstacle(REAR_L, thresholdCm) || 
           hasObstacle(REAR_M, thresholdCm) || 
           hasObstacle(REAR_R, thresholdCm);
}

bool SensorManager::checkLeftSideObstacle(int thresholdCm) {
    return hasObstacle(SIDE_FL, thresholdCm) || 
           hasObstacle(SIDE_RL, thresholdCm);
}

bool SensorManager::checkRightSideObstacle(int thresholdCm) {
    return hasObstacle(SIDE_FR, thresholdCm) || 
           hasObstacle(SIDE_RR, thresholdCm);
}
