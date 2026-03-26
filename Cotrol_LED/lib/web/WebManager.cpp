#include "WebManager.h"

WebManager::WebManager(uint16_t port)
    : _server(port), _ws("/ws") {}

bool WebManager::begin(const char *ssid, const char *password)
{
    if (!LittleFS.begin(true))
        return false;
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(_apIP, _apIP, _mask);
    WiFi.softAP(ssid, password);

    _dns.start(53, "*", _apIP);

    _ws.onEvent([this](AsyncWebSocket *s,
                       AsyncWebSocketClient *c,
                       AwsEventType t,
                       void *arg,
                       uint8_t *d,
                       size_t l)
                { _onWsEvent(s, c, t, arg, d, l); });

    _server.addHandler(&_ws);
    _setupCaptivePortal();
    _server.begin();

    return true;
}

void WebManager::_setupCaptivePortal()
{
    _server.serveStatic("/", LittleFS, "/");

    _server.onNotFound(
        [](AsyncWebServerRequest *r)
        {
            r->send(LittleFS, "/index.html", "text/html");
        });
}
void WebManager::_onWsEvent(AsyncWebSocket *,
                            AsyncWebSocketClient *,
                            AwsEventType type,
                            void *,
                            uint8_t *data,
                            size_t len)
{
    switch (type)
    {
    case WS_EVT_DATA:
    {
        String msg;
        msg.reserve(len);

        for (size_t i = 0; i < len; i++)
        {
            msg += (char)data[i];
        }

        if (_rawCb)
        {
            _rawCb(msg.c_str());
        }
    }
    break;
    case WS_EVT_CONNECT:
        printf("WS CONNECTED\n");
        break;
    case WS_EVT_DISCONNECT:
        printf("WS DIS_CONNECTED\n");
        break;
    default:
        break;
    }
}

void WebManager::broadcast(const char *message)
{
    _ws.textAll(message);
}

void WebManager::onRawMessage(RawWsCallback cb)
{
    _rawCb = cb;
}

void WebManager::update()
{
    _dns.processNextRequest();
    _ws.cleanupClients();
}
