// ============================================================================
// MotorController.cpp - Implementation điều khiển động cơ
// ============================================================================
#include "MotorController.h"
#include "Config.h"
#include <Arduino.h>

MotorController::MotorController(HardwareSerial* serialPort) {
    motorSerial = serialPort;
    lastCommand = {0, 0, 0, 0, 0, 0, 0, 0};
}

void MotorController::init() {
    motorSerial->begin(2400, SERIAL_8N1, Config::MOTOR_RX_PIN, Config::MOTOR_TX_PIN);
    Serial.println("Motor Controller initialized on UART");
}

void MotorController::sendCommand(int angelA, int dutyAngelA, int angelB, int dutyAngelB, 
                                   int dirMotorA, int dutyMotorA, int dirMotorB, int dutyMotorB) {
    bool isSameCommand = (angelA == lastCommand.angelA && dutyAngelA == lastCommand.dutyAngelA &&
                          angelB == lastCommand.angelB && dutyAngelB == lastCommand.dutyAngelB &&
                          dirMotorA == lastCommand.m1_dir && dutyMotorA == lastCommand.m1_duty &&
                          dirMotorB == lastCommand.m2_dir && dutyMotorB == lastCommand.m2_duty);

    if (isSameCommand) return;

    char buf[128];
    snprintf(buf, sizeof(buf), "%d,%d,%d,%d,%d,%d,%d,%d|\n",
             angelA, dutyAngelA, angelB, dutyAngelB,
             dirMotorA, dutyMotorA, dirMotorB, dutyMotorB);
    motorSerial->print(buf);

    lastCommand = {angelA, dutyAngelA, angelB, dutyAngelB, 
                   dirMotorA, dutyMotorA, dirMotorB, dutyMotorB};
}

void MotorController::stop() {
    sendCommand(0, 0, 0, 0, 0, 0, 0, 0);
}

void MotorController::moveForward(int speed) {
    driveDifferential(speed, speed);
}

void MotorController::moveBackward(int speed) {
    driveDifferential(-speed, -speed);
}

void MotorController::turnLeft(int speed) {
    driveDifferential(-speed / 2, speed / 2);
}

void MotorController::turnRight(int speed) {
    driveDifferential(speed / 2, -speed / 2);
}

void MotorController::driveDifferential(int leftSpeed, int rightSpeed) {
    leftSpeed = constrain(leftSpeed, -Config::MAX_SPEED, Config::MAX_SPEED);
    rightSpeed = constrain(rightSpeed, -Config::MAX_SPEED, Config::MAX_SPEED);

    int leftDir = (leftSpeed >= 0) ? 1 : 0;
    int leftDuty = abs(leftSpeed);
    int rightDir = (rightSpeed >= 0) ? 1 : 0;
    int rightDuty = abs(rightSpeed);

    sendCommand(0, 0, 0, 0, leftDir, leftDuty, rightDir, rightDuty);
}
