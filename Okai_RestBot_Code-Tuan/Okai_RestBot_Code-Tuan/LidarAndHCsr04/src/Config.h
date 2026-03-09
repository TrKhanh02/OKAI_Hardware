// ============================================================================
// Config.h - File cấu hình
// ============================================================================
#ifndef CONFIG_H
#define CONFIG_H

namespace Config {
    // --- Cấu hình Tốc độ ---
    const int MAX_SPEED = 255; 
    const int MIN_SPEED = 0; // Tốc độ tối thiểu khi không quay ngược
    const int OBSTACLE_DISTANCE_CM = 20;
    
    // Tốc độ cơ sở khi đi thẳng
    const int BASE_SPEED = 18; // Tăng BASE_SPEED lên để có độ linh hoạt cho PID
    
    // --- Cấu hình PID ---
    // Cần phải điều chỉnh Kp, Ki, Kd dựa trên robot thực tế.
    const float Kp = 1.6;     // Hệ số Tỷ lệ (P): Phản ứng với lỗi hiện tại
    const float Ki = 0.0;      // Hệ số Tích phân (I): Thường để 0 cho bám đường cơ bản
    const float Kd = 0.2;      // Hệ số Đạo hàm (D): Giúp giảm thiểu dao động
    const int TURN_SPEED_FORWARD = 35; // Tăng từ 27 lên 35
    const int TURN_SPEED_REVERSE = -20; // Tăng từ -6 lên -20 (Tăng lực quay ngược)
    // Giới hạn độ điều chỉnh tối đa từ PID (Tốc độ tối đa phải lớn hơn BASE_SPEED + MAX_CORRECTION)
    const int MAX_CORRECTION =10; 
    
    // --- Cấu hình UART ---
    // UART cho Nuvoton điều khiển động cơ
    const int MOTOR_RX_PIN = 39; 
    const int MOTOR_TX_PIN = 19;
    
    // UART cho Nuvoton dò line
    const int LINE_RX_PIN = 4;
    const int LINE_TX_PIN = -1;
    
    const size_t JSON_CAPACITY = 100;
}

#endif