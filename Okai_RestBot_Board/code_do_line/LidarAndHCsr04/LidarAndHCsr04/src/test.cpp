// #include "LineFollower.h"
// #include "Config.h"

// LineFollower::LineFollower(MotorController *motorController, SensorManager *sensorManager, HardwareSerial *lineSerialPort)
// {
//     motor = motorController;
//     sensor = sensorManager;
//     lineSerial = lineSerialPort;
//     lastError = 0.0;
//     integral = 0.0;
// }

// void LineFollower::init()
// {
//     lineSerial->begin(115200, SERIAL_8N1, Config::LINE_RX_PIN, Config::LINE_TX_PIN);
//     Serial.println("Line Follower initialized on separate UART (11 Sensors)");
// }

// bool LineFollower::checkSideObstaclesWhileTurning(bool isTurningLeft)
// {
//     if (isTurningLeft)
//     {
//         return sensor->checkLeftSideObstacle(Config::OBSTACLE_DISTANCE_CM);
//     }
//     else
//     {
//         return sensor->checkRightSideObstacle(Config::OBSTACLE_DISTANCE_CM);
//     }
// }

// // Hàm đọc pattern mới từ line sensor
// unsigned int LineFollower::readLinePattern()
// {
//     if (!lineSerial->available())
//         return 0;

//     DeserializationError error = deserializeJson(doc, *lineSerial);
//     if (error)
//     {
//         return 0;
//     }

//     return doc["pattern"];
// }

// // Kiểm tra line có ở giữa không (sensors 4-6)
// bool LineFollower::isLineInCenter(unsigned int pattern)
// {
//     // Kiểm tra cảm biến giữa (4, 5, 6) có phát hiện line
//     return (pattern & 0b00001110000) != 0;
// }

// void LineFollower::processLinePattern(unsigned int pattern)
// {

//     const float SET_POINT = 5.0; // Điểm đặt (cảm biến giữa)

//     int activeBits = 0;
//     int weightedSum = 0;
//     int minSensor = 11, maxSensor = -1;

//     for (int i = 0; i < 11; i++)
//     {
//         if (pattern & (1 << i))
//         {
//             activeBits++;
//             weightedSum += i;
//             if (i < minSensor)
//                 minSensor = i;
//             if (i > maxSensor)
//                 maxSensor = i;
//         }
//     }

//     float linePosition = (activeBits > 0) ? (float)weightedSum / activeBits : SET_POINT;
//     int sensorSpread = (maxSensor > minSensor) ? (maxSensor - minSensor) : 0;

//     // --- DEBUG 1: Dữ liệu cảm biến ---
//     Serial.print("DEBUG: Pattern = ");
//     Serial.print(pattern, BIN);
//     Serial.print(" (Dec: ");
//     Serial.print(pattern);
//     Serial.print(") | Active: ");
//     Serial.print(activeBits);
//     Serial.print(" | Pos: ");
//     Serial.print(linePosition);

//     // ========== XỬ LÝ TRƯỜNG HỢP ĐẶC BIỆT ==========
//     // 1. Mất đường hoàn toàn
//     if (pattern == 0)
//     {
//         Serial.println(" -> LOST LINE (STOP)");
//         motor->driveDifferential(0, 0);
//         lastError = 0.0;
//         integral = 0.0;
//         Serial.println("----------------------------------------");
//         return;
//     }

//     // 2. Giao lộ (tất cả cảm biến phát hiện line)
//     else if (pattern == 0b11111111111)
//     {
//         Serial.println(" -> INTERSECTION DETECTED (SLOW FORWARD)");
//         motor->driveDifferential(Config::BASE_SPEED / 2, Config::BASE_SPEED / 2);
//         lastError = 0.0;
//         integral = 0.0;
//         Serial.println("----------------------------------------");
//         return;
//     }
//     // 3. RẼ VUÔNG GÓC PHẢI (cảm biến 6-10 phát hiện line)
//     // Pattern ví dụ: 0b11111000000 (sensors 6-10)
//     else if (linePosition >= 6 && activeBits >= 6 )
//     {
//         Serial.println(" -> SHARP RIGHT TURN DETECTED");
//         // Kiểm tra vật cản bên phải
//         if (checkSideObstaclesWhileTurning(false))
//         {
//             Serial.println("   WARNING: Obstacle on right side!");
//             motor->driveDifferential(0, 0);
//         }
//         else
//         {
//             // Tốc độ quay
//             int leftSpeed = Config::BASE_SPEED * 1.3;
//             int rightSpeed = -Config::BASE_SPEED / 3;

//             Serial.print("   Turning Right -> Left: ");
//             Serial.print(leftSpeed);
//             Serial.print(", Right: ");
//             Serial.println(rightSpeed);

//             motor->driveDifferential(leftSpeed, rightSpeed);

//             // Vòng lặp quay
//             Serial.println("   ENTERING RIGHT TURN LOOP");
//             while (true)
//             {
//                 // Đọc pattern mới
//                 unsigned int currentPattern = readLinePattern();

//                 // *** KIỂM TRA MẤT LINE - THOÁT NGAY ***
//                 if (currentPattern == 0)
//                 {
//                     Serial.println("   LINE LOST DURING TURN - STOPPING!");
//                     motor->driveDifferential(0, 0);
//                     break;
//                 }
//                 if (currentPattern != 0)
//                 {
//                     Serial.print("   Loop Pattern: ");
//                     Serial.println(currentPattern, BIN);

//                     // Kiểm tra line đã về giữa chưa
//                     if (isLineInCenter(currentPattern))
//                     {
//                         Serial.println("   LINE CENTERED - BREAKING LOOP");
//                         break;
//                     }
//                 }
//                 // Tiếp tục quay
//                 motor->driveDifferential(leftSpeed, rightSpeed);
//             }

//             Serial.println("   EXITED RIGHT TURN LOOP");
//         }

//         lastError = 0.0;
//         integral = 0.0;
//         Serial.println("----------------------------------------");
//         return;
//     }

//     // 4. RẼ VUÔNG GÓC TRÁI (cảm biến 0-4 phát hiện line)
//     // Pattern ví dụ: 0b00000011111 (sensors 0-4)
//     else if (linePosition <= 4 && activeBits >= 6)
//     {
//         Serial.println(" -> SHARP LEFT TURN DETECTED");
//         // Kiểm tra vật cản bên trái
//         if (checkSideObstaclesWhileTurning(true))
//         {
//             Serial.println("   WARNING: Obstacle on left side!");
//             motor->driveDifferential(0, 0);
//         }
//         else
//         {
//             // Tốc độ quay
//             int leftSpeed = -Config::BASE_SPEED / 3;
//             int rightSpeed = Config::BASE_SPEED * 1.3;

//             Serial.print("   Turning Left -> Left: ");
//             Serial.print(leftSpeed);
//             Serial.print(", Right: ");
//             Serial.println(rightSpeed);

//             motor->driveDifferential(leftSpeed, rightSpeed);

//             // Vòng lặp quay
//             Serial.println("   ENTERING LEFT TURN LOOP");

//             while (true)
//             {
//                 // Đọc pattern mới
//                 unsigned int currentPattern = readLinePattern();

//                 // *** KIỂM TRA MẤT LINE - THOÁT NGAY ***
//                 if (currentPattern == 0)
//                 {
//                     Serial.println("   LINE LOST DURING TURN - STOPPING!");
//                     motor->driveDifferential(0, 0);
//                     break;
//                 }

//                 if (currentPattern != 0)
//                 {
//                     Serial.print("   Loop Pattern: ");
//                     Serial.println(currentPattern, BIN);

//                     // Kiểm tra line đã về giữa chưa
//                     if (isLineInCenter(currentPattern))
//                     {
//                         Serial.println("   LINE CENTERED - BREAKING LOOP");
//                         break;
//                     }
//                 }
//                 // Tiếp tục quay
//                 motor->driveDifferential(leftSpeed, rightSpeed);
//             }

//             Serial.println("   EXITED LEFT TURN LOOP");
//         }

//         lastError = 0.0;
//         integral = 0.0;
//         Serial.println("----------------------------------------");
//         return;
//     }

//     // ========== TÍNH TOÁN PID CHO ĐIỀU CHỈNH ĐƯỜNG THÔNG THƯỜNG ==========

//     float error = linePosition - SET_POINT;

//     // P-term
//     float proportional = Config::Kp * error;

//     // I-term
//     float integralTerm = Config::Ki * integral;

//     // D-term
//     float derivative = Config::Kd * (error - lastError);

//     // Tổng Correction
//     float correction = proportional + integralTerm + derivative;

//     // Giới hạn đầu ra PID
//     if (correction > Config::MAX_CORRECTION)
//     {
//         correction = Config::MAX_CORRECTION;
//     }
//     else if (correction < -Config::MAX_CORRECTION)
//     {
//         correction = -Config::MAX_CORRECTION;
//     }

//     // Cập nhật lỗi cuối cùng
//     lastError = error;

//     // Tốc độ cơ sở
//     int baseSpeed = Config::BASE_SPEED;

//     // Áp dụng độ điều chỉnh
//     int leftSpeed = baseSpeed + (int)correction;
//     int rightSpeed = baseSpeed - (int)correction;

//     // Giới hạn tốc độ
//     leftSpeed = constrain(leftSpeed, -Config::MAX_SPEED, Config::MAX_SPEED);
//     rightSpeed = constrain(rightSpeed, -Config::MAX_SPEED, Config::MAX_SPEED);

//     // --- DEBUG 2: Kết quả PID và Tốc độ ---
//     Serial.print(" | Error: ");
//     Serial.print(error);
//     Serial.print(" | Correction (PID): ");
//     Serial.print(correction);
//     Serial.println(" -> PID FOLLOW");

//     Serial.print("DEBUG: Set Speed -> Left: ");
//     Serial.print(leftSpeed);
//     Serial.print(", Right: ");
//     Serial.println(rightSpeed);
//     Serial.println("----------------------------------------");

//     motor->driveDifferential(leftSpeed, rightSpeed);
// }

// void LineFollower::update()
// {
//     if (!lineSerial->available())
//         return;

//     DeserializationError error = deserializeJson(doc, *lineSerial);
//     if (error)
//     {
//         Serial.print("JSON parse error: ");
//         Serial.println(error.c_str());
//         return;
//     }

//     unsigned int pattern = doc["pattern"];
//     processLinePattern(pattern);
// }
//  if (pattern != 0b11111111111)
//     {
//         inIntersection = false;
        
//     }
//     // 2. Giao lộ (tất cả cảm biến phát hiện line)
//     if (pattern == 0b11111111111) 
//     {
//         if (inIntersection == false) 
//         {
//             inIntersection = true;
//             intersectionCount++;            
//             Serial.print(" -> INTERSECTION: "); Serial.println(intersectionCount);           
//             switch (intersectionCount)
//             {
//                 case 1: // ĐI THẲNG
//                     Serial.println(" -> CASE 1: DI THANG (SLOW)");
//                     motor->driveDifferential(Config::BASE_SPEED, Config::BASE_SPEED);
//                     lastError = 0.0;
//                     integral = 0.0;
//                     break;

//                 case 2: // RẼ PHẢI 90 ĐỘ
//                     {
//                         Serial.println(" -> CASE 2: RE PHAI");
//                         int leftSpeed = Config::BASE_SPEED * 1.3;
//                         int rightSpeed = -Config::BASE_SPEED / 3;
//                         motor->driveDifferential(leftSpeed, rightSpeed);
//                         unsigned long timeout = millis();
//                 while (1)
//                 {
//                     if(pattern & 0b00000100000 == 0){
//                         break;
//                     }
//                     if(millis() - timeout > 1000) break;
//                 }
                
//                 while(1){
//                     pattern = readLinePattern();
//                     if(pattern & 0b00001110000 > 0){
//                         Serial.println("   LINE CENTERED - BREAKING LOOP");
//                         break;
//                     }
//                     if (millis() - timeout > 2000) break;
//                 }
//                         lastError = 0.0;
//                         integral = 0.0;                  
//                     }
//                     break;

//                 case 3: // RẼ TRÁI 90 ĐỘ
//                     {
//                         Serial.println(" -> CASE 3: RE TRAI");
                        
//                         int rightSpeed = Config::BASE_SPEED / 3;
//                         int leftSpeed = -Config::BASE_SPEED * 1.3;
//                         motor->driveDifferential(leftSpeed, rightSpeed);
//                         delay(400); // Tinh chỉnh số này
//                         lastError = 0.0;
//                         integral = 0.0;
//                     }
//                     break;
                    
//                 default:
//                     intersectionCount = 0;
//                     break;
//             }
//             return true;
//         }
//         else
//         {
//             return true;  
//         }
//     }


//...........................................

// #include "LineFollower.h"
// #include "Config.h"
// #include "NetworkConfig.h"

// // --- SỬA 1: Thêm dòng ": client(espClient)" để khởi tạo biến MQTT ---
// LineFollower::LineFollower(MotorController *motorController, SensorManager *sensorManager, HardwareSerial *lineSerialPort) 
// {
//     motor = motorController;
//     sensor = sensorManager;
//     lineSerial = lineSerialPort;
//     intersectionCount = 0;      
//     lastIntersectionTime = 0;   
//     resetPID();
// }

// void LineFollower::init()
// {
//     lineSerial->begin(115200, SERIAL_8N1, Config::LINE_RX_PIN, Config::LINE_TX_PIN);
//     Serial.println("Line Follower initialized on separate UART (11 Sensors)");
// }
// void LineFollower::resetPID()
// {
//     lastError = 0.0;
//     integral = 0.0;
// }

// bool LineFollower::checkSideObstaclesWhileTurning(bool isTurningLeft)
// {
//     if (isTurningLeft) return sensor->checkLeftSideObstacle(Config::OBSTACLE_DISTANCE_CM);
//     else return sensor->checkRightSideObstacle(Config::OBSTACLE_DISTANCE_CM);
// }

// unsigned int LineFollower::readLinePattern()
// {
//     if (!lineSerial->available()) return 0;
//     DeserializationError error = deserializeJson(doc, *lineSerial);
//     if (error) return 0;
//     return doc["pattern"];
// }

// bool LineFollower::isLineInCenter(unsigned int pattern)
// {
//     return (pattern & 0b00001110000) != 0;
// }

// void LineFollower::executeTurn(bool isLeft)
// {
//     const char* turnName = isLeft ? "Left" : "Right";
//     int leftSpeed, rightSpeed;

//     if (isLeft) {
//         Serial.println(" -> SHARP LEFT TURN DETECTED");
//         leftSpeed = -Config::BASE_SPEED / 3;
//         rightSpeed = Config::BASE_SPEED * 1.3;
//     } else {
//         Serial.println(" -> SHARP RIGHT TURN DETECTED");
//         leftSpeed = Config::BASE_SPEED * 1.3;
//         rightSpeed = -Config::BASE_SPEED / 3;
//     }

//     if (checkSideObstaclesWhileTurning(isLeft))
//     {
//         Serial.print("   WARNING: Obstacle on ");
//         Serial.print(isLeft ? "left" : "right");
//         Serial.println(" side!");
//         motor->driveDifferential(0, 0);
//     }
//     else
//     {
//         Serial.print("   Turning "); Serial.print(turnName);
//         Serial.print(" -> Left: "); Serial.print(leftSpeed);
//         Serial.print(", Right: "); Serial.println(rightSpeed);

//         motor->driveDifferential(leftSpeed, rightSpeed);

//         Serial.print("   ENTERING "); Serial.print(isLeft ? "LEFT" : "RIGHT"); Serial.println(" TURN LOOP");

//         while (true)
//         {
//             unsigned int currentPattern = readLinePattern();

//             if (currentPattern == 0)
//             {
//                 Serial.println("   LINE LOST DURING TURN - STOPPING!");
//                 motor->driveDifferential(0, 0);
//                 break;
//             }

//             if (currentPattern != 0)
//             {
//                 Serial.print("   Loop Pattern: ");
//                 Serial.println(currentPattern, BIN);

//                 if (isLineInCenter(currentPattern))
//                 {
//                     Serial.println("   LINE CENTERED - BREAKING LOOP");
//                     break;
//                 }
//             }
//             motor->driveDifferential(leftSpeed, rightSpeed);
//         }
//         Serial.print("   EXITED "); Serial.print(isLeft ? "LEFT" : "RIGHT"); Serial.println(" TURN LOOP");
//     }

//     resetPID();
//     Serial.println("----------------------------------------");
// }

// bool LineFollower::handleSpecialCases(unsigned int pattern, float linePosition, int activeBits)
// {
//     // 1. Mất đường hoàn toàn
//     if (pattern == 0)
//     {
//         Serial.println(" -> LOST LINE (STOP)");
//         motor->driveDifferential(0, 0);
//         resetPID();
//         Serial.println("----------------------------------------");
//         return true;
//     }
//       if (pattern != 0b11111111111)
//     {
//         inIntersection = false;
        
//     }
//     // 2. Giao lộ (tất cả cảm biến phát hiện line)
//     if (pattern == 0b11111111111) 
//     {
//         if (inIntersection == false) 
//         {
//             inIntersection = true;
//             intersectionCount++;            
//             Serial.print(" -> INTERSECTION: "); Serial.println(intersectionCount);           
//             switch (intersectionCount)
//             {
//                 case 1: // ĐI THẲNG
//                     Serial.println(" -> CASE 1: DI THANG (SLOW)");
//                     motor->driveDifferential(Config::BASE_SPEED, Config::BASE_SPEED);
//                     lastError = 0.0;
//                     integral = 0.0;
//                     break;

//                 case 2: // RẼ PHẢI 90 ĐỘ
//                     {
//                         Serial.println(" -> CASE 2: RE PHAI");
//                         int leftSpeed = Config::BASE_SPEED * 1.3;
//                         int rightSpeed = -Config::BASE_SPEED / 3;
//                         motor->driveDifferential(leftSpeed, rightSpeed);

//                         delay(400);

//                         lastError = 0.0;
//                         integral = 0.0;                  
//                     }
//                     break;

//                 case 3: // RẼ TRÁI 90 ĐỘ
//                     {
//                         Serial.println(" -> CASE 3: RE TRAI");
                        
//                         int rightSpeed = Config::BASE_SPEED / 3;
//                         int leftSpeed = -Config::BASE_SPEED * 1.3;
//                         motor->driveDifferential(leftSpeed, rightSpeed);
//                         delay(400); // Tinh chỉnh số này
//                         lastError = 0.0;
//                         integral = 0.0;
//                     }
//                     break;
                    
//                 default:
//                     intersectionCount = 0;
//                     break;
//             }
//             return true;
//         }
//         else
//         {
//             return true;  
//         }
//     }
//     // 3. RẼ VUÔNG GÓC PHẢI
//     else if (linePosition >= 6 && activeBits >= 6)
//     {
//         executeTurn(false); // false = Right
//         return true;
//     }

//     // 4. RẼ VUÔNG GÓC TRÁI
//     else if (linePosition <= 4 && activeBits >= 6)
//     {
//         executeTurn(true); // true = Left
//         return true;
//     }

//     return false;
// }

// void LineFollower::processLinePattern(unsigned int pattern)
// {
//     const float SET_POINT = 5.0; 
//     int activeBits = 0;
//     int weightedSum = 0;
//     int minSensor = 11, maxSensor = -1;

//     for (int i = 0; i < 11; i++)
//     {
//         if (pattern & (1 << i))
//         {
//             activeBits++;
//             weightedSum += i;
//             if (i < minSensor) minSensor = i;
//             if (i > maxSensor) maxSensor = i;
//         }
//     }

//     float linePosition = (activeBits > 0) ? (float)weightedSum / activeBits : SET_POINT;
//     Serial.print("DEBUG: Pattern = ");
//     Serial.print(pattern, BIN);
//     Serial.print(" (Dec: "); Serial.print(pattern);
//     Serial.print(") | Active: "); Serial.print(activeBits);
//     Serial.print(" | Pos: "); Serial.print(linePosition);

//     if (handleSpecialCases(pattern, linePosition, activeBits)) 
//     {
//         return;
//     }

//     // ========== TÍNH TOÁN PID ==========
//     float error = linePosition - SET_POINT;
//     float proportional = Config::Kp * error;
//     float integralTerm = Config::Ki * integral;
//     float derivative = Config::Kd * (error - lastError);
//     float correction = proportional + integralTerm + derivative;

//     if (correction > Config::MAX_CORRECTION) correction = Config::MAX_CORRECTION;
//     else if (correction < -Config::MAX_CORRECTION) correction = -Config::MAX_CORRECTION;

//     lastError = error;

//     int leftSpeed = Config::BASE_SPEED + (int)correction;
//     int rightSpeed = Config::BASE_SPEED - (int)correction;

//     leftSpeed = constrain(leftSpeed, -Config::MAX_SPEED, Config::MAX_SPEED);
//     rightSpeed = constrain(rightSpeed, -Config::MAX_SPEED, Config::MAX_SPEED);

//     Serial.print(" | Error: "); Serial.print(error);
//     Serial.print(" | Correction (PID): "); Serial.print(correction);
//     Serial.println(" -> PID FOLLOW");

//     Serial.print("DEBUG: Set Speed -> Left: "); Serial.print(leftSpeed);
//     Serial.print(", Right: "); Serial.println(rightSpeed);
//     Serial.println("----------------------------------------");

//     motor->driveDifferential(leftSpeed, rightSpeed);

// }

// void LineFollower::update()
// {
//     if (!lineSerial->available()) return;

//     DeserializationError error = deserializeJson(doc, *lineSerial);
//     if (error)
//     {
//         Serial.print("JSON parse error: ");
//         Serial.println(error.c_str());
//         return;
//     }

//     unsigned int pattern = doc["pattern"];
//     processLinePattern(pattern);
// }
