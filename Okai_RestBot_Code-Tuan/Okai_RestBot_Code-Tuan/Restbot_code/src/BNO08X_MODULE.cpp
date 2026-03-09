#include "BNO08X_MODULE.h"

// Constructor: Gán các chân pin khi đối tượng được tạo
Bno08xModule::Bno08xModule(int intPin, int rstPin) {
    _intPin = intPin;
    _rstPin = rstPin;
}

// Hàm bắt đầu hoạt động của cảm biến
bool Bno08xModule::begin(uint8_t i2c_addr) {
    Wire.begin();
    if (_imu.begin(i2c_addr, Wire, _intPin, _rstPin) == false) {
        Serial.println("BNO08x not detected. Check connections. Freezing...");
        return false;
    }
    Serial.println("BNO08x found!");

    Wire.setClock(400000); // Tăng tốc độ I2C
    setReports();
    delay(100);
    return true;
}

// Cài đặt các báo cáo (dữ liệu) muốn nhận từ cảm biến
void Bno08xModule::setReports() {
    Serial.println("Setting desired IMU reports...");
    if (_imu.enableRotationVector(50)) { // Yêu cầu gửi dữ liệu mỗi 50ms
        Serial.println(F("Rotation vector enabled."));
    } else {
        Serial.println("Could not enable rotation vector.");
    }
}

// Hàm cập nhật, xử lý dữ liệu từ cảm biến
void Bno08xModule::update() {
    if (_imu.wasReset()) {
        Serial.print("IMU was reset. Re-setting reports.");
        setReports();
    }

    if (_imu.getSensorEvent() == true) {
        // Kiểm tra xem có phải dữ liệu chúng ta cần không
        if (_imu.getSensorEventID() == SENSOR_REPORTID_ROTATION_VECTOR) {
            // Lấy dữ liệu yaw, pitch, roll từ thư viện (đơn vị radians)
            float rawYaw = _imu.getYaw();
            float rawPitch = _imu.getPitch();
            float rawRoll = _imu.getRoll();
            
            // Chuyển đổi sang độ và chuẩn hóa góc Yaw
            _yaw = - (rawYaw * 180.0 / PI); // Đảo dấu để phù hợp với robot
            _pitch = rawPitch * 180.0 / PI;
            _roll = rawRoll * 180.0 / PI;

            if (_yaw < 0) {
                _yaw += 360; // Chuẩn hóa góc Yaw từ 0 -> 360 độ
            }
            
            _accuracy = _imu.getQuatAccuracy(); // Lấy độ chính xác
            _dataValid = true; // Đánh dấu là đã có dữ liệu
            _lastDataTime = millis(); // Ghi lại thời gian
        }
    }
}

// Trả về giá trị góc quay (heading)
float Bno08xModule::getHeading() {
    return _yaw;
}

// Trả về độ chính xác
float Bno08xModule::getAccuracy() {
    return _accuracy;
}

// Kiểm tra dữ liệu: phải hợp lệ VÀ không quá cũ (ví dụ: < 1 giây)
bool Bno08xModule::isDataValid() {
    return _dataValid && (millis() - _lastDataTime < 1000);
}