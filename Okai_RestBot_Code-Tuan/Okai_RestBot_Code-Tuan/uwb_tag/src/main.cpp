#include <DW1000Ng.hpp>
#include <DW1000NgUtils.hpp>
#include <DW1000NgTime.hpp>
#include <DW1000NgConstants.hpp>
#include <DW1000NgRTLS.hpp>
#include <ArduinoJson.h>

// ============================================
// HARDWARE PINS
// ============================================
const uint8_t PIN_RST = 0xFF;
const uint8_t PIN_IRQ = 5;
const uint8_t PIN_SS = SS;

// ============================================
// MESSAGE TYPES
// ============================================
#define POLL 0
#define POLL_ACK 1
#define RANGE 2
#define RANGE_REPORT 3
#define RANGE_FAILED 255

// ============================================
// CONFIGURATION
// ============================================
const uint8_t NUM_ANCHORS = 3;

// *** QUAN TRỌNG: Thay đổi giá trị này trước khi flash ***
// Tag A: const uint16_t MY_ADDRESS = 5;
// Tag B: const uint16_t MY_ADDRESS = 6;
const uint16_t MY_ADDRESS = 6;  // <<<< THAY ĐỔI Ở ĐÂY

// ============================================
// STATE VARIABLES
// ============================================
volatile boolean sentAck = false;
volatile boolean receivedAck = false;

uint8_t currentAnchor = 1;
volatile byte expectedMsgId = POLL_ACK;

// Timestamps for ranging
uint64_t timePollSent;
uint64_t timePollAckReceived;
uint64_t timeRangeSent;

// Distances to anchors
double distances[3] = {0.0, 0.0, 0.0};
bool distanceValid[3] = {false, false, false};

// Timing
uint32_t lastActivity;
uint32_t resetPeriod = 100;
uint16_t replyDelayTimeUS = 800;
uint32_t lastCycleTime = 0;
uint8_t retryCount = 0;
const uint8_t MAX_RETRIES = 1;

// Data buffer
#define LEN_DATA 24
byte data[LEN_DATA];

// ============================================
// DEVICE CONFIGURATION
// ============================================
device_configuration_t DEFAULT_CONFIG = {
    false, true, true, true, false,
    SFDMode::STANDARD_SFD, Channel::CHANNEL_5,
    DataRate::RATE_850KBPS, PulseFrequency::FREQ_64MHZ,
    PreambleLength::LEN_256, PreambleCode::CODE_3
};

interrupt_configuration_t DEFAULT_INTERRUPT_CONFIG = {
    true, true, true, false, true
};

// ============================================
// UTILITY FUNCTIONS
// ============================================
void noteActivity() {
    lastActivity = millis();
}

// ============================================
// TRANSMIT FUNCTIONS
// ============================================
void transmitPoll(uint8_t anchorId) {
    data[0] = POLL;
    data[1] = anchorId;
    data[2] = (MY_ADDRESS >> 8) & 0xFF;  // Source address high byte
    data[3] = MY_ADDRESS & 0xFF;          // Source address low byte
    DW1000Ng::setTransmitData(data, 4);
    DW1000Ng::startTransmit();
}

void transmitRange(uint8_t anchorId) {
    data[0] = RANGE;
    data[1] = anchorId;
    data[2] = (MY_ADDRESS >> 8) & 0xFF;  // Source address
    data[3] = MY_ADDRESS & 0xFF;

    byte futureTimeBytes[LENGTH_TIMESTAMP];
    timeRangeSent = DW1000Ng::getSystemTimestamp();
    timeRangeSent += DW1000NgTime::microsecondsToUWBTime(replyDelayTimeUS);
    DW1000NgUtils::writeValueToBytes(futureTimeBytes, timeRangeSent, LENGTH_TIMESTAMP);
    DW1000Ng::setDelayedTRX(futureTimeBytes);
    timeRangeSent += DW1000Ng::getTxAntennaDelay();

    DW1000NgUtils::writeValueToBytes(data + 4, timePollSent, LENGTH_TIMESTAMP);
    DW1000NgUtils::writeValueToBytes(data + 9, timePollAckReceived, LENGTH_TIMESTAMP);
    DW1000NgUtils::writeValueToBytes(data + 14, timeRangeSent, LENGTH_TIMESTAMP);

    DW1000Ng::setTransmitData(data, 20);
    DW1000Ng::startTransmit(TransmitMode::DELAYED);
}

// ============================================
// SEND RANGING DATA VIA UART (JSON)
// ============================================
void sendDataJSON() {
    // *** CHỈ GỬI KHI CẢ 3 ANCHOR ĐỀU VALID ***
    if (distanceValid[0] && distanceValid[1] && distanceValid[2]) {
        JsonDocument doc;
        
        doc["addr"] = MY_ADDRESS;
        doc["d1"] = (double)distances[0];
        doc["d2"] = (double)distances[1];
        doc["d3"] = (double)distances[2];
        
        serializeJson(doc, Serial);
        Serial.println();
    } 
}

// ============================================
// STATE MACHINE
// ============================================
void moveToNextAnchor() {
    currentAnchor++;
    if (currentAnchor > NUM_ANCHORS) {
        // Chỉ gửi JSON khi có đủ 3 anchor valid
        sendDataJSON();
        
        // Reset lại trạng thái cho cycle mới
        currentAnchor = 1;
        lastCycleTime = millis();
        
        // Random delay để tránh collision với tag khác
        delay(random(5, 20));
    }
    retryCount = 0;
    expectedMsgId = POLL_ACK;

    DW1000Ng::forceTRxOff();
    delay(2);
    transmitPoll(currentAnchor);
    noteActivity();
}

void resetInactive() {
    distances[currentAnchor - 1] = 0.0;
    distanceValid[currentAnchor - 1] = false;
    
    if (retryCount < MAX_RETRIES) {
        retryCount++;
        expectedMsgId = POLL_ACK;
        DW1000Ng::forceTRxOff();
        delay(2);
        transmitPoll(currentAnchor);
        noteActivity();
    } else {
        moveToNextAnchor();
    }
}

// ============================================
// INTERRUPT HANDLERS
// ============================================
void handleSent() { 
    sentAck = true; 
}

void handleReceived() { 
    receivedAck = true; 
}

// ============================================
// SETUP
// ============================================
void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.printf("=== UWB Tag %d (Multi-Tag Support) ===\n", MY_ADDRESS);
    Serial.println("Starting Ranging Mode\n");

    DW1000Ng::initialize(PIN_SS, PIN_IRQ, PIN_RST);
    DW1000Ng::applyConfiguration(DEFAULT_CONFIG);
    DW1000Ng::applyInterruptConfiguration(DEFAULT_INTERRUPT_CONFIG);
    DW1000Ng::setNetworkId(10);
    DW1000Ng::setDeviceAddress(MY_ADDRESS);
    DW1000Ng::setAntennaDelay(16450);

    DW1000Ng::attachSentHandler(handleSent);
    DW1000Ng::attachReceivedHandler(handleReceived);

    Serial.println("Initialization complete!");
    
    // Random seed dựa trên địa chỉ để tạo timing khác nhau
    randomSeed(MY_ADDRESS * analogRead(0));
    
    // Random delay để tránh collision khi khởi động
    uint16_t startDelay = random(0, 150);
    Serial.printf("Starting with %dms delay to avoid collision\n", startDelay);
    delay(startDelay);
    
    Serial.println("Starting ranging with Anchor 1...\n");

    lastCycleTime = millis();
    transmitPoll(currentAnchor);
    noteActivity();
}

// ============================================
// MAIN LOOP
// ============================================
void loop() {
    if (!sentAck && !receivedAck) {
        if (millis() - lastActivity > resetPeriod) {
            resetInactive();
        }
        return;
    }

    if (sentAck) {
        sentAck = false;
        DW1000Ng::startReceive();
    }

    if (receivedAck) {
        receivedAck = false;
        DW1000Ng::getReceivedData(data, LEN_DATA);
        byte msgId = data[0];

        // *** KIỂM TRA SOURCE ADDRESS - CHỈ XỬ LÝ MESSAGE DÀNH CHO TAG NÀY ***
        if (msgId == POLL_ACK || msgId == RANGE_REPORT || msgId == RANGE_FAILED) {
            uint16_t targetAddr = (data[2] << 8) | data[3];
            if (targetAddr != MY_ADDRESS) {
                // Message dành cho tag khác, bỏ qua
                DW1000Ng::startReceive();
                return;
            }
        }

        // ==============================
        // POLL_ACK HANDLER
        // ==============================
        if (msgId == POLL_ACK) {
            uint8_t anchorId = data[1];

            if (anchorId != currentAnchor) {
                DW1000Ng::startReceive();
                return;
            }

            timePollSent = DW1000Ng::getTransmitTimestamp();
            timePollAckReceived = DW1000Ng::getReceiveTimestamp();
            
            expectedMsgId = RANGE_REPORT;
            transmitRange(currentAnchor);
            noteActivity();
        }

        // ==============================
        // RANGE_REPORT HANDLER
        // ==============================
        else if (msgId == RANGE_REPORT) {
            uint8_t anchorId = data[1];
            if (anchorId != currentAnchor) {
                DW1000Ng::startReceive();
                return;
            }

            uint16_t range_mm;
            memcpy(&range_mm, &data[10], 2);
            distances[currentAnchor - 1] = (float)range_mm / 1000.0f;
            distanceValid[currentAnchor - 1] = true;

            moveToNextAnchor();
        }

        // ==============================
        // RANGE_FAILED HANDLER
        // ==============================
        else if (msgId == RANGE_FAILED) {
            uint8_t anchorId = data[1];
            if (anchorId != currentAnchor) {
                DW1000Ng::startReceive();
                return;
            }

            distances[currentAnchor - 1] = 0.0;
            distanceValid[currentAnchor - 1] = false;
            moveToNextAnchor();
        }
    }
    
    delay(1);
}