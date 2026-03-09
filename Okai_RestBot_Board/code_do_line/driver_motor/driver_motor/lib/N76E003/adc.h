/* adc.h */
#ifndef ADC_H_
#define ADC_H_

#ifdef __C51__
#include "myIntType.h"
#else
#include <stdint.h>
#endif

#define ADC_SINGLE      1
#define ADC_CONTINUOUS  2
#define VBG             8
#define VTEMP           9
#define VLDO           10

#define ADC_HWT_PWM0CH0    0
#define ADC_HWT_PWM0CH2    1
#define ADC_HWT_PWM0CH4    2
#define ADC_HWT_STADC    3

#define ADC_HWT_FALLINGEDGE    0
#define ADC_HWT_RISINGEDGE     1
#define ADC_HWT_CENTRAL        2
#define ADC_HWT_END            3

#define ADC_INT_HALFDONE       0
#define ADC_INT_CONTDONE       1
#define ADC_INT_SINGLE         3

#define ADCSlowSpeed           0
#define ADCHighSpeed           1

#define ADC_CH0                 0
#define ADC_CH1                 1
#define ADC_CH2                 2
#define ADC_CH3                 3
#define ADC_CH4                 4
#define ADC_CH5                 5
#define ADC_CH6                 6
#define ADC_CH7                 7
#define ADC_BANDGAP             8

#define ADC_ADCDIV1                 0
#define ADC_ADCDIV2                 1
#define ADC_ADCDIV4                 2
#define ADC_ADCDIV8                 3

#define ADC_ADCAQT0                 0
#define ADC_ADCAQT1                 1
#define ADC_ADCAQT2                 2
#define ADC_ADCAQT3                 3
#define ADC_ADCAQT4                 4
#define ADC_ADCAQT5                 5
#define ADC_ADCAQT6                 6
#define ADC_ADCAQT7                 7



void ADC_StartConv(void);
uint8_t ADC_IsBusy(void);
uint16_t ADC_GetData(uint8_t channel);
void ADC_ClearFlag(void);
void ADC_Disable(void);
void ADC_ConvertTime(uint8_t u8ADCDIV, uint8_t u8ADCAQT);
void ADC_ComapreMode(uint8_t u8ADCCMPEN, uint16_t u16ADCCMPVALUE);
void ADC_Init(uint8_t channel, uint8_t div);
void ADC_SelectChannel(uint8_t channel);
#endif