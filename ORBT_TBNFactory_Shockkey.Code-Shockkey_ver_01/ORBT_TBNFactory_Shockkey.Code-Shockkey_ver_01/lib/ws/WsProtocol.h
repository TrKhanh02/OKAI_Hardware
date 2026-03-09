#ifndef WS_PROTOCOL_H
#define WS_PROTOCOL_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <functional>
#include "WebManager.h"

/* ================= TYPE ================= */
#define TYPE_COMMAND "command"
#define TYPE_EVENT "event"
#define TYPE_RESPONSE "response"
#define TYPE_SYNC "sync"
#define TYPE_UNKNOWN "unknown"

/* ================= ACTION ================= */
#define ACTION_FINGERPRINT "fingerprint"
#define ACTION_RFID "rfid"
#define ACTION_SYNC "sync"
#define ACTION_DELETE "delete"

/* ================= COMMAND ENUM ================= */
enum class WsCommandType
{
    UNKNOWN,
    FINGERPRINT,
    RFID,
    SAVE,
    DELETE,
    SYNC
};

/* ================= COMMAND ================= */
struct WsCommand
{
    WsCommandType type;
    const char *cmd;  // payload.cmd
    const char *uid;  // payload.uid
    const char *name; // payload.name
    uint8_t fid;      // payload.fid
    uint8_t id;   // payload.id
    bool isAdmin;     // payload.isAdmin
    JsonObject payload;
};

using PayloadBuilder = std::function<void(JsonObject)>;

class WsProtocol
{
public:
    explicit WsProtocol(WebManager *web);

    /* ===== ESP → CLIENT ===== */
    void send(
        const char *type,
        const char *action,
        PayloadBuilder builder = nullptr);

    /* ===== CLIENT → ESP ===== */
    bool parse(const char *json, WsCommand &out);

private:
    WebManager *_web;
    JsonDocument _txDoc;
    JsonDocument _rxDoc;

    WsCommandType _parseAction(const char *action);
};

#endif
