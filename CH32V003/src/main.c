// #include "debug.h"
// #include "motor.h"
// #include "ws2812.h"
// #define LED_COUNT 8
// int main(void)
// {
//     SystemCoreClockUpdate();
//     Delay_Init();
//     Motor_Init();
//     Motor_SetPWM(1, 400);
//     Motor_SetPWM(2, 500);
//     Motor_SetPWM(3, 700);
//     Motor_SetPWM(4, 800);
//     /* Khởi tạo WS2812 (Chạy DMA trên PC1) */
//     RGBLED_Init(LED_COUNT);
//     RGBLED_SetBrightness(50); // Giới hạn độ sáng để bảo vệ nguồn
//     RGBLED_Clear();
//     RGBLED_Show();

//     uint8_t pos = 0;
//     while (1)
//     {
//         // Hiệu ứng LED chạy đuổi (Chasing effect)
//         RGBLED_Clear();
//         // Màu xanh dương nhạt (R:0, G:50, B:150)
//         RGBLED_SetPixel(pos, RGBLED_RGB(0, 50, 150));
//         // Gọi Show để DMA tự đẩy dữ liệu ra PC1
//         RGBLED_Show();

//         pos++;
//         if (pos >= LED_COUNT)
//         {
//             pos = 0;
//         }
//         Delay_Ms(120);
//     }
// }

// #include "debug.h"
// #include "rc522.h"

// int main(void) {
//     uint8_t status;
//     uint8_t UID[MAX_LEN]; // Đã dùng MAX_LEN định nghĩa trong file .h

//     SystemCoreClockUpdate();
//     Delay_Init();
//     USART_Printf_Init(115200);
    
//     printf("\r\n--- CH32V003 RFID System Start ---\r\n");

//     SPI1_Init();
//     RC522_Init();
    
//     // Đọc version để kiểm tra kết nối
//     uint8_t v = Read_RC522(0x37);
//     printf("RC522 Version: 0x%02x\r\n", v);

//     while(1) {
//         // Quét thẻ và lấy UID
//         status = RC522_GetUID(UID);

//         if (status == MI_OK) {
//             printf("Card Detected! UID: %02X %02X %02X %02X\r\n", 
//                     UID[0], UID[1], UID[2], UID[3]);
//             Delay_Ms(1000); // Tránh đọc lặp lại liên tục
//         }

//         Delay_Ms(100);
//     }
// }
#include "debug.h"
#include "line.h"

int main(void)
{
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);

    Line_Init();

    printf("=== LINE SENSOR TEST MODE ===\r\n");
    printf("Format: L1 L2 L3 L4 L5 | BYTE\r\n");

    while (1)
    {
        uint8_t line = Line_Get_Byte();   // đọc thẳng, không lọc

        /* In từng mắt */
        printf("   ");
        for (int i = 0; i < 5; i++)
        {
            printf("%d ", (line >> i) & 0x01);
        }

        /* In dạng nhị phân */
        printf("| ");
        for (int i = 4; i >= 0; i--)
        {
            printf("%d", (line >> i) & 0x01);
        }

        printf("\r\n");

        Delay_Ms(100);
    }
}
