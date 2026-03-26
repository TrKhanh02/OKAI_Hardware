#include <Arduino.h>
#include <ArduinoJson.h>

#include "WebManager.h"
#include "LEDManager.h"
#define LED_PIN 5
#define LED_COUNT 60
WebManager web;
LEDManager led(LED_PIN, LED_COUNT);
/* ============================= */
/* xử lý command từ web */
/* ============================= */

void handleCommand(const char *msg)
{
  JsonDocument doc;

  DeserializationError err = deserializeJson(doc, msg);

  if (err)
  {
    Serial.println("JSON parse error");
    return;
  }

  const char *cmd = doc["cmd"];

  /* đổi màu LED */

  if (strcmp(cmd, "color") == 0)
  {
    int r = doc["r"];
    int g = doc["g"];
    int b = doc["b"];

    led.setColor(r, g, b);
  }

  /* hiệu ứng rainbow */

  if (strcmp(cmd, "rainbow") == 0)
  {
    led.setEffect(LED_RAINBOW);
  }
  /* tắt LED */
  if (strcmp(cmd, "off") == 0)
  {
    led.setColor(0, 0, 0);
  }
}
void setup()
{
  Serial.begin(115200);
  /* khởi động LED */
  led.begin();
  led.setColor(255, 0, 0);
  led.setEffect(LED_RAINBOW);
  /* khởi động wifi + web */

  web.begin("LED_CONTROL", "12345678");
  /* nhận message websocket */
  web.onRawMessage(handleCommand);

  Serial.println("System ready");
}
void loop()
{
  web.update();
  led.update();
}