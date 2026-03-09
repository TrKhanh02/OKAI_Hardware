#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <FastLED.h>

#define N 8
#define DATA_PIN 27
#define BRIGHTNESS 255
#define LED_TYPE WS2812
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 100

extern CRGB leds[N];

extern CRGBPalette16 currentPalette;
extern TBlendType currentBlending;

void LED_setup();
uint8_t mapBrightness(int inputBrightness);
void LED_NUMBER(int STT_LED, int MAU, int DO_SANG);
void SetupTotallyRandomPalette();
void SetupBlackAndWhiteStripedPalette();
void SetupPurpleAndGreenPalette();
void ChangePalettePeriodically();
void FillLEDsFromPaletteColors(uint8_t colorIndex);
void runLedEffect(int effectType, unsigned long duration);

#endif // LED_H