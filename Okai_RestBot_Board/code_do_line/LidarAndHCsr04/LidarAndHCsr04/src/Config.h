#ifndef CONFIG_H
#define CONFIG_H
#include <cstddef> 
namespace Config {
    const int MAX_SPEED = 255; 
    const int MIN_SPEED = 0; // Tốc độ tối thiểu khi không quay ngược
    const int OBSTACLE_DISTANCE_CM = 20;
    // Tốc độ cơ sở khi đi thẳng
    const int BASE_SPEED = 20; 
    
    const float Kp = 1.4; 
    const float Ki = 0.0; 
    const float Kd = 0.9;
    const int TURN_SPEED_FORWARD = 35; // Tốc độ bánh xe bên ngoài (tiến)
    const int TURN_SPEED_REVERSE = -20; // Tốc độ bánh xe bên trong (lùi/phanh)
    
    const int MAX_CORRECTION = 12; 
    
    // --- Cấu hình UART ---
    const int MOTOR_RX_PIN = 39; 
    const int MOTOR_TX_PIN = 19;
    
    const int LINE_RX_PIN = 4;
    const int LINE_TX_PIN = -1;

    const size_t JSON_CAPACITY = 100;
}
#endif