#include "LEDManager.h"

LEDManager::LEDManager(uint8_t pin, uint16_t count)
{
    _pin = pin;
    _count = count;

    _effect = LED_OFF;

    _r = 255;
    _g = 255;
    _b = 255;

    _hue = 0;
    _blinkState = false;
}

void LEDManager::begin()
{
    _leds = new CRGB[_count];

    FastLED.addLeds<WS2812, 5, GRB>(_leds, _count); 
    FastLED.setBrightness(150);
}

void LEDManager::setBrightness(uint8_t brightness)
{
    FastLED.setBrightness(brightness);
}

void LEDManager::setColor(uint8_t r, uint8_t g, uint8_t b)
{
    _r = r;
    _g = g;
    _b = b;
}

void LEDManager::setEffect(LedEffect effect)
{
    _effect = effect;
}

void LEDManager::update()
{
    switch (_effect)
    {
        case LED_OFF:
            fill_solid(_leds, _count, CRGB::Black);
            break;

        case LED_STATIC:
            effectStatic();
            break;

        case LED_RAINBOW:
            effectRainbow();
            break;

        case LED_BLINK:
            effectBlink();
            break;
    }

    FastLED.show();
}

void LEDManager::effectStatic()
{
    fill_solid(_leds, _count, CRGB(_r, _g, _b));
}

void LEDManager::effectRainbow()
{
    fill_rainbow(_leds, _count, _hue++, 5);
}

void LEDManager::effectBlink()
{
    if (millis() - _lastUpdate > 500)
    {
        _lastUpdate = millis();
        _blinkState = !_blinkState;

        if (_blinkState)
            fill_solid(_leds, _count, CRGB(_r, _g, _b));
        else
            fill_solid(_leds, _count, CRGB::Black);
    }
}