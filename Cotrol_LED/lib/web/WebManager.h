#ifndef WEB_MANAGER_H
#define WEB_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include <LittleFS.h>
#include <functional>

class WebManager {
public:
    using RawWsCallback = std::function<void(const char* msg)>;

    explicit WebManager(uint16_t port = 80);

    bool begin(const char* ssid, const char* password);
    void update();

    /* ===== WebSocket ===== */
    void broadcast(const char* message);
    void onRawMessage(RawWsCallback cb);

private:
    AsyncWebServer  _server;
    AsyncWebSocket  _ws;
    DNSServer       _dns;

    RawWsCallback   _rawCb;

    const IPAddress _apIP   = IPAddress(192, 168, 4, 1);
    const IPAddress _mask   = IPAddress(255, 255, 255, 0);

    void _setupCaptivePortal();
    void _onWsEvent(AsyncWebSocket* server,
                    AsyncWebSocketClient* client,
                    AwsEventType type,
                    void* arg,
                    uint8_t* data,
                    size_t len);
};

#endif
