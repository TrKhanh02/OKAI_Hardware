// #include <DW1000Ng.hpp>
// #include <DW1000NgUtils.hpp>
// #include <DW1000NgTime.hpp>
// #include <DW1000NgConstants.hpp>

// // ==============================
// // HARDWARE
// // ==============================
// const uint8_t PIN_RST = 0xFF;
// const uint8_t PIN_IRQ = 5;
// const uint8_t PIN_SS = SS;

// // ==============================
// // MESSAGE DEFINES
// // ==============================
// #define POLL_ACK 1
// #define TIMESTAMP_REQUEST 4
// #define TIMESTAMP_RESPONSE 5

// // ==============================
// // TIMESTAMP MASK (40-bit DW1000 timer)
// // ==============================
// const uint64_t TIMESTAMP_MASK = 0xFFFFFFFFFFULL;  // 40-bit mask

// // ==============================
// // CONFIGURATION
// // ==============================
// const uint16_t MY_ADDRESS = 6;           // Slave tag
// const uint16_t MASTER_TAG_ADDR = 5;      // Master tag
// const uint8_t TDOA_ANCHOR_ID = 2;        // Anchor dùng để tính TDoA

// // ==============================
// // STATE
// // ==============================
// volatile bool receivedAck = false;
// uint64_t last_anchor_ts = 0;             // Timestamp nhận POLL_ACK từ Anchor2
// byte data[18];

// // ==============================
// // DW1000 CONFIG
// // ==============================
// device_configuration_t DEFAULT_CONFIG = {
//     false, true, true, true, false,
//     SFDMode::STANDARD_SFD,
//     Channel::CHANNEL_5,
//     DataRate::RATE_850KBPS,
//     PulseFrequency::FREQ_64MHZ,
//     PreambleLength::LEN_256,
//     PreambleCode::CODE_3
// };

// interrupt_configuration_t DEFAULT_INTERRUPT_CONFIG = {
//     true, true, true, false, true
// };

// // ==============================
// // CALLBACK
// // ==============================
// void handleReceived() { 
//     receivedAck = true; 
// }

// // ==============================
// // SETUP
// // ==============================
// void setup() {
//     Serial.begin(115200);
//     delay(1000);
    
//     Serial.println("=== UWB Slave Tag - Fixed Timestamp ===");
//     Serial.println("Using 40-bit timestamp masking");
//     Serial.printf("Listening for Anchor %d POLL_ACK\n\n", TDOA_ANCHOR_ID);
    
//     DW1000Ng::initialize(PIN_SS, PIN_IRQ, PIN_RST);
//     DW1000Ng::applyConfiguration(DEFAULT_CONFIG);
//     DW1000Ng::applyInterruptConfiguration(DEFAULT_INTERRUPT_CONFIG);
//     DW1000Ng::setNetworkId(10);
//     DW1000Ng::setDeviceAddress(MY_ADDRESS);
//     DW1000Ng::setAntennaDelay(16436);
    
//     DW1000Ng::attachReceivedHandler(handleReceived);
//     DW1000Ng::startReceive();
    
//     Serial.println("Initialization done. Listening...");
// }

// // ==============================
// // LOOP
// // ==============================
// void loop() {
//     if (!receivedAck) return;
    
//     receivedAck = false;
//     DW1000Ng::getReceivedData(data, 18);
    
//     byte msgId = data[0];
    
//     // ==============================
//     // 1️⃣ Nhận POLL_ACK từ Anchor2 và lưu timestamp
//     // ==============================
//     if (msgId == POLL_ACK) {
//         uint8_t anchorId = data[1];
        
//         if (anchorId == TDOA_ANCHOR_ID) {
//             // ✅ Mask timestamp về 40-bit
//             last_anchor_ts = DW1000Ng::getReceiveTimestamp() & TIMESTAMP_MASK;
//             Serial.printf("[Slave] Got POLL_ACK from A%d | TS=%llu\n", anchorId, last_anchor_ts);
//         }
//     }
    
//     // ==============================
//     // 2️⃣ Nhận yêu cầu timestamp từ Master
//     // ==============================
//     else if (msgId == TIMESTAMP_REQUEST) {
//         uint16_t senderAddr = (data[8] << 8) | data[7];
        
//         if (senderAddr == MASTER_TAG_ADDR) {
//             if (last_anchor_ts == 0) {
//                 Serial.println("[Slave] No valid anchor timestamp yet.");
//                 DW1000Ng::startReceive();
//                 return;
//             }
            
//             // Chuẩn bị gói phản hồi
//             data[0] = TIMESTAMP_RESPONSE;
//             DW1000NgUtils::writeValueToBytes(data + 1, last_anchor_ts, sizeof(uint64_t));
//             DW1000NgUtils::writeValueToBytes(data + 7, MY_ADDRESS, sizeof(uint16_t));
            
//             DW1000Ng::setTransmitData(data, 18);
//             DW1000Ng::startTransmit();
            
//             Serial.printf("[Slave] Sent TIMESTAMP_RESPONSE | TS=%llu\n", last_anchor_ts);
//         }
//     }
    
//     DW1000Ng::startReceive();
// }