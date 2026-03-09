#ifndef LIDAR_MODULE_H
#define LIDAR_MODULE_H

#include <Arduino.h>
#include <LDS_LDROBOT_LD14P.h>

#define N_DATA_QUADS 360

class LidarModule {
public:
    LidarModule(uint8_t rxPin, uint8_t txPin);
    bool begin();
    void loop();
    float getMinDistanceInSector(float centerAngle, float halfAngle);
    bool isPathClear(float angle, float distance);
    float* getScanData();

    struct GapInfo {
    bool isValid = false;
    float angle_deg = 0.0f;
    float width_mm = 0.0f;
    float distance_to_center_mm = 0.0f;
};

GapInfo findBestGap(float currentTargetAngle, int startAngle, int endAngle, float MIN_SAFE_CLEARANCE_MM, float GAP_SCORE_ANGLE_PENALTY);
    uint8_t _rxPin;
    uint8_t _txPin;
    HardwareSerial _lidarSerial;
    LDS_LDROBOT_LD14P _lidar;
    float _scanData[N_DATA_QUADS];

    // Static callback functions for C-style API
    static int lidar_serial_read_callback();
    static size_t lidar_serial_write_callback(const uint8_t* buffer, size_t length);
    static void lidar_scan_point_callback(float angle_deg, float distance_mm, float quality, bool scan_completed);
    static void lidar_info_callback(LDS::info_t code, String info);
    static void lidar_error_callback(LDS::result_t code, String aux_info);
    static void lidar_packet_callback(uint8_t* packet, uint16_t length, bool scan_completed);
};

// Global instance and data for callbacks
extern LidarModule* globalLidarModuleInstance;

#endif