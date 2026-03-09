#include "RFIDManager.h"

RFIDManager::RFIDManager(uint8_t ssPin, uint8_t rstPin)
    : mfrc522(ssPin, rstPin),
      _ssPin(ssPin), _rstPin(rstPin),
      _useCustomSPI(false),
      _state(RFIDState::WAIT_CARD) {}

RFIDManager::RFIDManager(uint8_t ssPin, uint8_t rstPin,
                         uint8_t sckPin, uint8_t misoPin, uint8_t mosiPin)
    : mfrc522(ssPin, rstPin),
      _ssPin(ssPin), _rstPin(rstPin),
      _sckPin(sckPin), _misoPin(misoPin), _mosiPin(mosiPin),
      _useCustomSPI(true),
      _state(RFIDState::WAIT_CARD) {}

bool RFIDManager::begin()
{
    if (_useCustomSPI)
    {
#if defined(ESP32)
        SPI.begin(_sckPin, _misoPin, _mosiPin, _ssPin);
#else
        SPI.begin();
#endif
    }
    else
    {
        SPI.begin();
    }

    mfrc522.PCD_Init();
    byte v = mfrc522.PCD_ReadRegister(MFRC522::VersionReg);
    return !(v == 0x00 || v == 0xFF);
}

/* ================= FSM ================= */

void RFIDManager::startScan()
{
    if (_state != RFIDState::IDLE)
        return;

    _uid = "";
    _state = RFIDState::WAIT_CARD;
    _startTick = millis();
    emit("start");
}

void RFIDManager::reScan()
{
    _state = RFIDState::IDLE;
    RFIDManager::startScan();
}

void RFIDManager::idle()
{
    _uid = "";
    _state = RFIDState::IDLE;
}

void RFIDManager::update()
{
    if (_state == RFIDState::WAIT_CARD)
    {

        // if (millis() - _startTick > TIMEOUT)
        // {
        //     emit("timeout");
        //     _state = RFIDState::IDLE;
        //     return;
        // }

        if (!mfrc522.PICC_IsNewCardPresent())
            return;
        if (!mfrc522.PICC_ReadCardSerial())
            return;

        _uid = "";
        for (byte i = 0; i < mfrc522.uid.size; i++)
        {
            if (mfrc522.uid.uidByte[i] < 0x10)
                _uid += "0";
            _uid += String(mfrc522.uid.uidByte[i], HEX);
        }
        _uid.toUpperCase();

        mfrc522.PICC_HaltA();
        mfrc522.PCD_StopCrypto1();

        emit("detected");
        _state = RFIDState::CARD_READ;
    }
}

int8_t RFIDManager::authorize(const String &nameSpace)
{
    // Chưa quét thẻ thì không authorize
    if (_uid.isEmpty())
        return -1;

    prefs.begin(nameSpace.c_str(), true);

    for (int id = 1; id <= 100; id++)
    {
        char keyUid[20];
        sprintf(keyUid, "user_%d_uid", id);

        if (!prefs.isKey(keyUid))
            continue;

        String savedUID = prefs.getString(keyUid);

        if (savedUID == _uid)
        {
            prefs.end();
            return id;  
        }
    }
    prefs.end();
    return -1;    
}


void RFIDManager::onEvent(RFIDEventCallback cb)
{
    _cb = cb;
}

void RFIDManager::emit(const char *event)
{
    if (_cb)
        _cb(event, _uid);
}
