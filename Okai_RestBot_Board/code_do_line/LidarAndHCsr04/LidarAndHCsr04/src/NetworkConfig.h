#ifndef NETWORK_CONFIG_H
#define NETWORK_CONFIG_H

class NetworkConfig {
public:
    // --- THÔNG TIN WIFI ---
    static constexpr const char* WIFI_SSID = "OKAI";          // Đã thêm const
    static constexpr const char* WIFI_PASS = "Okai@101025";   // Đã thêm const

    // --- THÔNG TIN HIVEMQ CLOUD ---
    static constexpr const char* MQTT_SERVER = "30880ddfcad24790a2ee4e55cd1e3b48.s1.eu.hivemq.cloud";
    static constexpr int   MQTT_PORT = 8883; 
    
    static constexpr const char* MQTT_USER = "robot1";        // Đã thêm const
    static constexpr const char* MQTT_PASS = "Robot@2025";    // Đã thêm const

    static constexpr const char* MQTT_TOPIC_DATA = "myrobot/telemetry"; // Đã thêm const
};

#endif