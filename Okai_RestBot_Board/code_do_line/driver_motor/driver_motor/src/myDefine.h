#ifndef MY_DEFINE_H
#define MY_DEFINE_H

/*map timer
uart - timer3
millis - timer1
hall speed - timer0
*/

/*--------------------------------------INCLUDE------------------------------------------*/
#include "json.h"
#include "N76E003.h"
#include "math.h"
#include "hall_speed.h"
#include "millis.h"

/*--------------------------------------DEFINE------------------------------------------*/
// PWM
#define PWM1_EN PWM2_P10_OUTPUT_ENABLE
#define PWM2_EN PWM1_P11_OUTPUT_ENABLE
#define PWM3_EN PWM0_P12_OUTPUT_ENABLE
#define PWM4_EN PWM3_P00_OUTPUT_ENABLE
#define PWM1_DIS PWM2_P10_OUTPUT_DISABLE
#define PWM2_DIS PWM1_P11_OUTPUT_DISABLE
#define PWM3_DIS PWM0_P12_OUTPUT_DISABLE
#define PWM4_DIS PWM3_P00_OUTPUT_DISABLE
#define PWM1_CH 2
#define PWM2_CH 1
#define PWM3_CH 0
#define PWM4_CH 3
#define PWM1_PORT P10
#define PWM2_PORT P11
#define PWM3_PORT P12
#define PWM4_PORT P00
#define PWM1_MODE P10_PushPull_Mode
#define PWM2_MODE P11_PushPull_Mode
#define PWM3_MODE P12_PushPull_Mode
#define PWM4_MODE P00_PushPull_Mode

// DIR
#define Dir1_MODE P15_PushPull_Mode
#define Dir2_MODE P01_PushPull_Mode
#define Dir3_MODE P13_PushPull_Mode
#define Dir4_MODE P14_PushPull_Mode
#define Dir1 P15
#define Dir2 P01
#define Dir3 P13
#define Dir4 P14

// ADC
#define ADC_AQTSIG1 ADC_ADCAQT0
#define ADC_AQTSIG2 ADC_ADCAQT6
#define ADC_AQTSIGT ADC_ADCAQT5
#define ADC_SIG1_EN Enable_ADC_AIN0 //P17
#define ADC_SIG2_EN Enable_ADC_AIN6 //P03
#define ADC_SIGT_EN Enable_ADC_AIN5 //P04
#define ADC_SIG1 ADC_CH0
#define ADC_SIG2 ADC_CH6
#define ADC_SIGT ADC_CH5

// Min-Max ADC
#define inMin 0
#define inMmax 4080
#define outMin 0
#define outMmax 180

/*--------------------------------------VARIABLE------------------------------------------*/
// Internal ram
uint8_t i = 0;
bit_t flagJson = 0;
bit_t flagMotor = 0;
uint16_t sig1 = 0;
uint16_t sig2 = 0;
uint16_t sigT = 0;


// xdata
/* |0 -> AngleA | |1 -> sAngleA|  |2 -> AngleB | |3 -> sAngleB|  |4 -> MotorA | |5 -> sMotorA|  |6 -> MotorB | |7 -> sMotorB| */
__xdata volatile uint8_t dataRx[8];
__xdata volatile char json[50];
__xdata volatile uint32_t previous = 0;
__xdata volatile uint32_t timeDelay = 1000;

/*--------------------------------------SETUP------------------------------------------*/
#define PWM_Congfig(Mode, Port, En) \
   do                               \
   {                                \
      Mode;                         \
      Port = 0;                     \
      En;                           \
   } while (0)
#define DIR_Congfig(Dir, Mode) \
   do                          \
   {                           \
      Mode;                    \
      Dir = 0;                 \
   } while (0)

#define ADC_Congfig(DIV, AQT)    \
   do                            \
   {                             \
      ADC_ConvertTime(DIV, AQT); \
      clr_ADCF;                  \
      set_ADCS;                  \
   } while (0)

/*--------------------------------------LOOP------------------------------------------*/
/* change heading */
#define HandleADC(CH, TARGET, DIR, PWM_EN, PWM_DIS)              \
   do                                                            \
   {                                                             \
      ADC_SelectChannel(CH);                                     \
      ADC_ClearFlag();                                           \
      ADC_StartConv();                                           \
      while (ADC_IsBusy())                                       \
         ;                                                       \
      uint16_t value = map(ADC_GetData(CH), 0, 4086, 0, 180);    \
      ADC_Disable();                                             \
      if (value != TARGET)                                       \
      {                                                          \
         if (value > TARGET)                                     \
         {                                                       \
            PWM_EN;                                              \
            DIR = 1;                                             \
         }                                                       \
         else                                                    \
         {                                                       \
            PWM_EN;                                              \
            DIR = 0;                                             \
         }                                                       \
      }                                                          \
      else                                                       \
      {                                                          \
         PWM_DIS;                                                \
      }                                                          \
   } while (0)

/* PWM change */
#define HandlePWM(CHANNEL, TARGET)      \
   do                                   \
   {                                    \
      PWM_SetDuty((CHANNEL), (TARGET)); \
   } while (0)

/* change direction*/
#define HandleDir(DIR, TARGET) \
   do                          \
   {                           \
      if (DIR != TARGET)       \
         DIR = TARGET;         \
   } while (0)

#endif