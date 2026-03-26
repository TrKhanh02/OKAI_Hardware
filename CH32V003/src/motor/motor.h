#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>

#define MOTOR_PWM_MAX   1000

void Motor_Init(void);
void Motor_SetPWM(uint8_t channel, uint16_t duty);  

#endif