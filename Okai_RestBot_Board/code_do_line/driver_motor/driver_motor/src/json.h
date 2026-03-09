#ifndef JSON_H
#define JSON_H
#include "stdint.h"

uint8_t parse_json(const char *buf, int *AngleA, int *sAngleA, int *AngleB, int *sAngleB, int *MotorA, int *sMotorA, int *MotorB, int *sMotorB);

#endif