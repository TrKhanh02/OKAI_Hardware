#define runMain 1

#if runMain == 1
#include <Arduino.h>
#include <stdio.h>
#include <FingerManager.h>
#include <RFIDManager.h>
#include <WebManager.h>
#include <WsProtocol.h>
#include <ArduinoJson.h>
#include <Preferences.h>

#define R588S_RX_PIN 18
#define R588S_TX_PIN 19

#define RST_PIN 27   // Configurable, see typical pin layout above
#define MISO_PIN 26 // Configurable, see typical pin layout above
#define MOSI_PIN 25 // Configurable, see typical pin layout above
#define SCK_PIN 33  // Configurable, see typical pin layout above
#define SS_PIN 32   // Configurable, see typical pin layout above

#define Relay_1 21 // Tải to
#define Relay_2 22 // Tải to
#define Relay_3 23 // Tải nhỏ
#define Relay_4 4  // Còi



// #define R588S_RX_PIN 16
// #define R588S_TX_PIN 17

// #define RST_PIN 9   // Configurable, see typical pin layout above
// #define MISO_PIN 10 // Configurable, see typical pin layout above
// #define MOSI_PIN 11 // Configurable, see typical pin layout above
// #define SCK_PIN 12  // Configurable, see typical pin layout above
// #define SS_PIN 13   // Configurable, see typical pin layout above



boolean flagR1 = 0;
boolean flagR2 = 0;
boolean flagR3 = 0;
boolean flagR4 = 0;

FingerManager myR588S(&Serial2);
Preferences store;
RFIDManager myRC522(SS_PIN, RST_PIN, SCK_PIN, MISO_PIN, MOSI_PIN);
WebManager myWeb;
WsProtocol myWsProtocol(&myWeb);

JsonDocument doc;

uint32_t timerPre = 0;

/* Callback functions */
void handleWebSocketMessage(const char *msg)
{
  // printf("[WS RX] %s\n", msg);
  WsCommand command;
  /* ===============Parse the command=============== */
  if (!myWsProtocol.parse(msg, command))
  {
    myWsProtocol.send(
        TYPE_RESPONSE,
        "error",
        [](JsonObject payload)
        {
          payload["code"] = 400;
          payload["message"] = "Invalid command format";
        });
    return;
  }

  /* ================= FINGERPRINT ================= */
  if (command.type == WsCommandType::FINGERPRINT)
  {
    if (!strcmp(command.cmd, "start"))
    {
      myR588S.startScan();
      myWsProtocol.send(
          TYPE_RESPONSE,
          ACTION_FINGERPRINT,
          [](JsonObject payload)
          {
            payload["status"] = "enroll_started";
          });
      return;
    }

    if (!strcmp(command.cmd, "rescan"))
    {
      myR588S.reScan();
      myWsProtocol.send(
          TYPE_RESPONSE,
          ACTION_FINGERPRINT,
          [](JsonObject payload)
          {
            payload["status"] = "scan_reload";
          });
      return;
    }

    if (!strcmp(command.cmd, "save"))
    {
      store.begin("users", false);
      if (command.id == 0 || !myR588S.isReadyToSave())
      {
        String errorMsg = "";
        command.id == 0 ? errorMsg += "Missing ID. " : errorMsg += "";
        !myR588S.isReadyToSave() ? errorMsg += "Fingerprint not ready to save." : errorMsg += "";
        command.fid == 0 ? errorMsg += "Missing FID. " : errorMsg += "";
        myWsProtocol.send(
            TYPE_RESPONSE,
            ACTION_FINGERPRINT,
            [errorMsg](JsonObject payload)
            {
              payload["status"] = "error";
              payload["message"] = errorMsg;
            });
        store.end();
        return;
      }
      uint8_t fid = command.fid;
      uint8_t id = command.id;
      String fidKey = "user_" + String(id) + "_fid";
      myR588S.saveFingerprint(fid);
      store.putUInt(fidKey.c_str(), fid); // Lưu mapping id -> fid vào Preferences
      uint8_t savedFid = store.getUInt(fidKey.c_str(), 0);
      myWsProtocol.send(
          TYPE_RESPONSE,
          ACTION_FINGERPRINT,
          [&](JsonObject payload)
          {
            payload["status"] = "saved";
            payload["key:"] = fidKey;
            payload["value:"] = savedFid;
          });
      store.end();
      return;
    }

    if (!strcmp(command.cmd, "idle"))
    {
      myR588S.idle();
      myWsProtocol.send(
          TYPE_RESPONSE,
          ACTION_FINGERPRINT,
          [](JsonObject payload)
          {
            payload["status"] = "idle";
          });
      return;
    }
  }

  /* ================= RFID ================= */
  if (command.type == WsCommandType::RFID)
  {
    if (!strcmp(command.cmd, "start"))
    {
      myRC522.startScan();
      myWsProtocol.send(
          TYPE_RESPONSE,
          ACTION_RFID,
          [](JsonObject payload)
          {
            payload["status"] = "scan_started";
          });
      return;
    }

    if (!strcmp(command.cmd, "rescan"))
    {
      myRC522.reScan();
      // myRC522.startScan();
      myWsProtocol.send(
          TYPE_RESPONSE,
          ACTION_RFID,
          [](JsonObject payload)
          {
            payload["status"] = "scan_reload";
          });
      return;
    }

    if (!strcmp(command.cmd, "save"))
    {
      store.begin("users", false);
      String missingField = "";
      if (command.id == 0 || command.uid == "" || command.name == "")
      {
        command.id == 0 ? missingField += "id " : missingField += "";
        command.uid == "" ? missingField += "uid " : missingField += "";
        command.name == "" ? missingField += "name " : missingField += "";
        missingField = missingField + "field(s) missing";
        myWsProtocol.send(
            TYPE_RESPONSE,
            ACTION_RFID,
            [missingField](JsonObject payload)
            {
              payload["status"] = "error";
              payload["message"] = missingField;
            });
        store.end();
        return;
      }

      uint8_t id = command.id;
      String name = command.name;
      String uid = command.uid;
      bool isAdmin = command.isAdmin;
      isAdmin ? Serial.println("isAdmi: true") : Serial.println("isAdmin: false");

      String nameKey = "user_" + String(id) + "_name";
      String uidKey = "user_" + String(id) + "_uid";
      String isAdminKey = "user_" + String(id) + "_isAdmin";

      store.putString(nameKey.c_str(), String(name)); // Lưu mapping id -> name vào Preferences
      store.putString(uidKey.c_str(), String(uid));   // Lưu mapping id -> uid vào Preferences
      store.putBool(isAdminKey.c_str(), isAdmin);     // Lưu mapping id -> isAdmin vào Preferences

      String savedUid = store.getString(uidKey.c_str(), "");
      Serial.println("Saved UID: " + savedUid);
      String savedName = store.getString(nameKey.c_str(), "");
      Serial.println("Saved Name: " + savedName);
      bool savedisAdmin = store.getBool(isAdminKey.c_str(), false);
      Serial.printf("Saved isAdmin: %s\n", savedisAdmin ? "true" : "false");
      myWsProtocol.send(
          TYPE_RESPONSE,
          ACTION_RFID,
          [&](JsonObject payload)
          {
            payload["status"] = "saved";
            payload["uid_key"] = uidKey;
            payload["uid_value"] = savedUid;
            payload["name_key"] = nameKey;
            payload["name_value"] = savedName;
            payload["isAdmin_key"] = isAdminKey;
            payload["isAdmin_value"] = savedisAdmin;
          });
      store.end();
      return;
    }

    if (!strcmp(command.cmd, "idle"))
    {
      myRC522.idle();
      // myRC522.startScan();
      myWsProtocol.send(
          TYPE_RESPONSE,
          ACTION_RFID,
          [](JsonObject payload)
          {
            payload["status"] = "idle";
          });
      return;
    }
  }

  /* ================= SYNC ================= */
  if (command.type == WsCommandType::SYNC)
  {
    if (strcmp(command.cmd, "users") != 0)
    {
      myWsProtocol.send(TYPE_RESPONSE, "error", [](JsonObject payload)
                        {
            payload["code"] = 400;
            payload["message"] = "Invalid sync action"; });
      return;
    }
    store.begin("users", true);

    myWsProtocol.send(TYPE_SYNC, "users", [](JsonObject p)
                      { p["status"] = "start"; });

    for (int id = 1; id <= 100; id++)
    {
      String keyUid = "user_" + String(id) + "_uid";
      String keyName = "user_" + String(id) + "_name";
      String keyFid = "user_" + String(id) + "_fid";
      String keyAdmin = "user_" + String(id) + "_isAdmin";

      if (!store.isKey(keyUid.c_str()))
        continue;

      String uidvalue = store.getString(keyUid.c_str(), "");
      String namevalue = store.getString(keyName.c_str(), "");
      int8_t fidvalue = store.getUInt(keyFid.c_str(), 0);
      bool isAdminValue = store.getBool(keyAdmin.c_str(), false);
      // printf("Syncing User ID %d: UID=%s, Name=%s, FID=%d, isAdmin=%s\n",
      //        id, uidvalue.c_str(), namevalue.c_str(), fidvalue,
      //        isAdminValue ? "true" : "false");
      myWsProtocol.send(TYPE_SYNC, "user", [&](JsonObject payload)
                        {
    payload["id"] = id;
    payload["uid"] = uidvalue;
    payload["name"] = namevalue;
    payload["fid"] = fidvalue;
    payload["isAdmin"] = isAdminValue; });

      delay(5);
    }

    myWsProtocol.send(TYPE_SYNC, "users", [](JsonObject p)
                      { p["status"] = "end"; });

    store.end();
    return;
  }

  /* ================= DELETE ================= */
  if (command.type == WsCommandType::DELETE)
  {
    uint8_t id = command.id;
    store.begin("users", false);
    String nameKey = "user_" + String(id) + "_name";
    String uidKey = "user_" + String(id) + "_uid";
    String fidKey = "user_" + String(id) + "_fid";
    String isAdminKey = "user_" + String(id) + "_isAdmin";
    store.remove(nameKey.c_str()) ? Serial.printf("remove name id %d ok!\n", id) : Serial.printf("remove name id %d error\n", id);
    store.remove(uidKey.c_str()) ? Serial.printf("remove uid id %d ok!\n", id) : Serial.printf("remove uid id %d error\n", id);
    store.remove(fidKey.c_str()) ? Serial.printf("remove fid id %d ok!\n", id) : Serial.printf("remove fid id %d error\n", id);
    store.remove(isAdminKey.c_str()) ? Serial.printf("remove admin id %d ok!\n", id) : Serial.printf("remove admin id %d error\n", id);
  }

  /* ================= UNKNOWN ================= */
  if (command.type == WsCommandType::UNKNOWN)
  {
    printf("Unknown command type received.\n");
    myWsProtocol.send(
        TYPE_RESPONSE,
        "error",
        [](JsonObject payload)
        {
          payload["code"] = 404;
          payload["message"] = "Unknown command type";
        });
  }
}

// Hàm xử lý sự kiện vân tay (Callback)
void handleFingerprintEvent(const char *state, uint8_t step, uint8_t total)
{
  // Giả định 'myWsProtocol' hoặc 'ws' là biến toàn cục
  myWsProtocol.send(TYPE_EVENT, ACTION_FINGERPRINT, [state, step, total](JsonObject p)
                    {
        p["state"] = state;

        // Nếu đang trong trạng thái quét, gửi thêm thông tin tiến trình
        if (strcmp(state, "scanning") == 0) {
            p["step"]  = step;
            p["total"] = total;
        } });

  // Log ra Serial để dễ debug
  printf("[FINGER] State: %s, Step: %d/%d\n", state, step, total);
}

// Hàm xử lý sự kiện RFID (Callback)
void handleRfidEvent(const char *event, const String &uid)
{
  myWsProtocol.send(
      TYPE_EVENT,
      ACTION_RFID,
      [event, uid](JsonObject payload)
      {
        payload["state"] = event;

        // Kiểm tra nếu UID không rỗng thì mới thêm vào JSON
        if (uid.length() > 0)
        {
          payload["uid"] = uid;
        }
      });

  // Debug log
  printf("[RFID] Event: %s, UID: %s\n", event, uid.c_str());
}

void setup()
{
  Serial.begin(115200);
  Serial2.begin(57600, SERIAL_8N1, R588S_RX_PIN, R588S_TX_PIN);
  myRC522.begin();
  myR588S.begin();
  myWeb.begin("OKAI HE HE HE", NULL) ? printf("Web system san sang!") : printf("Loi khoi tao Web system!");
  myWeb.onRawMessage(handleWebSocketMessage);
  myR588S.onEvent(handleFingerprintEvent);
  myRC522.onEvent(handleRfidEvent);

  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  pinMode(Relay_4, OUTPUT);

  // store.begin("users", true);
  // String value1 = store.getString("user_1_uid","error");
  // Serial.printf("UID1: %s", value1);

  // store.begin("users", true);
  // String value2 = store.getString("user_2_uid","error");
  // Serial.printf("UID2: %s", value2);
}

void loop()
{
  myWeb.update();
  myR588S.update();
  myRC522.update();

  // Serial.printf("AP: %d \n", WiFi.softAPgetStationNum());

  if (WiFi.softAPgetStationNum() == 0)
  {
    if (myR588S.getFingerprintID() != 255)
    {
      digitalWrite(Relay_1, HIGH);
      digitalWrite(Relay_2, HIGH);
      Serial.println("ON thiết bị");
    }
    if (myRC522.state() == RFIDState::CARD_READ)
    {
      int userId = myRC522.authorize("users");

      if (userId > 0)
      {
        digitalWrite(Relay_1, HIGH);
        digitalWrite(Relay_2, HIGH);
      }
      myRC522.idle();
      myRC522.startScan();
    }
  }
  else{
    digitalWrite(Relay_1, LOW);
    digitalWrite(Relay_2, LOW);
    digitalWrite(Relay_3, LOW);
    digitalWrite(Relay_4, LOW);
  }
}

#elif runMain == 2

#include <Arduino.h>

#include <nvs_flash.h>
#include <nvs.h>
#include <Preferences.h>

void printAllInNamespace(const char *ns_name)
{
  printf("--- Đang quét toàn bộ nội dung trong namespace: %s ---\n", ns_name);

  // 1. Khởi tạo iterator để duyệt qua phân vùng "nvs"
  // Lọc theo tên namespace cụ thể
  nvs_iterator_t it = nvs_entry_find("nvs", ns_name, NVS_TYPE_ANY);

  if (it == NULL)
  {
    printf("Namespace trống hoặc không tồn tại.\n");
    return;
  }

  Preferences prefs;
  prefs.begin(ns_name, true); // Mở để đọc giá trị

  do
  {
    nvs_entry_info_t info;
    nvs_entry_info(it, &info); // Lấy thông tin về Key hiện tại

    printf("Key: %-15s | Type: ", info.key);

    // 2. Dựa vào kiểu dữ liệu (info.type) để gọi hàm get tương ứng
    switch (info.type)
    {
    case NVS_TYPE_I8:
      printf("(Int8): %d\n", prefs.getChar(info.key));
      break;
    case NVS_TYPE_U8:
      printf("(Uint8/Bool): %d\n", prefs.getUChar(info.key));
      break;
    case NVS_TYPE_I16:
      printf("(Int16): %d\n", prefs.getShort(info.key));
      break;
    case NVS_TYPE_U16:
      printf("(Uint16): %d\n", prefs.getUShort(info.key));
      break;
    case NVS_TYPE_I32:
      printf("(Int32): %d\n", prefs.getInt(info.key));
      break;
    case NVS_TYPE_U32:
      printf("(Uint32): %u\n", prefs.getUInt(info.key));
      break;
    case NVS_TYPE_STR:
      printf("(String): %s\n", prefs.getString(info.key).c_str());
      break;
    case NVS_TYPE_BLOB:
      printf("(Blob): Kích thước %d bytes\n", prefs.getBytesLength(info.key));
      break;
    default:
      printf("(Khác): Type %d\n", info.type);
      break;
    }

    it = nvs_entry_next(it); // Chuyển sang Key tiếp theo
  } while (it != NULL);

  prefs.end();
  nvs_release_iterator(it);
  printf("--- Kết thúc quét ---\n");
}

void setup()
{
  Serial.begin(115200);
  delay(1000);

  // Gọi hàm để xem toàn bộ nội dung của namespace "users"
  printAllInNamespace("users");
}

void loop() {}

#else
#include <Arduino.h>
#include "WebManager.h"
#include "WsProtocol.h"
#include "FingerManager.h"

/* ================= HARDWARE ================= */
#define FP_RX 16
#define FP_TX 17

HardwareSerial FingerSerial(2);

/* ================= OBJECT ================= */
WebManager web;
WsProtocol ws(&web);
FingerManager finger(&FingerSerial);

/* ================= WEBSOCKET RX ================= */
void onWsMessage(const char *msg)
{
  WsCommand cmd;

  if (!ws.parse(msg, cmd))
    return;

  if (cmd.type == WsCommandType::FINGERPRINT)
  {

    if (!strcmp(cmd.cmd, "start"))
    {
      finger.startScan();
    }

    else if (!strcmp(cmd.cmd, "save"))
    {
      uint16_t id = cmd.payload["id"];
      finger.saveFingerprint(id);
    }
  }
}

/* ================= SETUP ================= */
void setup()
{
  Serial.begin(115200);

  /* Fingerprint UART */
  FingerSerial.begin(57600, SERIAL_8N1, FP_RX, FP_TX);

  /* WebSocket */
  web.begin();
  web.onMessage(onWsMessage);

  /* Fingerprint */
  if (!finger.begin())
  {
    Serial.println("Fingerprint init FAILED");
  }

  /* Finger FSM → WebSocket EVENT */
  finger.onEvent([&](const char *state, uint8_t step, uint8_t total)
                 { ws.send(TYPE_EVENT, ACTION_FINGERPRINT, [&](JsonObject p)
                           {
            p["state"] = state;

            if (!strcmp(state, "scanning")) {
                p["step"]  = step;
                p["total"] = total;
            } }); });

  Serial.println("System READY");
}

/* ================= LOOP ================= */
void loop()
{
  web.loop();      // WebSocket
  finger.update(); // FSM vân tay
}

#endif