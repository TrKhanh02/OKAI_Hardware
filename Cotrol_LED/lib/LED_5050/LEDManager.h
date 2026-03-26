#ifndef LED_MANAGER_H
#define LED_MANAGER_H

#include <Arduino.h>
#include <FastLED.h>

enum LedEffect
{
    LED_OFF,
    LED_STATIC,
    LED_RAINBOW,
    LED_BLINK
};

class LEDManager
{
public:
    LEDManager(uint8_t pin, uint16_t count);

    void begin();
    void update();

    void setColor(uint8_t r, uint8_t g, uint8_t b);
    void setEffect(LedEffect effect);
    void setBrightness(uint8_t brightness);

private:
    void effectStatic();
    void effectRainbow();
    void effectBlink();

    uint8_t _pin;
    uint16_t _count;

    CRGB *_leds;

    LedEffect _effect;

    uint8_t _r;
    uint8_t _g;
    uint8_t _b;

    uint8_t _hue;
    bool _blinkState;

    uint32_t _lastUpdate;
};

#endif