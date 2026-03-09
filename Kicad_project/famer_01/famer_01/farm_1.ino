#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>
#include <math.h>
#include "MP3.h"   // === Thư viện phát nhạc MP3 ===

// ===== LCD ILI9341 =====
#define TFT_CS   15
#define TFT_DC   2
#define TFT_MOSI 23
#define TFT_CLK  18
#define TFT_RST  -1
#define TFT_MISO -1
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);

// ===== DHT11 =====
#define DHTPIN 21
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ===== 74HC595 =====
#define LATCH_PIN 22
#define CLOCK_PIN 4
#define DATA_PIN  19

// ===== WiFi & MQTT =====
const char* ssid        = "OKAI";
const char* password    = "prv@101024";
const char* mqtt_server = "a94798199e0f48808fa4ad0169db6e34.s1.eu.hivemq.cloud";
const int   mqtt_port   = 8883;
const char* mqtt_user   = "farmokai3";
const char* mqtt_pass   = "Farmokai2003@";

#define MQTT_TOPIC       "OKAI_ESP_FARM"
#define MQTT_TOPIC_RELAY "OKAI_ESP_FARM/relay"

WiFiClientSecure espClient;
PubSubClient client(espClient);

// ===== Cảm biến analog =====
#define PIN_35 35
#define PIN_34 34
#define PIN_VP 36
#define PIN_VN 39
#define PIN_33 33

// ===== Biến toàn cục =====
unsigned long previousMillis = 0;
const long interval = 10000;

int adc35, adc34, adcVP, adcVN, adc33;
int digital1 = 0, digital2 = 0, digital3 = 0, digital4 = 0;
float dhtTemp = NAN, dhtHum = NAN;
byte relayState = 0b00001111;
int lcdScreen = 0;

// ===== Ngưỡng riêng cho từng cảm biến =====
const int NGUONG_ADC35 = 1500;
const int NGUONG_ADC34 = 1800;
const int NGUONG_VP    = 2000;
const int NGUONG_VN    = 2200;
const float TEMP_CAO   = 32.0;
const float TEMP_THAP  = 15.0;
const float DOAM_CAO   = 85.0;
const float DOAM_THAP  = 30.0;

// ===== WiFi =====
void setup_wifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.println(WiFi.localIP());
}

// ===== 74HC595 =====
void setRelays(byte data) {
  relayState = data;
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data);
  digitalWrite(LATCH_PIN, HIGH);
}

// ===== MQTT Callback =====
void mqttCallback(char* topic, byte* message, unsigned int length) {
  // Chuyển message thành String
  String msg;
  for (unsigned int i = 0; i < length; i++) {
    msg += (char)message[i];
    Serial.print((char)message[i]);  // In từng ký tự nhận được
  }
  Serial.println();  // Xuống dòng sau khi in xong toàn bộ message

  // In topic ra Serial
  Serial.print("Received on topic: ");
  Serial.println(topic);

  // Xử lý JSON nếu topic là relay
  if (String(topic) == MQTT_TOPIC_RELAY) {
    StaticJsonDocument<200> doc;
    if (!deserializeJson(doc, msg)) { // nếu JSON hợp lệ
      if (doc.containsKey("relay")) {
        int val = doc["relay"];
        if (val >= 0 && val <= 15) setRelays(val);
      }
    }
  }
}


// ===== MQTT Connect =====
void connect_to_broker() {
  while (!client.connected()) {
    String clientId = "ESP32-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_pass))
      client.subscribe(MQTT_TOPIC_RELAY);
    else delay(2000);
  }
}

// ===== Đọc ADC =====
void readADC() {
  adc35 = analogRead(PIN_35);
  adc34 = analogRead(PIN_34);
  adcVP = analogRead(PIN_VP);
  adcVN = analogRead(PIN_VN);
}

// ===== Đọc GPIO33 =====
void readGPIO33() {
  adc33 = analogRead(PIN_33);

  struct Range { int min; int max; const char *bits; };
  Range table[] = {
    {-20, 30, "0000"}, {30, 330, "0001"}, {330, 730, "0010"}, {730, 1080, "0011"},
    {1080, 1500, "0100"}, {1500, 1730, "0101"}, {1730, 1900, "0110"}, {1900, 2130, "0111"},
    {2130, 2430, "1000"}, {2430, 2610, "1001"}, {2610, 2800, "1010"}, {2800, 2930, "1011"},
    {2930, 3040, "1100"}, {3040, 3170, "1101"}, {3170, 3270, "1110"}, {3270, 4076, "1111"}
  };

  const char *bits = "0000";
  for (int i = 0; i < 16; i++)
    if (adc33 >= table[i].min && adc33 < table[i].max) {
      bits = table[i].bits;
      break;
    }

  digital1 = bits[0] == '1';
  digital2 = bits[1] == '1';
  digital3 = bits[2] == '1';
  digital4 = bits[3] == '1';
}

// ===== DHT =====
void readDHT() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (!isnan(h) && !isnan(t)) {
    dhtHum = h;
    dhtTemp = t;
  }
}

// ===== Gửi MQTT =====
void sendMQTT() {
  char payload[400];
  snprintf(payload, sizeof(payload),
           "{\"ADC35\":%d,\"ADC34\":%d,\"VP\":%d,\"VN\":%d,"
           "\"Digital1\":%d,\"Digital2\":%d,\"Digital3\":%d,\"Digital4\":%d,"
           "\"DHT_Temp\":%.2f,\"DHT_Hum\":%.2f,\"RelayState\":%d}",
           adc35, adc34, adcVP, adcVN,
           digital1, digital2, digital3, digital4,
           dhtTemp, dhtHum, relayState);
  client.publish(MQTT_TOPIC, payload);
  Serial.println(payload);
}

// ===== LCD =====
void displayLCD() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(2);

  if (lcdScreen == 0) {
    tft.setCursor(10, 10);  tft.setTextColor(ILI9341_CYAN);   tft.printf("Temp: %.1f C", dhtTemp);
    tft.setCursor(10, 40);  tft.setTextColor(ILI9341_GREEN);  tft.printf("Humi: %.1f %%", dhtHum);
    tft.setCursor(10, 70);  tft.setTextColor(ILI9341_YELLOW); tft.printf("A1: %d", adc35);
    tft.setCursor(10, 100); tft.printf("A2: %d", adc34);
    tft.setCursor(10, 130); tft.printf("A3: %d", adcVP);
    tft.setCursor(10, 160); tft.printf("A4: %d", adcVN);
  } else {
    int y = 10, step = 25;
    tft.setTextColor(ILI9341_MAGENTA);
    tft.setCursor(10, y);      tft.printf("D1: %d", digital1);
    tft.setCursor(10, y+=step);tft.printf("D2: %d", digital2);
    tft.setCursor(10, y+=step);tft.printf("D3: %d", digital3);
    tft.setCursor(10, y+=step);tft.printf("D4: %d", digital4);
  }
}

// ===== Phát âm thanh theo cảm biến =====
void playBySensor() {
  // Analog cảm biến (0–3)
  if (adc35 > NGUONG_ADC35) mp3Task(0);   // cambien1.mp3
  if (adc34 > NGUONG_ADC34) mp3Task(1);   // cambien2.mp3
  if (adcVP > NGUONG_VP)    mp3Task(2);   // cambien3.mp3
  if (adcVN > NGUONG_VN)    mp3Task(3);   // cambien4.mp3

  // Digital cảm biến (4–7)
  if (digital1) mp3Task(4);
  if (digital2) mp3Task(5);
  if (digital3) mp3Task(6);
  if (digital4) mp3Task(7);

  // DHT (8–11)
  if (dhtTemp > TEMP_CAO) mp3Task(8);       // nhietdocao.mp3
  else if (dhtTemp < TEMP_THAP) mp3Task(9); // nhietdothap.mp3

  if (dhtHum > DOAM_CAO) mp3Task(10);       // doamcao.mp3
  else if (dhtHum < DOAM_THAP) mp3Task(11); // doamthap.mp3
}

// ===== SETUP =====
void setup() {
  Serial.begin(115200);
  setup_wifi();
  dht.begin();

  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  setRelays(relayState);

  espClient.setInsecure();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(mqttCallback);

  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(ILI9341_BLACK);

  // === Khởi tạo MP3 ===
  mp3_setup();
}

// ===== LOOP =====
void loop() {
  client.loop();
  if (!client.connected()) connect_to_broker();
  mp3_loop();  // Duy trì phát nhạc

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    readADC();
    readGPIO33();
    readDHT();
    playBySensor();  // 
    sendMQTT();
    displayLCD();
    lcdScreen = 1 - lcdScreen;
  }
}
