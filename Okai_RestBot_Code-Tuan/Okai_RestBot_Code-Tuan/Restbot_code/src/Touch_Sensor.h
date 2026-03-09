#ifndef CAMBIEN_CHAM_H
#define CAMBIEN_CHAM_H

#include <Arduino.h>
#include <Wire.h>
#include <PCF8575.h> 

extern int lastButtonState;
extern unsigned long lastDebounceTime;
extern const unsigned long debounceDelay;
enum CHAM_PIN
{
    sensorcham_1 = P4,
    sensorcham_2 = P5,
    sensorcham_3 = P6,
    sensorcham_4 = P7,
    sensorcham_5 = P8,
    sensorcham_6 = P9,

};

extern PCF8575 pcf8575;

void CAMBIEN_CHAM_SETUP(int sensorcham);
void CAMBIEN_CHAM_LOOP(int sensorcham);

#endif