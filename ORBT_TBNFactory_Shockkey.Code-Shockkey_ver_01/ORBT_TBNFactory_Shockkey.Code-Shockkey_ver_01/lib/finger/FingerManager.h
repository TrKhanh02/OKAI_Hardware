#ifndef FINGER_MANAGER_H
#define FINGER_MANAGER_H

#include <Arduino.h>
#include <Adafruit_Fingerprint.h>
#include <functional>

/* ================= LED DEFINE ================= */
#define R588S_LED_BREATHING 0x01
#define R588S_LED_FLASHING 0x02
#define R588S_LED_ON 0x03
#define R588S_LED_OFF 0x04
#define R588S_LED_GRADUAL_ON 0x05
#define R588S_LED_GRADUAL_OFF 0x06

#define R588S_LED_RED 0x01
#define R588S_LED_BLUE 0x02
#define R588S_LED_PURPLE 0x03

/* ================= CALLBACK ================= */
/*
 state:
   "start"
   "scanning"
   "ready"
   "error"
*/
using FingerEventCallback = std::function<void(
    const char *state,
    uint8_t step,
    uint8_t total)>;

/* ================= FSM STATE ================= */
enum class FingerState
{
    IDLE,
    WAIT_FINGER,
    CAPTURE,
    STEP_DONE,
    MODEL_READY,
    WAIT_REMOVE,
    SAVING,
    ERROR
};

class FingerManager
{
public:
    explicit FingerManager(HardwareSerial *serial);

    bool begin(uint32_t baud = 57600);

    /* ===== FSM CONTROL ===== */
    void update();

    uint8_t getFingerprintID();

    void startScan(); // client gửi lệnh QUÉT
    void reScan();
    void idle();
    bool isReadyToSave() const;
    int saveFingerprint(uint16_t id); // client gửi lệnh LƯU

    /* ===== CALLBACK ===== */
    void onEvent(FingerEventCallback cb);

    /* ===== DATABASE ===== */
    bool deleteFingerprint(uint16_t id);
    void clearAll();
    uint16_t getTemplateCount();

    /* ===== LED ===== */
    void setLED(uint8_t mode, uint8_t speed, uint8_t color, uint8_t cycles = 0);
    void ledStandby();
    void ledSuccess();
    void ledError();

private:
    /* ===== INTERNAL ===== */
    Adafruit_Fingerprint _finger;
    HardwareSerial *_serial;

    FingerState _state;
    uint8_t _step = 1;
    static const uint8_t TOTAL_STEP = 4;
    unsigned long _removeTick = 0;
    static constexpr uint16_t REMOVE_DELAY = 100; // ms

    FingerEventCallback _cb;

    void emit(const char *state);
};

#endif
