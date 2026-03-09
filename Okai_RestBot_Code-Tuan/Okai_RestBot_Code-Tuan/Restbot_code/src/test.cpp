// // =========================================================
// // Code ESP32 Đọc và Giải Mã JSON từ Serial (UART)
// // =========================================================

// // Cần thư viện ArduinoJson để giải mã dữ liệu JSON.
// // Vui lòng cài đặt thư viện này qua Library Manager (phiên bản 6.x).
// #include <ArduinoJson.h>

// // Định nghĩa tốc độ truyền Serial.
// // PHẢI KHỚP với tốc độ truyền của mạch gửi (mạch có hàm sendDataJSON).
// #define BAUD_RATE 115200 

// // Kích thước bộ đệm (buffer) tĩnh cho tài liệu JSON.
// // Kích thước này phải đủ lớn để chứa chuỗi JSON mà mạch gửi tạo ra.
// // Nếu chuỗi JSON của bạn dài, hãy tăng kích thước này lên.
// // Ví dụ JSON của bạn có khoảng 120-150 byte, nên 256 là an toàn.
// const size_t JSON_DOC_SIZE = 256; 

// // Biến lưu trữ dữ liệu JSON thô nhận được qua Serial.
// String jsonBuffer = ""; 

// /**
//  * @brief Giải mã chuỗi JSON đã nhận và in ra các giá trị.
//  * * @param jsonString Chuỗi JSON thô (ví dụ: {"d1":1.2, "d2":-1.0, ...}\n)
//  */
// void processJsonData(const String& jsonString) {
//   // Tạo tài liệu JSON tĩnh trên Stack. 
//   StaticJsonDocument<JSON_DOC_SIZE> doc;

//   // Giải mã chuỗi JSON
//   // deserializeJson trả về một mã lỗi nếu không thành công
//   DeserializationError error = deserializeJson(doc, jsonString);

//   // Kiểm tra lỗi giải mã
//   if (error) {
//     Serial.print(F("Lỗi giải mã JSON: "));
//     Serial.println(error.f_str());
//     Serial.print(F("Dữ liệu nhận được: "));
//     Serial.println(jsonString);
//     return; // Dừng xử lý nếu có lỗi
//   }
  
//   // ==============================================================
//   // 1. TRÍCH XUẤT DỮ LIỆU (Đọc các trường dữ liệu)
//   // ==============================================================
  
//   // Đọc các giá trị khoảng cách (d1, d2, d3) dưới dạng double.
//   // Nếu trường không tồn tại, nó sẽ trả về giá trị mặc định là 0.0, 
//   // nhưng an toàn hơn là kiểm tra hoặc dùng giá trị mặc định.
//   double d1 = doc["d1"] | 0.0; 
//   double d2 = doc["d2"] | 0.0;
//   double d3 = doc["d3"] | 0.0;
  
//   // Đọc giá trị chênh lệch TDOA
//   double tdoa_diff = doc["tdoa_diff"] | 0.0; 

//   // ==============================================================
//   // 2. IN DỮ LIỆU ĐÃ TRÍCH XUẤT
//   // ==============================================================
//   Serial.println("----------------------------------------------");
//   Serial.println("  DỮ LIỆU JSON ĐÃ NHẬN:");
//   Serial.print("  d1 (Khoảng cách 1): ");
//   Serial.println(d1);
//   Serial.print("  d2 (Khoảng cách 2): ");
//   Serial.println(d2);
//   Serial.print("  d3 (Khoảng cách 3): ");
//   Serial.println(d3);
  
//   // Kiểm tra và in giá trị TDOA (Chỉ xuất hiện nếu tdoa_data_valid là true ở mạch gửi)
//   if (doc.containsKey("tdoa_diff")) {
//     Serial.print("  TDOA Difference (tdoa_diff): ");
//     Serial.println(tdoa_diff, 0); // In số nguyên, 0 chữ số sau thập phân
//   } else {
//     Serial.println("  TDOA Difference: (Không có trong gói dữ liệu này)");
//   }
//   Serial.println("----------------------------------------------");
// }

// void setup() {
//   // Khởi tạo Serial (UART0) để giao tiếp với máy tính (để debug)
//   Serial.begin(BAUD_RATE);
//   delay(100);
//   Serial.println("==============================================");
//   Serial.println("  ESP32 - JSON Serial Receiver Started");
//   Serial.println("==============================================");
//   Serial.println("  Chờ dữ liệu JSON từ mạch gửi...");
//   Serial.println("  Đảm bảo tốc độ Baud Rate là: " + String(BAUD_RATE));
// }

// void loop() {
//   // Kiểm tra xem có dữ liệu đến qua cổng Serial (UART0) không
//   while (Serial.available() > 0) {
//     char incomingChar = Serial.read();
    
//     // Thêm ký tự vào buffer
//     jsonBuffer += incomingChar;
    
//     // Dữ liệu JSON từ mạch gửi kết thúc bằng ký tự xuống dòng ('\n') 
//     // do hàm 'Serial.println()' sau 'serializeJson'
//     if (incomingChar == '\n') {
//       // Đã nhận đủ một chuỗi JSON. Bắt đầu giải mã.
//       processJsonData(jsonBuffer);
      
//       // Xóa buffer để chuẩn bị cho chuỗi JSON tiếp theo
//       jsonBuffer = ""; 
//     }
//   }
// }
