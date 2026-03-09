#define runMain 0

#if runMain
#include "N76E003.h"
#include "myDefine.h"

void main(void)
{
    MODIFY_HIRC(HIRC_166);
    UART0_Init(115200); // timer3
    printf("HELLO\n");
    PWM_Init(1000);
    // PWM_Congfig(PWM1_MODE, PWM1_PORT, PWM1_EN);
    PWM_Congfig(PWM2_MODE, PWM2_PORT, PWM2_EN);
    // PWM_Congfig(PWM3_MODE, PWM3_PORT, PWM3_EN);
    // PWM_Congfig(PWM4_MODE, PWM4_PORT, PWM4_EN);
    // PWM_SetDuty(PWM1_CH, 50);
    // // dataRx[1] = PWM_GetDuty(PWM1_CH);
    PWM_SetDuty(PWM2_CH, 50);
    // // dataRx[3] = PWM_GetDuty(PWM2_CH);
    // PWM_SetDuty(PWM3_CH, 50);
    // // dataRx[5] = PWM_GetDuty(PWM3_CH);
    // PWM_SetDuty(PWM4_CH, 50);
    // dataRx[7] = PWM_GetDuty(PWM4_CH);
    // DIR_Congfig(Dir1, Dir1_MODE);
    DIR_Congfig(Dir2, Dir2_MODE);
    // DIR_Congfig(Dir3, Dir3_MODE);
    // DIR_Congfig(Dir4, Dir4_MODE);
    // ADC_Congfig(ADC_ADCDIV1, ADC_AQTSIG1);
    // ADC_Congfig(ADC_ADCDIV1, ADC_AQTSIG2);
    // //ADC_Congfig(ADC_ADCDIV1, ADC_AQTSIGT);
    // HallSpeed_Init();
    Millis_Init();

    while (1)
    {
        while (UART0_Available() > 0)
        {
            char c = UART0_GetChar();
            // printf("%c",c);
            if (c == '|')
            {
                json[i] = '\0'; // kết thúc chuỗi
                flagJson = 1;
                UART0_ResetBuffer();
                i = 0; // reset index cho gói mới
            }
            else
            {
                json[i++] = c;
            }
            flagJson = 1;
        }

        if (flagJson)
        {
            // 10,50,10,50,1,50,1,30|
            parse_json(json, &dataRx[0], &dataRx[1], &dataRx[2], &dataRx[3], &dataRx[4], &dataRx[5], &dataRx[6], &dataRx[7]);
            for (int i = 0; i <= 8; i++)
            {
                if (i == 8)
                {
                    printf("\n");
                }
                else
                {
                    printf("\n [%d] = %d \n", i, dataRx[i]);
                }
            }
            flagJson = 0;
            flagMotor = 1;
        }

        if (1)
        {
            /* PWM change */
            HandlePWM(PWM1_CH, dataRx[1]);
            HandlePWM(PWM2_CH, dataRx[3]);
            HandlePWM(PWM3_CH, dataRx[5]);
            HandlePWM(PWM4_CH, dataRx[7]);

            /* change heading */
            HandleADC(ADC_SIG1, dataRx[0], Dir1, PWM1_EN, PWM1_DIS);
            HandleADC(ADC_SIG2, dataRx[2], Dir2, PWM2_EN, PWM2_DIS);

            /* change direction*/
            HandleDir(Dir3, dataRx[4]);
            HandleDir(Dir4, dataRx[6]);

            if (Millis() - previous >= timeDelay)
            {

                previous = Millis();
                printf("%u,%u,%u,%u|\n", HallSpeed_GetSpeed(0), HallSpeed_GetSpeed(1), HallSpeed_GetSpeed(2), HallSpeed_GetSpeed(3));
            }
        }
    }
}
#else

#include "N76E003.h"
#include "myDefine.h"

#define MAX_JSON_SIZE 64

void main(void)
{
    unsigned long lastPacketTime = 0; 
    
    // Delay nhẹ khởi động để tránh lỗi nạp (Anti-Brick)
    unsigned int safety_i, safety_j;
    for(safety_i = 0; safety_i < 100; safety_i++) for(safety_j = 0; safety_j < 1000; safety_j++);

    MODIFY_HIRC(HIRC_166);
    UART0_Init(2400); 
    PWM_Init(1000);
    
    PWM_Congfig(PWM3_MODE, PWM3_PORT, PWM3_EN);
    PWM_Congfig(PWM4_MODE, PWM4_PORT, PWM4_EN);
    
    PWM_SetDuty(PWM3_CH, 0);
    dataRx[5] = PWM_GetDuty(PWM3_CH);
    PWM_SetDuty(PWM4_CH, 0);
    dataRx[7] = PWM_GetDuty(PWM4_CH);
    
    DIR_Congfig(Dir3, Dir3_MODE);
    DIR_Congfig(Dir4, Dir4_MODE);
    
    // printf("Ready\n");
    Millis_Init();
    lastPacketTime = Millis();
    while (1)
    {
        // 1. Nhận dữ liệu (Giữ nguyên logic lọc rác hôm qua)
        while (UART0_Available() > 0)
        {
            char c = UART0_GetChar();
            if (c == '|') {
                json[i] = '\0'; 
                flagJson = 1;
                i = 0; 
            }
            else if (i < MAX_JSON_SIZE - 1) {
                // Chỉ lấy ký tự hợp lệ
                if ((c >= '0' && c <= '9') || c == ',' || c == '-') {
                    json[i++] = c;
                }
            }
            else { i = 0; }
        }

        // 2. Xử lý dữ liệu với BỘ LỌC THÔNG MINH
        if (flagJson)
        {
            int commaCount = 0;
            int k = 0;
            while(json[k] != '\0') {
                if(json[k] == ',') commaCount++;
                k++;
            }
            if (commaCount == 7) 
            {
                parse_json(json, &dataRx[0], &dataRx[1], &dataRx[2], &dataRx[3], &dataRx[4], &dataRx[5], &dataRx[6], &dataRx[7]);
                
                HandlePWM(PWM3_CH, dataRx[5]);
                HandlePWM(PWM4_CH, dataRx[7]);
                HandleDir(Dir3, dataRx[4]);
                HandleDir(Dir4, dataRx[6]);
                lastPacketTime = Millis(); 
            }
            else 
            {
            }
            flagJson = 0; 
        }
        // 3. Timeout
        if (Millis() - lastPacketTime > 1000) {
            HandlePWM(PWM3_CH, 0);
            HandlePWM(PWM4_CH, 0);
        }
    }
}

#endif
