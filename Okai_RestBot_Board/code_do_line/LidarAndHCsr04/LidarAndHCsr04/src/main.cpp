#include <HardwareSerial.h>
#include "Config.h"
#include "MotorController.h"
#include "SensorManager.h"
#include "ObstacleAvoidance.h"
#include "LineFollower.h"
// Khai báo 2 UART riêng biệt cho 2 Nuvoton
HardwareSerial SerialMotor(2);  // UART2 cho điều khiển động cơ
HardwareSerial SerialLine(1);   // UART1 cho dò lin
// Khởi tạo các module
MotorController motorController(&SerialMotor);

SensorManager sensorManager;
ObstacleAvoidance obstacleAvoidance(&motorController, &sensorManager);
LineFollower lineFollower(&motorController, &sensorManager, &SerialLine);

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("========================================");
    Serial.println("Robot System with Dual Nuvoton Starting");
    Serial.println("========================================");
    
    // Khởi tạo các module
    motorController.init();
    sensorManager.init();
    obstacleAvoidance.init();
    lineFollower.init();
    
    Serial.println("========================================");
    Serial.println("System Ready!");
    Serial.println("- Motor Control: UART2");
    Serial.println("- Line Sensor: UART1");
    Serial.println("- Ultrasonic: 10 sensors");
    Serial.println("========================================");
}

void loop() {
    // sensorManager.update();
    
    // if (!obstacleAvoidance.isAvoidanceActive() && obstacleAvoidance.shouldActivate()) {
    //     obstacleAvoidance.start();
    // }
    
    // if (obstacleAvoidance.isAvoidanceActive()) {
    //     obstacleAvoidance.update();
    //     return;
    // }
    
    lineFollower.update();
}