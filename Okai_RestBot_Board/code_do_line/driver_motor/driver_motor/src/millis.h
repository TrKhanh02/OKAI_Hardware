#ifndef MILLIS_H
#define MILLIS_H

#include "N76E003.h"


void Timer1_ISR (void) __interrupt (3);
void Millis_Init(void);
uint32_t Millis(void);


#endif