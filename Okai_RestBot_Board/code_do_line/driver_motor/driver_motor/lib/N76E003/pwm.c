
#include "N76E003.h"
#include "pwm.h"

#if useFpwm
static uint16_t period;

/*
    fPWM = fPWM_clk / (CNR + 1)
    fPWM_clk = Fsys / 8 (chia 8 cố định)
*/
void PWM_Init(uint16_t Fpwm)
{
    PWM_CLOCK_FSYS;
    PWM_IMDEPENDENT_MODE;
    PWM_CLOCK_DIV_8;

    period = PWM_FSYS_DIV_8/Fpwm - 1;

    PWMPH = (period >> 8) & 0xFF;
    PWMPL = period & 0xFF;

    set_LOAD;
    set_PWMRUN;
}

void PWM_SetDuty(uint8_t channel, uint8_t dutyPercent)
{
    uint16_t cmr;
    if (dutyPercent == 0) {
        cmr = 0;
    } else {
        cmr = ((uint32_t)dutyPercent * (period + 1)) / 100 - 1;
    }
    if (cmr > period) cmr = period;

    switch (channel) {
        case 0: PWM0H = cmr >> 8; PWM0L = cmr; break;
        case 1: PWM1H = cmr >> 8; PWM1L = cmr; break;
        case 2: PWM2H = cmr >> 8; PWM2L = cmr; break;
        case 3: PWM3H = cmr >> 8; PWM3L = cmr; break;
        case 4: set_SFRPAGE; PWM4H = cmr >> 8; PWM4L = cmr; clr_SFRPAGE; break;
        case 5: set_SFRPAGE; PWM5H = cmr >> 8; PWM5L = cmr; clr_SFRPAGE; break;
    }

    set_LOAD;
}

uint8_t PWM_GetDuty(uint8_t channel)
{
    uint16_t cmr = 0;
    switch (channel) {
        case 0: cmr = ((uint16_t)PWM0H << 8) | PWM0L; break;
        case 1: cmr = ((uint16_t)PWM1H << 8) | PWM1L; break;
        case 2: cmr = ((uint16_t)PWM2H << 8) | PWM2L; break;
        case 3: cmr = ((uint16_t)PWM3H << 8) | PWM3L; break;
        case 4: set_SFRPAGE; cmr = ((uint16_t)PWM4H << 8) | PWM4L; clr_SFRPAGE; break;
        case 5: set_SFRPAGE; cmr = ((uint16_t)PWM5H << 8) | PWM5L; clr_SFRPAGE; break;
    }

    if (cmr == 0) return 0;
    return (uint8_t)(((uint32_t)(cmr + 1) * 100) / (period + 1));
}


#else

static uint16_t g_period;

/*
  fPWM​=fPWM_clk​​/(CNR+1)
 */
void PWM_Init(uint16_t period)
{
    PWM_IMDEPENDENT_MODE;
    PWM_CLOCK_DIV_8;                       // Fpwm_clk = Fsys/8
    PWMPH = (period >> 8) & 0xFF;
    PWMPL = period & 0xFF;
    g_period = period;

    set_LOAD;
    set_PWMRUN;
}

void PWM_SetDuty(uint8_t channel, uint8_t dutyPercent)
{
    uint16_t cmr;
    if (dutyPercent == 0) {
        cmr = 0;
    } else {
        cmr = ((uint32_t)(dutyPercent) * (g_period+1)) / 100 - 1;
    }
    if (cmr > g_period) cmr = g_period;

    switch(channel) {
        case 0: PWM0H = cmr >> 8; PWM0L = cmr; break;
        case 1: PWM1H = cmr >> 8; PWM1L = cmr; break;
        case 2: PWM2H = cmr >> 8; PWM2L = cmr; break;
        case 3: PWM3H = cmr >> 8; PWM3L = cmr; break;
        case 4: set_SFRPAGE; PWM4H = cmr >> 8; PWM4L = cmr; clr_SFRPAGE; break;
        case 5: set_SFRPAGE; PWM5H = cmr >> 8; PWM5L = cmr; clr_SFRPAGE; break;
    }

    set_LOAD;
}


uint8_t PWM_GetDuty(uint8_t channel)
{
    uint16_t cmr = 0;
    switch(channel) {
        case 0: cmr = ((uint16_t)PWM0H << 8) | PWM0L; break;
        case 1: cmr = ((uint16_t)PWM1H << 8) | PWM1L; break;
        case 2: cmr = ((uint16_t)PWM2H << 8) | PWM2L; break;
        case 3: cmr = ((uint16_t)PWM3H << 8) | PWM3L; break;
        case 4: set_SFRPAGE; cmr = ((uint16_t)PWM4H << 8) | PWM4L; clr_SFRPAGE; break;
        case 5: set_SFRPAGE; cmr = ((uint16_t)PWM5H << 8) | PWM5L; clr_SFRPAGE; break;
    }

    if (cmr == 0) return 0;  // duty = 0%
    return (uint8_t)(((uint32_t)(cmr + 1) * 100) / (g_period + 1));
}


#endif