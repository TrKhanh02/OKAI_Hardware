#ifndef BNO08X_MODULE_H
#define BNO08X_MODULE_H

#include <Wire.h>
#include "SparkFun_BNO08x_Arduino_Library.h"

class Bno08xModule {
public:
    // Constructor - Hàm khởi tạo
    Bno08xModule(int intPin = -1, int rstPin = -1);

    // Hàm bắt đầu hoạt động của cảm biến
    bool begin(uint8_t i2c_addr = 0x4B);

    // Hàm cập nhật dữ liệu từ cảm biến (cần gọi liên tục trong loop)
    void update();

    // Hàm lấy giá trị góc quay (yaw/heading)
    float getHeading();

    // Hàm kiểm tra xem dữ liệu có hợp lệ và mới không
    bool isDataValid();
    
    // Hàm lấy độ chính xác của cảm biến
    float getAccuracy();

private:
    BNO08x _imu; // Đối tượng IMU từ thư viện SparkFun
    int _intPin;
    int _rstPin;

    // Các biến để lưu trữ dữ liệu đọc được
    float _yaw = 0.0;
    float _pitch = 0.0;
    float _roll = 0.0;
    float _accuracy = 0.0; // Độ chính xác của cảm biến

    bool _dataValid = false; // Cờ báo dữ liệu có hợp lệ không
    unsigned long _lastDataTime = 0; // Thời điểm cuối cùng nhận được dữ liệu

    // Hàm cài đặt các báo cáo từ cảm biến
    void setReports();
};

#endif