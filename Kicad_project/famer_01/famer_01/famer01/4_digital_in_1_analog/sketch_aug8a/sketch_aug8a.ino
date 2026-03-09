const int analogPin = 33; // GPIO33

void setup() {
  Serial.begin(115200); // Mở cổng serial để in dữ liệu
}

void loop() {
  int analogValue = analogRead(analogPin); // Đọc giá trị analog
  float voltage = analogValue * (3.3 / 4095.0); // Chuyển sang đơn vị volt

  Serial.print("Analog value: ");
  Serial.print(analogValue);
  Serial.print(" -> Voltage: ");
  Serial.print(voltage, 3); // 3 chữ số sau dấu phẩy
  Serial.println(" V");

  delay(500); // Đọc mỗi 500ms
}