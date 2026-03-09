#include "WsProtocol.h"

WsProtocol::WsProtocol(WebManager* web)
    : _web(web) {}

/* ================= ESP → CLIENT ================= */

void WsProtocol::send(
    const char* type,
    const char* action,
    PayloadBuilder builder
) {
    _txDoc.clear();

    _txDoc["from"]   = "esp32";
    _txDoc["type"]   = type;
    _txDoc["action"] = action;

    if (builder) {
        JsonObject payload = _txDoc["payload"].to<JsonObject>();
        builder(payload);
    }

    char buf[256];
    serializeJson(_txDoc, buf);
    //printf("[WS TX] %s\n", buf);
    _web->broadcast(buf);
}

/* ================= CLIENT → ESP ================= */

bool WsProtocol::parse(const char* json, WsCommand& out)
{
    _rxDoc.clear();

    if (deserializeJson(_rxDoc, json)) return false;

    const char* from = _rxDoc["from"];
    if (!from || strcmp(from, "client") != 0)
        return false;

    const char* type = _rxDoc["type"];
    if (!type)
        return false;

    if (strcmp(type, TYPE_COMMAND) != 0 &&
        strcmp(type, TYPE_SYNC)    != 0 &&
        strcmp(type, TYPE_EVENT)   != 0 &&
        strcmp(type, TYPE_RESPONSE) != 0)
        return false;

    const char* action = _rxDoc["action"];
    if (!action)
        return false;

    JsonObject payload = _rxDoc["payload"].is<JsonObject>()
                       ? _rxDoc["payload"].as<JsonObject>()
                       : JsonObject();

    out.type    = _parseAction(action);
    out.cmd     = payload["cmd"] | "";
    out.uid     = payload["uid"] | "";
    out.name    = payload["name"] | "";
    out.fid     = payload["fid"] | 0;
    out.id      = payload["id"] | 0;
    out.isAdmin = payload["isAdmin"] | false;
    out.payload = payload;

    return out.type != WsCommandType::UNKNOWN;
}


WsCommandType WsProtocol::_parseAction(const char* action)
{
    if (!strcmp(action, ACTION_FINGERPRINT))
        return WsCommandType::FINGERPRINT;

    if (!strcmp(action, ACTION_RFID))
        return WsCommandType::RFID;

    if (!strcmp(action, ACTION_SYNC))
        return WsCommandType::SYNC;

    if (!strcmp(action, ACTION_DELETE))
        return WsCommandType::DELETE;

    return WsCommandType::UNKNOWN;
}
