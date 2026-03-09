/* adc.c */
#include <N76E003.h>
#include "adc.h"

// /**
//   * @brief This configures ADC Sampling time
//   * @param[u8ADCDIV] Decides the ADC clock devider value. Value from 0 ~ 3, devider is from 1 ~ 128, default value is 0 means Fadc = Fsys/1
//   * @param[u8ADCAQT] Decides the ADC acquisition time base to add sampling time for ADC input, value is from 0 ~ 7, time = (4*u8ADCAQT+6)/Fadc, default value is 10/Fsys = 417ns.
//   * @return  None
//   * @note
//   * @example ADC_ConvertTime(ADC_ADCDIV2,ADC_ADCAQT5);

void ADC_ConvertTime(uint8_t u8ADCDIV, uint8_t u8ADCAQT)
{
    clr_ADCF;
    set_ADCS;

    SFRS = 0;
    ADCCON1 &= 0x8F;
    ADCCON1 |= (u8ADCDIV & 0x07) << 4;
    ADCCON2 &= 0xF1;
    ADCCON2 |= (u8ADCAQT & 0x07) << 1;
}

void ADC_StartConv(void)
{
    ADCS = 1;
}

uint8_t ADC_IsBusy(void)
{
    return !ADCF;
}

// uint16_t ADC_GetData(uint8_t channel)
// {
//     uint16_t raw[6];
//     raw[channel] = ((uint16_t)ADCRH << 4) | (ADCRL & 0x0F);
//     return raw[channel];
// }

uint16_t ADC_GetData(uint8_t channel)
{
    __idata uint16_t raw[6];
    __idata static uint16_t filtered[6] = {0};
    static uint8_t initialized = 0;

    raw[channel] = ((uint16_t)ADCRH << 4) | (ADCRL & 0x0F);

    if (!(initialized & (1 << channel)))
    {
        filtered[channel] = raw[channel];
        initialized |= (1 << channel); // Đánh dấu đã khởi tạo
    }
    else
    {
        filtered[channel] = ((filtered[channel] << 3) - filtered[channel] + raw[channel]) >> 3;
    }

    return filtered[channel];
}

void ADC_ClearFlag(void)
{
    ADCF = 0;
}

void ADC_Disable(void)
{
    ADCCON1 &= 0xFE;
}

void ADC_ComapreMode(uint8_t u8ADCCMPEN, uint16_t u16ADCCMPVALUE)
{
    SFRS = 0;
    ADCMPL = u16ADCCMPVALUE & 0x000F;
    ADCMPH = u16ADCCMPVALUE >> 4;
    if (u8ADCCMPEN)
    {
        set_ADCMPEN;
    }
    else
    {
        clr_ADCMPEN;
    }
}

void ADC_Init(uint8_t channel, uint8_t div)
{
    switch (channel)
    {
    case ADC_CH0:
        Enable_ADC_AIN0;
        ADC_ConvertTime(div, ADC_ADCAQT0);
        clr_ADCF;
        set_ADCS;
        break;
    case ADC_CH1:
        Enable_ADC_AIN1;
        ADC_ConvertTime(div, ADC_ADCAQT1);
        clr_ADCF;
        set_ADCS;
        break;
    case ADC_CH2:
        Enable_ADC_AIN2;
        ADC_ConvertTime(div, ADC_ADCAQT2);
        clr_ADCF;
        set_ADCS;
        break;
    case ADC_CH3:
        Enable_ADC_AIN3;
        ADC_ConvertTime(div, ADC_ADCAQT3);
        clr_ADCF;
        set_ADCS;
        break;
    case ADC_CH4:
        Enable_ADC_AIN4;
        ADC_ConvertTime(div, ADC_ADCAQT4);
        clr_ADCF;
        set_ADCS;
        break;
    case ADC_CH5:
        Enable_ADC_AIN5;
        ADC_ConvertTime(div, ADC_ADCAQT5);
        clr_ADCF;
        set_ADCS;
        break;
    case ADC_CH6:
        Enable_ADC_AIN6;
        ADC_ConvertTime(div, ADC_ADCAQT6);
        clr_ADCF;
        set_ADCS;
        break;
    case ADC_CH7:
        Enable_ADC_AIN7;
        ADC_ConvertTime(div, ADC_ADCAQT7);
        clr_ADCF;
        set_ADCS;
        break;
    case ADC_BANDGAP:
        Enable_ADC_BandGap;
        clr_ADCF;
        set_ADCS;
        break;
    }
}

void ADC_SelectChannel(uint8_t channel)
{
    switch (channel)
    {
    case ADC_CH0:
        Enable_ADC_AIN0;
        break;
    case ADC_CH1:
        Enable_ADC_AIN1;
        break;
    case ADC_CH2:
        Enable_ADC_AIN2;
        break;
    case ADC_CH3:
        Enable_ADC_AIN3;
        break;
    case ADC_CH4:
        Enable_ADC_AIN4;
        break;
    case ADC_CH5:
        Enable_ADC_AIN5;
        break;
    case ADC_CH6:
        Enable_ADC_AIN6;
        break;
    case ADC_CH7:
        Enable_ADC_AIN7;
        break;
    case ADC_BANDGAP:
        Enable_ADC_BandGap;
        break;
    }
}