#ifndef RFID_MANAGER_H
#define RFID_MANAGER_H

#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <functional>
#include <Preferences.h>

enum class RFIDState
{
    IDLE,
    WAIT_CARD,
    CARD_READ,
    ERROR
};

using RFIDEventCallback = std::function<void(const char *event, const String &uid)>;

class RFIDManager
{
public:
    RFIDManager(uint8_t ssPin, uint8_t rstPin);
    RFIDManager(uint8_t ssPin, uint8_t rstPin,
                uint8_t sckPin, uint8_t misoPin, uint8_t mosiPin);

    bool begin();

    /* ===== FSM API ===== */
    void startScan();
    void reScan();
    void idle();
    void update();

    int8_t authorize(const String &nameSpace);

    void onEvent(RFIDEventCallback cb);

    RFIDState state() const { return _state; }

private:
    MFRC522 mfrc522;
    Preferences prefs;

    bool _useCustomSPI;
    uint8_t _ssPin, _rstPin, _sckPin, _misoPin, _mosiPin;

    RFIDState _state;
    unsigned long _startTick;
    static constexpr uint32_t TIMEOUT = 10000;

    String _uid;
    RFIDEventCallback _cb;

    void emit(const char *event);
};

#endif
