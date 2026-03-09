#include "LIDAR_MODULE.h"

// Global instance for static callbacks
LidarModule* globalLidarModuleInstance = nullptr;
static inline float normalizeAngleError(float ang)
{
    while (ang > 180.0f)
        ang -= 360.0f;
    while (ang < -180.0f)
        ang += 360.0f;
    return ang;
}
// Static callback implementations
int LidarModule::lidar_serial_read_callback() {
    if (globalLidarModuleInstance) {
        return globalLidarModuleInstance->_lidarSerial.read();
    }
    return -1;
}

size_t LidarModule::lidar_serial_write_callback(const uint8_t* buffer, size_t length) {
    if (globalLidarModuleInstance) {
        return globalLidarModuleInstance->_lidarSerial.write(buffer, length);
    }
    return 0;
}

void LidarModule::lidar_scan_point_callback(float angle_deg, float distance_mm, float quality, bool scan_completed) {
    if (!globalLidarModuleInstance) return;
    
    // Convert to cm and validate
    float dist_cm = (distance_mm <= 0 || distance_mm > 12000) ? 99999.0f : (distance_mm / 10.0f);
    
    // Normalize angle and get array index
    int idx = ((int)round(angle_deg) % 360 + 360) % 360;
    
    if (idx >= 0 && idx < N_DATA_QUADS) {
        globalLidarModuleInstance->_scanData[idx] = dist_cm;
    }

    if (scan_completed) {
        static unsigned long lastScanTime = 0;
        //Serial.printf("Scan completed; RPM: %.1f\n", globalLidarModuleInstance->_lidar.getCurrentScanFreqHz());
        lastScanTime = millis();
    }
}

void LidarModule::lidar_info_callback(LDS::info_t code, String info) {
    Serial.printf("LiDAR INFO [%s]: %s\n", globalLidarModuleInstance->_lidar.infoCodeToString(code).c_str(), info.c_str());
}

void LidarModule::lidar_error_callback(LDS::result_t code, String aux_info) {
    Serial.printf("LiDAR ERROR [%s]: %s\n", globalLidarModuleInstance->_lidar.resultCodeToString(code).c_str(), aux_info.c_str());
}

void LidarModule::lidar_packet_callback(uint8_t* packet, uint16_t length, bool scan_completed) {
    // Packet processing if needed
}

// LidarModule constructor
LidarModule::LidarModule(uint8_t rxPin, uint8_t txPin) 
    : _rxPin(rxPin), _txPin(txPin), _lidarSerial(1) {
    globalLidarModuleInstance = this; // Set the global instance
}

bool LidarModule::begin() {
    
    if (_lidarSerial.setRxBufferSize(2048)) {
        Serial.println(" LiDAR RX buffer increased to 2KB");
    }
_lidarSerial.begin(_lidar.getSerialBaudRate(), SERIAL_8N1, _rxPin, _txPin);
    _lidar.setScanPointCallback(lidar_scan_point_callback);
    _lidar.setPacketCallback(lidar_packet_callback);
    _lidar.setSerialWriteCallback(lidar_serial_write_callback);
    _lidar.setSerialReadCallback(lidar_serial_read_callback);
    _lidar.setInfoCallback(lidar_info_callback);
    _lidar.setErrorCallback(lidar_error_callback);
    
    _lidar.init();
    LDS::result_t result = _lidar.start();
    Serial.printf("LiDAR start result: %s\n", _lidar.resultCodeToString(result).c_str());

    // Initialize scan data array
    for (int i = 0; i < N_DATA_QUADS; ++i) {
        _scanData[i] = 99999.0f;
    }
    
    return result == LDS::RESULT_OK;
}

void LidarModule::loop() {
    _lidar.loop();
}
float normalizeAngleDeg(float angle) {
    while (angle >= 180.0f) angle -= 360.0f;
    while (angle < -180.0f) angle += 360.0f;
    return angle;
}
float LidarModule::getMinDistanceInSector(float centerAngle, float halfAngle) {
    float minDist = 99999.0f;
    int half = (int)halfAngle;
    
    for (int a = -half; a <= half; ++a) {
        int idx = ((int)round(centerAngle + a) % 360 + 360) % 360;
        if (idx >= 0 && idx < N_DATA_QUADS) {
            minDist = min(minDist, _scanData[idx]);
        }
    }
    return minDist;
}
LidarModule::GapInfo LidarModule::findBestGap(float currentTargetAngle, int startAngle, int endAngle, float MIN_SAFE_CLEARANCE_MM, float GAP_SCORE_ANGLE_PENALTY) {
    GapInfo bestGap;
    bestGap.isValid = false;
    float bestGapScore = -99999.0f; 

    // CÁC HẰNG SỐ QUAN TRỌNG (CẦN TÙY CHỈNH)
    const float MAX_OBSTACLE_RANGE_CM = 300.0f; // Ngưỡng coi là vật cản (3m)
    const float DISTANCE_PENALTY_FACTOR = 0.05f; // Phạt nhẹ cho khoảng cách (điểm/mm)
    
    // CÁC HẰNG SỐ ĐÃ SỬA ĐỔI ĐỂ ƯU TIÊN HƯỚNG TARGET
    const float HUGE_ANGLE_PENALTY = 50.0f;    // Tăng trọng số hình phạt góc RẤT LỚN
    const float MIN_GAP_BONUS = 1000.0f;       // Điểm cơ bản để đảm bảo gap có điểm dương
    const float WIDTH_DIVISOR = 10.0f;         // Giảm trọng số chiều rộng (chia 10)

    int startIdx = ((startAngle % N_DATA_QUADS) + N_DATA_QUADS) % N_DATA_QUADS;
    int endIdx = ((endAngle % N_DATA_QUADS) + N_DATA_QUADS) % N_DATA_QUADS;

    bool inGap = false;
    int gapStartEdgeIdx = -1; 

    int loopCount = (endIdx - startIdx + N_DATA_QUADS) % N_DATA_QUADS + 1;

    for (int i = 0; i < loopCount; ++i) { 
        int currentIdx = (startIdx + i) % N_DATA_QUADS;
        
        bool isObstacle = (_scanData[currentIdx] < MAX_OBSTACLE_RANGE_CM && _scanData[currentIdx] > 1.0f);

        if (!isObstacle && inGap) {
            inGap = false;
            int gapEndEdgeIdx = currentIdx; 

            // --- TÍNH TOÁN KHOẢNG TRỐNG ---
            float angle1_rad = gapStartEdgeIdx * DEG_TO_RAD;
            float dist1_mm = _scanData[gapStartEdgeIdx] * 10.0f; 
            float x1 = dist1_mm * cos(angle1_rad);
            float y1 = dist1_mm * sin(angle1_rad);

            float angle2_rad = gapEndEdgeIdx * DEG_TO_RAD;
            float dist2_mm = _scanData[gapEndEdgeIdx] * 10.0f;
            float x2 = dist2_mm * cos(angle2_rad);
            float y2 = dist2_mm * sin(angle2_rad);
            
            float gapWidth_mm = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

            if (gapWidth_mm > MIN_SAFE_CLEARANCE_MM) {
                float centerX = (x1 + x2) / 2.0f;
                float centerY = (y1 + y2) / 2.0f;
                float centerAngle_deg = atan2(centerY, centerX) * RAD_TO_DEG;
                float distToCenter_mm = sqrt(centerX*centerX + centerY*centerY);
                
                // --- LOGIC CHẤM ĐIỂM ƯU TIÊN HƯỚNG TARGET ---
                float angleDiff = abs(normalizeAngleError(centerAngle_deg - currentTargetAngle));
                
                // Score = Bonus + (Width/10) - (AngleDiff * 50) - (Distance * 0.05)
                // Ưu tiên: Góc nhỏ > Rộng > Gần
                float score = MIN_GAP_BONUS                            
                              + (gapWidth_mm / WIDTH_DIVISOR)          
                              - (angleDiff * HUGE_ANGLE_PENALTY)       
                              - (distToCenter_mm * DISTANCE_PENALTY_FACTOR); 

                if (score > bestGapScore) {
                    bestGapScore = score;
                    bestGap.isValid = true;
                    bestGap.angle_deg = centerAngle_deg;
                    bestGap.width_mm = gapWidth_mm;
                    bestGap.distance_to_center_mm = distToCenter_mm;
                }
            }
        } else if (isObstacle && !inGap) {
            inGap = true;
            gapStartEdgeIdx = currentIdx;
        }
    }

    // --- XỬ LÝ KHE HỞ CUỐI CÙNG (NẾU CÓ) ---
    if (inGap) {
        int gapEndEdgeIdx = endIdx; 
        
        float angle1_rad = gapStartEdgeIdx * DEG_TO_RAD;
        float dist1_mm = _scanData[gapStartEdgeIdx] * 10.0f;
        float x1 = dist1_mm * cos(angle1_rad);
        float y1 = dist1_mm * sin(angle1_rad);

        float angle2_rad = gapEndEdgeIdx * DEG_TO_RAD;
        float dist2_mm = _scanData[gapEndEdgeIdx] * 10.0f; 
        
        if (_scanData[gapEndEdgeIdx] > MAX_OBSTACLE_RANGE_CM || _scanData[gapEndEdgeIdx] < 1.0f) {
             dist2_mm = MAX_OBSTACLE_RANGE_CM * 10.0f; 
        }

        float x2 = dist2_mm * cos(angle2_rad);
        float y2 = dist2_mm * sin(angle2_rad);
        
        float gapWidth_mm = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

        if (gapWidth_mm > MIN_SAFE_CLEARANCE_MM) {
            float centerX = (x1 + x2) / 2.0f;
            float centerY = (y1 + y2) / 2.0f;
            float centerAngle_deg = atan2(centerY, centerX) * RAD_TO_DEG;
            float distToCenter_mm = sqrt(centerX*centerX + centerY*centerY);
            
            float angleDiff = abs(normalizeAngleError(centerAngle_deg - currentTargetAngle));
            
            float score = MIN_GAP_BONUS 
                          + (gapWidth_mm / WIDTH_DIVISOR)
                          - (angleDiff * HUGE_ANGLE_PENALTY) 
                          - (distToCenter_mm * DISTANCE_PENALTY_FACTOR); 

            if (score > bestGapScore) {
                bestGap.isValid = true;
                bestGap.angle_deg = centerAngle_deg;
                bestGap.width_mm = gapWidth_mm;
                bestGap.distance_to_center_mm = distToCenter_mm;
            }
        }
    }

    return bestGap;
}
bool LidarModule::isPathClear(float angle, float distance) {
    return getMinDistanceInSector(0.0f, angle) > distance;
}

float* LidarModule::getScanData() {
    return _scanData;
}

