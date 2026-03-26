#include "motor.h"
#include <ch32v00x.h>
void Motor_Init(void)
{
    // Cấp Clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | 
                           RCC_APB2Periph_GPIOD | RCC_APB2Periph_TIM1, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure = {0}; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    // Cấu hình GPIO
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; GPIO_Init(GPIOC, &GPIO_InitStructure);

    // Dừng Timer trước khi cấu hình để đảm bảo đồng bộ
    TIM_Cmd(TIM1, DISABLE);
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure = {0};
    TIM_TimeBaseStructure.TIM_Period = 999;        
    TIM_TimeBaseStructure.TIM_Prescaler = 47;         
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

    //Cấu hình PWM Mode
    TIM_OCInitTypeDef TIM_OCInitStructure = {0};
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;         
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);
    TIM_OC2Init(TIM1, &TIM_OCInitStructure);
    TIM_OC3Init(TIM1, &TIM_OCInitStructure);
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
    TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
    TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);
    TIM_ARRPreloadConfig(TIM1, ENABLE);
    TIM_InternalClockConfig(TIM1);
    TIM_GenerateEvent(TIM1, TIM_EventSource_Update); 
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
    TIM_Cmd(TIM1, ENABLE);
}
//set duty
void Motor_SetPWM(uint8_t channel, uint16_t duty)
{
    if (duty > MOTOR_PWM_MAX) duty = MOTOR_PWM_MAX;

    switch(channel) {
        case 1: TIM1->CH1CVR = duty; break; // PD2
        case 2: TIM1->CH2CVR = duty; break; // PA1
        case 3: TIM1->CH3CVR = duty; break; // PC3
        case 4: TIM1->CH4CVR = duty; break; // PC4
    }
}