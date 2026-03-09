#include "Touch_Sensor.h"
#include <PCF8575.h> 
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 25;
void CAMBIEN_CHAM_SETUP(int sensorcham)
{
    Wire.begin();
    pcf8575.begin();
    pcf8575.pinMode(sensorcham, INPUT_PULLUP);
    Serial.begin(9600);
}
void CAMBIEN_CHAM_LOOP(int sensorcham)
{
    int reading = pcf8575.digitalRead(sensorcham);

    if (reading != lastButtonState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        if (reading == 0)
        {
            Serial.println("Press");
        }
        else
        {
        }
    }

    lastButtonState = reading;
}
