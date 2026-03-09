#include "FingerManager.h"

// Đặt là 1 để bật debug, 0 để tắt
#define FINGER_DEBUG 1

FingerManager::FingerManager(HardwareSerial *serial)
    : _finger(serial),
      _serial(serial),
      _state(FingerState::IDLE),
      _step(0) {}

bool FingerManager::begin(uint32_t baud)
{
    _serial->begin(baud);

#if FINGER_DEBUG
    printf("[FingerManager] Đang khởi tạo...\n");
#endif

    if (_finger.verifyPassword())
    {
#if FINGER_DEBUG
        printf("[FingerManager] Kết nối cảm biến THÀNH CÔNG.\n");
#endif
        ledStandby();
        return true;
    }

#if FINGER_DEBUG
    printf("[FingerManager] LỖI: Không tìm thấy cảm biến vân tay!\n");
#endif
    return false;
}

/* ================= CALLBACK ================= */

void FingerManager::onEvent(FingerEventCallback cb)
{
    _cb = cb;
}

void FingerManager::emit(const char *state)
{
#if FINGER_DEBUG
    printf("[Event] Emit: ");
    printf(state);
    printf(" | Step: ");
    printf("%d\n", _step);
#endif

    if (_cb)
        _cb(state, _step, TOTAL_STEP);
}

/* ================= FSM API ================= */

void FingerManager::startScan()
{
    if (_state != FingerState::IDLE)
        return;

#if FINGER_DEBUG
    printf("[FingerManager] Bắt đầu quét vân tay mới...\n");
#endif

    _step = 1;
    _state = FingerState::WAIT_FINGER;

    setLED(R588S_LED_BREATHING, 30, R588S_LED_BLUE);
    emit("start");
}

void FingerManager::idle()
{
    _state = FingerState::IDLE;
}

void FingerManager::reScan()
{
    _state = FingerState::IDLE;
    _step = 1;
    // FingerManager::startScan();
}

bool FingerManager::isReadyToSave() const
{
    return _state == FingerState::MODEL_READY;
}

int FingerManager::saveFingerprint(uint16_t id)
{
    if (_state != FingerState::MODEL_READY)
    {
#if FINGER_DEBUG
        printf("[FingerManager] Lỗi: Chưa có Model vân tay sẵn sàng để lưu!\n");
#endif
        return FINGERPRINT_FLASHERR;
    }

#if FINGER_DEBUG
    printf("[FingerManager] Đang lưu vào bộ nhớ ID: ");
    printf("%d \n", id);
#endif

    _state = FingerState::SAVING;

    int p = _finger.storeModel(id);

    if (p == FINGERPRINT_OK)
    {
#if FINGER_DEBUG
        printf("[FingerManager] Lưu thành công!\n");
#endif
        ledSuccess();
        emit("saved");
    }
    else
    {
#if FINGER_DEBUG
        printf("[FingerManager] Lỗi lưu trữ. Mã lỗi: 0x");
        printf("%02X\n", p);
#endif
        ledError();
        emit("error");
    }

    _state = FingerState::IDLE;
    ledStandby();
    return p;
}

/* ================= FSM UPDATE ================= */

void FingerManager::update()
{

    uint8_t result;
    switch (_state)
    {

    /* ================= IDLE ================= */
    case FingerState::IDLE:
        break;

    /* ================= CHỜ ĐẶT TAY ================= */
    case FingerState::WAIT_FINGER:
        result = _finger.getImage();
        if (result == FINGERPRINT_OK)
        {
#if FINGER_DEBUG
            printf("[FingerManager] Step ");
            printf("%d", _step);
            printf(": Đã lấy ảnh vân tay.\n");
#endif

            setLED(R588S_LED_ON, 0, R588S_LED_BLUE);
            _state = FingerState::CAPTURE;
        }
        break;

    /* ================= CHUYỂN IMAGE → TZ ================= */
    case FingerState::CAPTURE:
        if (_finger.image2Tz(_step) == FINGERPRINT_OK)
        {
#if FINGER_DEBUG
            printf("[FingerManager] Step ");
            printf("%d", _step);
            printf(": image2Tz OK.\n");
#endif

            emit("scanning"); // gửi websocket step hiện tại
            _removeTick = millis();
            _state = FingerState::WAIT_REMOVE;
        }
        else
        {
#if FINGER_DEBUG
            printf("[FingerManager] Lỗi image2Tz!\n");
#endif
            _state = FingerState::ERROR;
        }
        break;

    /* ================= BẮT BUỘC NHẤC TAY ================= */
    case FingerState::WAIT_REMOVE:
        result = _finger.getImage();
        if (result == FINGERPRINT_NOFINGER)
        {
            if (millis() - _removeTick >= REMOVE_DELAY)
            {
                _state = FingerState::STEP_DONE;
            }
        }
        else
        {
            // tay vẫn còn → reset timer
            _removeTick = millis();
        }
        break;

    /* ================= HOÀN TẤT 1 STEP ================= */
    case FingerState::STEP_DONE:
        if (_step < TOTAL_STEP)
        {
#if FINGER_DEBUG
            printf("[FingerManager] Nhấc tay xong, chuẩn bị step tiếp.\n");
#endif

            _step++;
            setLED(R588S_LED_BREATHING, 30, R588S_LED_BLUE);
            _state = FingerState::WAIT_FINGER;
        }
        else
        {
#if FINGER_DEBUG
            printf("[FingerManager] Đang tạo Model tổng hợp...\n");
#endif

            if (_finger.createModel() == FINGERPRINT_OK)
            {
#if FINGER_DEBUG
                printf("[FingerManager] Model READY.\n");
#endif

                setLED(R588S_LED_ON, 0, R588S_LED_PURPLE);
                emit("ready");
                _state = FingerState::MODEL_READY;
            }
            else
            {
                _state = FingerState::ERROR;
            }
        }
        break;

    /* ================= CHỜ CLIENT LƯU ================= */
    case FingerState::MODEL_READY:
        break;

    /* ================= LỖI ================= */
    case FingerState::ERROR:
#if FINGER_DEBUG
        printf("[FingerManager] ERROR → reset.\n");
#endif

        ledError();
        emit("error");
        _step = 1;
        _state = FingerState::IDLE;
        ledStandby();
        break;
    }
}

uint8_t FingerManager::getFingerprintID()
{
    uint8_t p = _finger.getImage();
    if (p != FINGERPRINT_OK)
        return -1;

    p = _finger.image2Tz();
    if (p != FINGERPRINT_OK)
        return -1;

    p = _finger.fingerFastSearch();
    if (p != FINGERPRINT_OK)
        return -1;

    // found a match!
    Serial.print("Found ID #");
    Serial.print(_finger.fingerID);
    Serial.print(" with confidence of ");
    Serial.println(_finger.confidence);
    return _finger.fingerID;
}

/* ================= DATABASE ================= */

bool FingerManager::deleteFingerprint(uint16_t id)
{
#if FINGER_DEBUG
    printf("[FingerManager] Đang xóa ID: ");
    printf("%d\n", id);
#endif
    bool res = (_finger.deleteModel(id) == FINGERPRINT_OK);
#if FINGER_DEBUG
    if (res)
        printf("[FingerManager] Xóa thành công.\n");
    else
        printf("[FingerManager] Xóa thất bại!\n");
#endif
    return res;
}

void FingerManager::clearAll()
{
#if FINGER_DEBUG
    printf("[FingerManager] ĐANG XÓA TOÀN BỘ CƠ SỞ DỮ LIỆU...\n");
#endif
    _finger.emptyDatabase();
}

uint16_t FingerManager::getTemplateCount()
{
    _finger.getTemplateCount();
#if FINGER_DEBUG
    printf("[FingerManager] Tổng số vân tay hiện có: ");
    printf("%d \n", _finger.templateCount);
#endif
    return _finger.templateCount;
}

/* ================= LED ================= */

void FingerManager::setLED(uint8_t mode, uint8_t speed, uint8_t color, uint8_t cycles)
{
    _finger.LEDcontrol(mode, speed, color, cycles);
}

void FingerManager::ledStandby()
{
    setLED(R588S_LED_BREATHING, 40, R588S_LED_BLUE);
}

void FingerManager::ledSuccess()
{
    setLED(R588S_LED_FLASHING, 30, R588S_LED_PURPLE, 3);
}

void FingerManager::ledError()
{
    setLED(R588S_LED_FLASHING, 20, R588S_LED_RED, 3);
}