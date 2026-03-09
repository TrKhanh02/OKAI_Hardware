
// /*
//  * MIT License
//  * Copyright (c) 2018 Michele Biondi, Andrea Salvatori
//  * Copyright (c) 2015 by Thomas Trojer <thomas@trojer.net>
//  * Licensed under MIT and Apache License, Version 2.0
//  * @file RangingAnchorMain.ino
//  * Anchor chính đo khoảng cách với tag và nhận khoảng cách từ hai anchor phụ.
//  */

// #include <DW1000Ng.hpp>
// #include <DW1000NgUtils.hpp>
// #include <DW1000NgRanging.hpp>
// #include <DW1000NgTime.hpp>
// #include <DW1000NgConstants.hpp>
// #include <DW1000NgRTLS.hpp>

// // Kết nối chân
// const uint8_t PIN_RST = 0xFF;
// const uint8_t PIN_IRQ = 5;
// const uint8_t PIN_SS = SS;

// // Tin nhắn
// #define POLL 0
// #define POLL_ACK 1
// #define RANGE 2
// #define RANGE_REPORT 3
// #define RANGE_FAILED 255

// // Biến trạng thái cho TWR
// volatile byte expectedMsgId = POLL;
// volatile boolean sentAck = false;
// volatile boolean receivedAck = false;
// boolean protocolFailed = false;

// // Thời gian cho TWR
// uint64_t timePollReceived;
// uint64_t timePollAckSent;
// uint64_t timeRangeReceived;

// // Bộ đệm dữ liệu
// #define LEN_DATA 18
// byte data[LEN_DATA];

// // Watchdog
// uint32_t lastActivity;
// uint32_t resetPeriod = 250;
// uint16_t replyDelayTimeUS = 3000;
// uint16_t successRangingCount = 0;
// uint32_t rangingCountPeriod = 0;
// float samplingRate = 0;

// // Khoảng cách từ các anchor
// double range_self; // Anchor chính (ID 1)
// double range_A;    // Anchor phụ A (ID 2)
// double range_B;    // Anchor phụ B (ID 3)
// boolean received_A = false;
// boolean received_B = false;

// // Cấu hình
// device_configuration_t DEFAULT_CONFIG = {
//     false, true, true, true, false,
//     SFDMode::STANDARD_SFD, Channel::CHANNEL_5,
//     DataRate::RATE_850KBPS, PulseFrequency::FREQ_16MHZ,
//     PreambleLength::LEN_256, PreambleCode::CODE_3
// };

// interrupt_configuration_t DEFAULT_INTERRUPT_CONFIG = {
//     true, true, true, false, true
// };

// void noteActivity() {
//     lastActivity = millis();
// }

// void receiver() {
//     DW1000Ng::forceTRxOff();
//     DW1000Ng::startReceive();
// }

// void handleSent() {
//     sentAck = true;
// }

// void handleReceived() {
//     receivedAck = true;
// }

// void transmitPollAck(uint8_t anchorId) {
//     data[0] = POLL_ACK;
//     data[1] = anchorId;
//     DW1000Ng::setTransmitData(data, LEN_DATA);
//     DW1000Ng::startTransmit();
// }

// void transmitRangeReport() {
//     byte rangingReport[] = {DATA, SHORT_SRC_AND_DEST, DW1000NgRTLS::increaseSequenceNumber(), 0,0, 0,0, 0,0, 0x60, 0,0};
//     DW1000Ng::getNetworkId(&rangingReport[3]);
//     byte tag_address[] = {0x05, 0x00}; // Địa chỉ tag
//     memcpy(&rangingReport[5], tag_address, 2);
//     DW1000Ng::getDeviceAddress(&rangingReport[7]);
//     DW1000NgUtils::writeValueToBytes(&rangingReport[10], static_cast<uint16_t>(range_self * 1000), 2);
//     DW1000Ng::setTransmitData(rangingReport, sizeof(rangingReport));
//     DW1000Ng::startTransmit();
// }

// void transmitRangeFailed(uint8_t anchorId) {
//     data[0] = RANGE_FAILED;
//     data[1] = anchorId;
//     DW1000Ng::setTransmitData(data, LEN_DATA);
//     DW1000Ng::startTransmit();
// }

// void setup() {
//     Serial.begin(115200);
//     delay(1000);
//     Serial.println(F("### DW1000Ng-arduino-ranging-anchorMain ###"));
//     DW1000Ng::initialize(PIN_SS, PIN_IRQ, PIN_RST);
//     Serial.println(F("DW1000Ng initialized ..."));
//     DW1000Ng::applyConfiguration(DEFAULT_CONFIG);
//     DW1000Ng::applyInterruptConfiguration(DEFAULT_INTERRUPT_CONFIG);
//     DW1000Ng::setNetworkId(10);
//     DW1000Ng::setDeviceAddress(1); // Địa chỉ anchor chính
//     DW1000Ng::setAntennaDelay(16436);
//     Serial.println(F("Committed configuration ..."));
//     char msg[128];
//     DW1000Ng::getPrintableDeviceIdentifier(msg);
//     Serial.print("Device ID: "); Serial.println(msg);
//     DW1000Ng::getPrintableExtendedUniqueIdentifier(msg);
//     Serial.print("Unique ID: "); Serial.println(msg);
//     DW1000Ng::getPrintableNetworkIdAndShortAddress(msg);
//     Serial.print("Network ID & Device Address: "); Serial.println(msg);
//     DW1000Ng::getPrintableDeviceMode(msg);
//     Serial.print("Device mode: "); Serial.println(msg);
//     DW1000Ng::attachSentHandler(handleSent);
//     DW1000Ng::attachReceivedHandler(handleReceived);
//     receiver();
//     noteActivity();
//     rangingCountPeriod = millis();
// }

// void loop() {
//     int32_t curMillis = millis();
//     if (!sentAck && !receivedAck) {
//         if (curMillis - lastActivity > resetPeriod) {
//             receiver();
//             noteActivity();
//         }
//         return;
//     }
//     if (sentAck) {
//         sentAck = false;
//         if (data[0] == POLL_ACK) {
//             timePollAckSent = DW1000Ng::getTransmitTimestamp();
//             noteActivity();
//         }
//         receiver();
//     }
//     if (receivedAck) {
//         receivedAck = false;
//         DW1000Ng::getReceivedData(data, LEN_DATA);
//         byte msgId = data[0];
//         uint8_t anchorId = data[1];
//         if (msgId == POLL && anchorId == 1) {
//             protocolFailed = false;
//             timePollReceived = DW1000Ng::getReceiveTimestamp();
//             expectedMsgId = RANGE;
//             transmitPollAck(anchorId);
//             noteActivity();
//         } else if (msgId == RANGE && anchorId == 1) {
//             timeRangeReceived = DW1000Ng::getReceiveTimestamp();
//             expectedMsgId = POLL;
//             if (!protocolFailed) {
//                 uint64_t timePollSent = DW1000NgUtils::bytesAsValue(data + 2, LENGTH_TIMESTAMP);
//                 uint64_t timePollAckReceived = DW1000NgUtils::bytesAsValue(data + 7, LENGTH_TIMESTAMP);
//                 uint64_t timeRangeSent = DW1000NgUtils::bytesAsValue(data + 12, LENGTH_TIMESTAMP);
//                 range_self = DW1000NgRanging::computeRangeAsymmetric(
//                     timePollSent, timePollReceived, timePollAckSent,
//                     timePollAckReceived, timeRangeSent, timeRangeReceived);
//                 range_self = DW1000NgRanging::correctRange(range_self);
//                 if (range_self > 10.0 || range_self < 0.0) {
//                     transmitRangeFailed(anchorId);
//                 } else {
//                     Serial.print("anchor 1 Range: "); Serial.print(range_self); Serial.println(" m");
//                     transmitRangeReport();
//                     successRangingCount++;
//                     if (curMillis - rangingCountPeriod > 1000) {
//                         samplingRate = (1000.0f * successRangingCount) / (curMillis - rangingCountPeriod);
//                         rangingCountPeriod = curMillis;
//                         successRangingCount = 0;
//                     }
//                 }
//             } else {
//                 transmitRangeFailed(anchorId);
//             }
//             noteActivity();
//         } else if (msgId == RANGE_REPORT && (anchorId == 2 || anchorId == 3)) {
//             double range = static_cast<double>(DW1000NgUtils::bytesAsValue(&data[10], 2)) / 1000.0;
//             if (anchorId == 2) {
//                 range_A = range;
//                 Serial.print("anchor 2 Range: "); Serial.print(range_A); Serial.println(" m");
//                 received_A = true;
//             } else if (anchorId == 3) {
//                 range_B = range;
//                 Serial.print("anchor 3 Range: "); Serial.print(range_B); Serial.println(" m");
//                 received_B = true;
//             }
//             noteActivity();
//         }
//         receiver();
//     }
// }