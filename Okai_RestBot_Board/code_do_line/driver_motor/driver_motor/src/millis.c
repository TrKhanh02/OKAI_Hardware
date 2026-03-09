#include "millis.h"

static uint32_t timePeak;

void Timer1_ISR(void) __interrupt(3)
{
    TH1 = HIBYTE(TIMER_DIV12_VALUE_1ms);
    TL1 = LOBYTE(TIMER_DIV12_VALUE_1ms);
    // P00 ^= 1;
    timePeak++;
}

void Millis_Init(void)
{
    //P00_OpenDrain_Mode;
    TIMER1_MODE1_ENABLE;
    clr_TF1;
    clr_T1M;

    TH1 = HIBYTE(TIMER_DIV12_VALUE_1ms);
    TL1 = LOBYTE(TIMER_DIV12_VALUE_1ms);

    set_ET1; // cho phép ngắt Timer1
    set_EA;  // cho phép ngắt toàn cục
    set_TR1; // bật Timer1
}

uint32_t Millis(void)
{
    return timePeak;
}
