#ifndef _HALL_SPEED_H_
#define _HALL_SPEED_H_

#include "N76E003.h"


#define HALL_COUNT 4

void Timer0_ISR (void) __interrupt (1);
void HallSpeed_Init(void);
uint16_t HallSpeed_GetCount(uint8_t index);
uint16_t HallSpeed_GetSpeed(uint8_t index);

#endif
