#ifndef PWM_H
#define PWM_H


#define useFpwm 1

#include "N76E003.h"

#if useFpwm
void PWM_Init(uint16_t Fpwm); //
#else
void PWM_Init(uint16_t period); //
#endif

// Đặt duty (0–100 %)
/*
 PWM5_P03_OUTPUT_ENABLE
 PWM4_P01_OUTPUT_ENABLE
 PWM3_P04_OUTPUT_ENABLE
 PWM3_P00_OUTPUT_ENABLE
 PWM2_P05_OUTPUT_ENABLE
 PWM2_P10_OUTPUT_ENABLE
 PWM1_P14_OUTPUT_ENABLE
 PWM1_P11_OUTPUT_ENABLE
 PWM0_P12_OUTPUT_ENABLE
 PWM5_P15_OUTPUT_ENABLE
*/
void PWM_SetDuty(uint8_t channel, uint8_t dutyPercent);

uint8_t PWM_GetDuty(uint8_t channel);

#endif
