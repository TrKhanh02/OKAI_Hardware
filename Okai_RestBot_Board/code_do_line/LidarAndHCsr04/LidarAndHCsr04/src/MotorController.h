// ============================================================================
// MotorController.h - Header file điều khiển động cơ
// ============================================================================
#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <HardwareSerial.h>

class MotorController {
private:
    struct CarCommand {
        int angelA;
        int dutyAngelA;
        int angelB;
        int dutyAngelB;
        int m1_dir;
        int m1_duty;
        int m2_dir;
        int m2_duty;
    };
    
    CarCommand lastCommand;
    HardwareSerial* motorSerial;
    
    // --- THÊM DÒNG NÀY ---
    unsigned long lastSentTime; 
    // --------------------
    
public:
    MotorController(HardwareSerial* serialPort);
    void init();
    void sendCommand(int angelA, int dutyAngelA, int angelB, int dutyAngelB, 
                      int dirMotorA, int dutyMotorA, int dirMotorB, int dutyMotorB);
    void stop();
    void moveForward(int speed);
    void moveBackward(int speed);
    void turnLeft(int speed);
    void turnRight(int speed);
    void driveDifferential(int leftSpeed, int rightSpeed);
};

#endif