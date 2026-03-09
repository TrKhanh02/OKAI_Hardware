#include "Line_Sensor.h"
#include <PCF8575.h>
void CAMBIEN_LINE_SETUP(int sensorLINE)
{
    Wire.begin();
    pcf8575.begin();
    pcf8575.pinMode(sensorLINE, INPUT);
    Serial.begin(115200);
}
int CAMBIEN_LINE_DOC(int sensorLINE)
{
    int reading = pcf8575.digitalRead(sensorLINE);
    Serial.println(reading);
    return reading;
}
