// #define runMain 1

// #if runMain == 1
// /* Code 1 */
// /*============================include============================*/
// #include "N76E003.h"
// #include "isr.h"
// #include "line.h"
// #include "ir.h"
// #include "motor.h"
// #include "encoder.h"
// #include "serial_pid.h"

// /*============================Define============================*/
// #define dutyBase1 1500/* +600 */
// #define dutyBase2 1380/* +600 */
// #define minDuty1 0
// #define minDuty2 0
// #define maxDuty1 dutyBase1 + 1800
// #define maxDuty2 dutyBase2 + 1800
// #define Freq 160
// #define alpha 0.6
// #define flagWhile 1

// /*============================Variable============================*/
// /* map error */
// __xdata const int16_t i16errorTable[32] = {
//     // 0–31
//     [1] = 2500,    // [0 0 0 0 1] =  2500
//     [3] = 1600,    // [0 0 0 1 1] = 1400
//     [2] = 1400,    // [0 0 0 1 0] = 1200
//     [6] = 1000,     // [0 0 1 1 0] = 800
//     [4] = 0,       // [0 0 1 0 0] = 0
//     [12] = -1000,   // [0 1 1 0 0] =  -800
//     [8] = -1400,   // [0 1 0 0 0] = -1200
//     [24] = -1600,  // [1 1 0 0 0] =  -1400
//     [16] = -2500}; // [1 0 0 0 0] =  -2500

// /* state pd control */
// uint8_t ui8enablePID = 1;

// /* gain */
// __xdata uint8_t ui8Kp = 3;
// __xdata uint8_t ui8Kd = 2;

// /* use p,d */
// __xdata int16_t i16Error;

// /* use d */
// __xdata int16_t i16DeltaError;
// __xdata int16_t i16PerviousError;

// /* heading */
// enum heading
// {
//   headingLeft,
//   headingRight,
//   headingForward
// };
// enum heading stateHeading = headingForward;

// /*============================Fuction============================*/
// /* get error */
// int16_t getErrorFast(uint8_t s5, uint8_t s4, uint8_t s3, uint8_t s2, uint8_t s1)
// {
//   uint8_t idx = (s1 << 4) | (s2 << 3) | (s3 << 2) | (s4 << 1) | (s5);
//   return i16errorTable[idx];
// }

// /* handle line */
// // void handleline(uint8_t s5, uint8_t s4, uint8_t s3, uint8_t s2, uint8_t s1)
// // {
// // }

// /* PID control */
// // void pidControl(uint8_t ui8EnPID)
// // {
// // }

// void main()
// {
//   MODIFY_HIRC(HIRC_166);

//   InitialUART0_Timer3(2400);
//   printf("START PID LINE FOLLOWER \n");

//   IR_Line_Init(LINE1_SELECT);
//   IR_Line_Init(LINE2_SELECT);
//   IR_Line_Init(LINE3_SELECT);
//   IR_Line_Init(LINE4_SELECT);
//   IR_Line_Init(LINE5_SELECT);

//   IR_Obstacle_Init(IR1_SELECT);
//   IR_Obstacle_Init(IR2_SELECT);
//   IR_Obstacle_Init(IR3_SELECT);

//   Motor_Freq(Freq);
//   Motor_Init(MOTOR1_SELECT);
//   Motor_Init(MOTOR2_SELECT);
//   PWM_Scale(PWM_SCALE_100);

//   IR_Encoder_Init(EN1_SELECT);
//   IR_Encoder_Init(EN2_SELECT);

//   stateHeading = headingRight;
//   Motor_Control_Dir(MOTOR1_SELECT, DIR_FORWARD, dutyBase1);
//   Motor_Control_Dir(MOTOR2_SELECT, DIR_FORWARD, dutyBase2);

//   while (flagWhile)
//   {
//     /* READ SENSOR */
//     uint8_t ui8Sensor5 = IR_Line_Read(LINE5_SELECT);
//     uint8_t ui8Sensor4 = IR_Line_Read(LINE4_SELECT);
//     uint8_t ui8Sensor3 = IR_Line_Read(LINE3_SELECT);
//     uint8_t ui8Sensor2 = IR_Line_Read(LINE2_SELECT);
//     uint8_t ui8Sensor1 = IR_Line_Read(LINE1_SELECT);
//     uint8_t ui8SensorData = IR_Line_Read(LINE_DATA_SELECT);
//     uint8_t ui8SensorClock = IR_Line_Read(LINE_CLOCK_SELECT);

//     /* HANDEL HEADING */
//     // Right
//     if (((ui8Sensor5 == 0 && ui8Sensor4 == 0 && ui8Sensor3 == 1 && ui8Sensor2 == 1 && ui8Sensor1 == 1) ||
//          (ui8Sensor5 == 0 && ui8Sensor4 == 1 && ui8Sensor3 == 1 && ui8Sensor2 == 1 && ui8Sensor1 == 1) ||
//          ui8Sensor5 == 1 && ui8Sensor4 == 1 && ui8Sensor3 == 1 && ui8Sensor2 == 1 && ui8Sensor1 == 1) &&
//         stateHeading == headingRight)
//     {
//       ui8enablePID = 0;
//       printf("TURN RIGHT\n");
//       uint8_t flagRight = 0;
//       Timer0_Delay1ms(150);
//       printf("delay ne");
//       while (1)
//       {
//         Motor_Control_Dir(MOTOR1_SELECT, DIR_FORWARD, dutyBase1 + 1000);
//         Motor_Control_Dir(MOTOR2_SELECT, DIR_BACKWARD, dutyBase2 + 1000);
//         ui8Sensor5 = IR_Line_Read(LINE5_SELECT);
//         ui8Sensor4 = IR_Line_Read(LINE4_SELECT);
//         ui8Sensor3 = IR_Line_Read(LINE3_SELECT);
//         ui8Sensor2 = IR_Line_Read(LINE2_SELECT);
//         ui8Sensor1 = IR_Line_Read(LINE1_SELECT);
//         printf("[%d%d%d%d%d]\n", ui8Sensor5, ui8Sensor4, ui8Sensor3, ui8Sensor2, ui8Sensor1);
//         if (ui8Sensor3 == 0)
//         {
//           flagRight = 1;
//         }
//         if (flagRight == 1)
//         {
//           if (ui8Sensor3)
//           {
//             break;
//           }
//         }
//       }
//       ui8enablePID = 1;
//     }
//     // left
//     if (((ui8Sensor5 == 1 && ui8Sensor4 == 1 && ui8Sensor3 == 1 && ui8Sensor2 == 0 && ui8Sensor1 == 0) ||
//          (ui8Sensor5 == 1 && ui8Sensor4 == 1 && ui8Sensor3 == 1 && ui8Sensor2 == 1 && ui8Sensor1 == 1)) &&
//         stateHeading == headingLeft)
//     {
//       ui8enablePID = 0;
//       printf("TURN LEFT\n");
//       while (ui8Sensor4 || ui8Sensor5)
//       {
//         ui8Sensor5 = IR_Line_Read(LINE5_SELECT);
//         ui8Sensor4 = IR_Line_Read(LINE4_SELECT);
//         ui8Sensor3 = IR_Line_Read(LINE3_SELECT);
//         ui8Sensor2 = IR_Line_Read(LINE2_SELECT);
//         ui8Sensor1 = IR_Line_Read(LINE1_SELECT);
//         Motor_Control_Dir(MOTOR1_SELECT, DIR_BACKWARD, dutyBase1 + 1300);
//         Motor_Control_Dir(MOTOR2_SELECT, DIR_FORWARD, dutyBase2 + 1300);
//         printf("[%d%d%d%d%d]\n", ui8Sensor5, ui8Sensor4, ui8Sensor3, ui8Sensor2, ui8Sensor1);
//       }
//       ui8enablePID = 1;
//     }
//     // FORWARD
//     if (ui8enablePID)
//     {
//       /* Map erorr */
//       i16Error = getErrorFast(IR_Line_Read(LINE5_SELECT), IR_Line_Read(LINE4_SELECT), IR_Line_Read(LINE3_SELECT), IR_Line_Read(LINE2_SELECT), IR_Line_Read(LINE1_SELECT));

//       /* delta error */
//       i16DeltaError = alpha * i16Error - (1 - alpha) * i16PerviousError;
//       i16PerviousError = i16Error;

//       /* Pterm */
//       __xdata int16_t i16Pterm = (int16_t)i16Error / ui8Kp;

//       /* Dterm */
//       __xdata int16_t i16Dterm = (int16_t)i16DeltaError / ui8Kd;

//       /* Output data */
//       __xdata int16_t i16Output = (int16_t)i16Pterm + i16Dterm;

//       /* duty motor 1 & 2 */
//       __xdata int16_t i16Duty1 = dutyBase1 - i16Output;
//       __xdata int16_t i16Duty2 = dutyBase2 + i16Output;

//       if (i16Duty1 < minDuty1)
//         i16Duty1 = minDuty1;

//       if (i16Duty2 < minDuty2)
//         i16Duty2 = minDuty2;

//       Motor_Control_Dir(MOTOR1_SELECT, DIR_FORWARD, i16Duty1);
//       Motor_Control_Dir(MOTOR2_SELECT, DIR_FORWARD, i16Duty2);

//       printf("[%d%d%d%d%d-%d|%d] E:%d|D1:%d|D2:%d\n", ui8Sensor5, ui8Sensor4, ui8Sensor3, ui8Sensor2, ui8Sensor1, ui8SensorData, ui8SensorClock, i16Error, i16Duty1 - dutyBase1, i16Duty2 - dutyBase2);
//     }
//   }
// }

// #elif runMain == 2
// /* Code 2 */

// #include "N76E003.h"
// // #include "isr.h"
// // #include "line.h"
// // #include "ir.h"
// #include "motor.h"
// #include "encoder.h"
// // #include "serial_pid.h"

// void main(void)
// {
//   // Modify Clock system
//   MODIFY_HIRC(HIRC_166);
//   InitialUART0_Timer3(115200);
//   P10_PushPull_Mode;
//   // P10 = 1;
//   while (1)
//   {
//     P10 = 1;
//     Timer0_Delay1ms(100);
//     P10 = 0;
//     Timer0_Delay1ms(100);
//     printf("nahy\n");
//   }
// }
// #else
// /* Code test */
// #include "N76E003.h"
// // #include "isr.h"
// // #include "line.h"
// // #include "ir.h"
// // #include "motor.h"
// #include "encoder.h"
// // #include "serial_pid.h"

// void main(void)
// {
//   // Modify Clock system
//   MODIFY_HIRC(HIRC_166);

//   IR_Encoder_Init(EN1_SELECT);

//   InitialUART0_Timer3(115200);

//   while (1)
//   {

//     printf("sensor: %d\n", IR_Encoder_Read(EN1_SELECT));
//     // Timer0_Delay1ms(10);
//   }
// }
// #endif