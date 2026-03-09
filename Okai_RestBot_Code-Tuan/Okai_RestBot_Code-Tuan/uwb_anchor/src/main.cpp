#include <DW1000Ng.hpp>
#include <DW1000NgUtils.hpp>
#include <DW1000NgRanging.hpp>

const uint8_t PIN_RST = 0xFF;
const uint8_t PIN_IRQ = 4;
const uint8_t PIN_SS = SS;

// *** QUAN TRỌNG: Đặt ID duy nhất cho mỗi anchor (1, 2, hoặc 3) ***
uint8_t anchorId = 1;  // THAY ĐỔI THÀNH 1, 2, hoặc 3

// Protocol messages
#define POLL 0
#define POLL_ACK 1
#define RANGE 2
#define RANGE_REPORT 3
#define RANGE_FAILED 255

// State variables
volatile byte expectedMsgId = POLL;
volatile boolean sentAck = false;
volatile boolean receivedAck = false;
boolean protocolFailed = false;

// Timestamps
uint64_t timePollReceived;
uint64_t timePollAckSent;
uint64_t timeRangeReceived;

// Source address tracking
uint16_t currentSourceAddr = 0;

// Data buffer
#define LEN_DATA 24
byte data[LEN_DATA];

// Watchdog and timing
uint32_t lastActivity;
uint32_t resetPeriod = 500;
uint16_t replyDelayTimeUS = 3000;
uint16_t successRangingCount = 0;
uint32_t rangingCountPeriod = 0;
float samplingRate = 0;

// Distance filtering
const float MIN_VALID_DISTANCE = 0.1;
const float MAX_VALID_DISTANCE = 15.0;
float lastValidDistance = 0.0;
const float MAX_DISTANCE_JUMP = 5.0;

// Configuration
device_configuration_t DEFAULT_CONFIG = {
    false, true, true, true, false,
    SFDMode::STANDARD_SFD, Channel::CHANNEL_5,
    DataRate::RATE_850KBPS, PulseFrequency::FREQ_64MHZ,
    PreambleLength::LEN_256, PreambleCode::CODE_3
};

interrupt_configuration_t DEFAULT_INTERRUPT_CONFIG = {
    true, true, true, false, true
};

bool isDistanceValid(double distance) {
    if (distance < MIN_VALID_DISTANCE || distance > MAX_VALID_DISTANCE) {
        return false;
    }
    if (lastValidDistance > 0) {
        float jump = abs(distance - lastValidDistance);
        if (jump > MAX_DISTANCE_JUMP) {
            Serial.printf("Distance jump too large: %.2f -> %.2f (jump: %.2f)\n", 
                         lastValidDistance, distance, jump);
            return false;
        }
    }
    return true;
}

void noteActivity() {
    lastActivity = millis();
}

void receiver() {
    DW1000Ng::forceTRxOff();
    DW1000Ng::startReceive();
}

void resetInactive() {
    expectedMsgId = POLL;
    protocolFailed = false;
    currentSourceAddr = 0;
    receiver();
    noteActivity();
}

void handleSent() {
    sentAck = true;
}

void handleReceived() {
    receivedAck = true;
}

void transmitPollAck(uint8_t targetAnchorId, uint16_t sourceAddr) {
    data[0] = POLL_ACK;
    data[1] = targetAnchorId;
    data[2] = (sourceAddr >> 8) & 0xFF;  // Preserve source address
    data[3] = sourceAddr & 0xFF;
    DW1000Ng::setTransmitData(data, LEN_DATA);
    DW1000Ng::startTransmit();
}

void transmitRangeReport(float curRange, uint8_t targetAnchorId, uint16_t sourceAddr) {
    data[0] = RANGE_REPORT;
    data[1] = targetAnchorId;
    data[2] = (sourceAddr >> 8) & 0xFF;  // Target tag address
    data[3] = sourceAddr & 0xFF;
    uint16_t rangeInt = (uint16_t)(curRange * 1000); // Convert to mm
    DW1000NgUtils::writeValueToBytes(data + 10, rangeInt, 2);
    DW1000Ng::setTransmitData(data, LEN_DATA);
    DW1000Ng::startTransmit();
}

void transmitRangeFailed(uint8_t targetAnchorId, uint16_t sourceAddr) {
    data[0] = RANGE_FAILED;
    data[1] = targetAnchorId;
    data[2] = (sourceAddr >> 8) & 0xFF;  // Target tag address
    data[3] = sourceAddr & 0xFF;
    DW1000Ng::setTransmitData(data, LEN_DATA);
    DW1000Ng::startTransmit();
}

void setup() {
    Serial.begin(115200);
    Serial.println("Initializing DW1000...");
    DW1000Ng::initialize(PIN_SS, PIN_IRQ, PIN_RST);
    
    DW1000Ng::applyConfiguration(DEFAULT_CONFIG);
    DW1000Ng::applyInterruptConfiguration(DEFAULT_INTERRUPT_CONFIG);
    
    DW1000Ng::setNetworkId(10);
    DW1000Ng::setDeviceAddress(anchorId);
    DW1000Ng::setAntennaDelay(16426);
    
    Serial.println("Configuration committed");
    
    char msg[128];
    DW1000Ng::getPrintableDeviceIdentifier(msg);
    Serial.printf("Device ID: %s\n", msg);
    DW1000Ng::getPrintableExtendedUniqueIdentifier(msg);
    Serial.printf("Unique ID: %s\n", msg);
    DW1000Ng::getPrintableNetworkIdAndShortAddress(msg);
    Serial.printf("Network ID & Address: %s\n", msg);
    
    DW1000Ng::attachSentHandler(handleSent);
    DW1000Ng::attachReceivedHandler(handleReceived);
    
    receiver();
    noteActivity();
    rangingCountPeriod = millis();
    
    Serial.printf("Anchor %d ready - waiting for POLL messages (Multi-Tag Support)\n", anchorId);
}

void loop() {
    int32_t curMillis = millis();
    
    if (!sentAck && !receivedAck) {
        if (curMillis - lastActivity > resetPeriod) {
            resetInactive();
        }
        return;
    }
    
    if (sentAck) {
        sentAck = false;
        if (data[0] == POLL_ACK) {
            timePollAckSent = DW1000Ng::getTransmitTimestamp();
            noteActivity();
        }
        receiver();
    }
    
    // Handle received message
    if (receivedAck) {
        receivedAck = false;
        DW1000Ng::getReceivedData(data, LEN_DATA);
        
        byte msgId = data[0];
        uint8_t targetAnchorId = data[1];
        
        // *** CRITICAL: Only process if this message is for THIS anchor ***
        if (targetAnchorId != anchorId) {
            receiver();
            return;
        }
        
        // Extract source address from message
        uint16_t sourceAddr = 0;
        if (msgId == POLL || msgId == RANGE) {
            sourceAddr = (data[2] << 8) | data[3];
        }
        
        if (msgId != expectedMsgId) {
            protocolFailed = true;
            Serial.printf("Protocol error: expected %d, got %d\n", expectedMsgId, msgId);
        }
        
        if (msgId == POLL) {
            Serial.printf("Received POLL from Tag %d for Anchor %d\n", sourceAddr, anchorId);
            protocolFailed = false;
            currentSourceAddr = sourceAddr;  // Save source address
            timePollReceived = DW1000Ng::getReceiveTimestamp();
            expectedMsgId = RANGE;
            transmitPollAck(anchorId, sourceAddr);
            noteActivity();
            
        } else if (msgId == RANGE) {
            // Verify source address matches
            if (sourceAddr != currentSourceAddr) {
                Serial.printf("Source address mismatch! Expected %d, got %d\n", 
                             currentSourceAddr, sourceAddr);
                protocolFailed = true;
            }
            
            Serial.printf("Received RANGE from Tag %d for Anchor %d\n", sourceAddr, anchorId);
            timeRangeReceived = DW1000Ng::getReceiveTimestamp();
            expectedMsgId = POLL;
            
            if (!protocolFailed) {
                uint64_t timePollSent = DW1000NgUtils::bytesAsValue(data + 4, LENGTH_TIMESTAMP);
                uint64_t timePollAckReceived = DW1000NgUtils::bytesAsValue(data + 9, LENGTH_TIMESTAMP);
                uint64_t timeRangeSent = DW1000NgUtils::bytesAsValue(data + 14, LENGTH_TIMESTAMP);
                
                double distance = DW1000NgRanging::computeRangeAsymmetric(
                    timePollSent, timePollReceived, timePollAckSent,
                    timePollAckReceived, timeRangeSent, timeRangeReceived);
                    
                distance = DW1000NgRanging::correctRange(distance);
                
                if (isDistanceValid(distance)) {
                    Serial.printf("Tag %d -> Anchor %d Range: %.2fm | RX: %.1fdBm | Rate: %.1fHz\n", 
                                 sourceAddr, anchorId, distance, DW1000Ng::getReceivePower(), samplingRate);
                    transmitRangeReport(distance, anchorId, sourceAddr);
                    successRangingCount++;
                    lastValidDistance = distance;
                } else {
                    Serial.printf("Invalid distance: %.2fm - sending failure to Tag %d\n", 
                                 distance, sourceAddr);
                    transmitRangeFailed(anchorId, sourceAddr);
                }
            } else {
                Serial.printf("Protocol failed - sending failure to Tag %d\n", sourceAddr);
                transmitRangeFailed(anchorId, sourceAddr);
            }
            
            currentSourceAddr = 0;  // Reset source address
            noteActivity();
        }
        
        // Calculate sampling rate
        if (curMillis - rangingCountPeriod > 1000) {
            samplingRate = (1000.0f * successRangingCount) / (curMillis - rangingCountPeriod);
            rangingCountPeriod = curMillis;
            successRangingCount = 0;
        }
    }
    
    delay(1);
}