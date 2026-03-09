#include "hall_speed.h"

//=========================
// Cấu hình chân cảm biến Hall
//=========================
#define HALL1 P30
#define HALL2 P05
#define HALL3 P16
#define HALL4 P02


//=========================
// Biến toàn cục (XDATA để tiết kiệm RAM nội)
//=========================
__xdata static uint8_t prev_state[HALL_COUNT] = {0};
__xdata static uint16_t count[HALL_COUNT] = {0};
__xdata static uint16_t speed[HALL_COUNT] = {0};
static uint16_t ms_counter = 0;

void HallSpeed_Init(void)
{
    // Cấu hình GPIO làm input
    P30_Input_Mode;
    P05_Input_Mode;
    P16_Input_Mode;
    P02_Input_Mode;

    //====================
    // Cấu hình Timer0 mode 1 (16-bit)
    //====================
    TIMER0_MODE1_ENABLE;
    clr_TF0;
    clr_T0M;

    TH0 = HIBYTE(TIMER_DIV12_VALUE_100us);
    TL0 = LOBYTE(TIMER_DIV12_VALUE_100us);

    set_ET0; // cho phép ngắt Timer0
    set_EA;  // cho phép ngắt toàn cục
    set_TR0; // bật Timer0
}

//=========================
// Truy cập dữ liệu
//=========================
uint16_t HallSpeed_GetCount(uint8_t index)
{
    if (index >= HALL_COUNT)
        return 0;
    return count[index];
}

uint16_t HallSpeed_GetSpeed(uint8_t index)
{
    if (index >= HALL_COUNT)
        return 0;
    return speed[index];
}


//=========================
// Ngắt Timer0 (vector 1)
//=========================
void Timer0_ISR(void) __interrupt(1)
{
    clr_TF0; // xóa cờ tràn

    uint8_t i;
    uint8_t hall_now = 0;

    for (i = 0; i < HALL_COUNT; i++)
    {
        switch (i)
        {
        case 0:
            hall_now = HALL1;
            break;
        case 1:
            hall_now = HALL2;
            break;
        case 2:
            hall_now = HALL3;
            break;
        case 3:
            hall_now = HALL4;
            break;
        }

        // Phát hiện cạnh lên
        if (!prev_state[i] && hall_now)
            count[i]++;

        prev_state[i] = hall_now;
    }

    if (++ms_counter >= 2560) //400us
    {
        for (i = 0; i < HALL_COUNT; i++)
        {
            if (count[i] > 0)
                speed[i] = count[i]; // có xung → cập nhật
            else
                speed[i] = 0; // không có xung → bằng 0
            count[i] = 0;
        }
        ms_counter = 0;
    }

    // Nạp lại giá trị cho Timer0 (1ms)
    TH0 = HIBYTE(TIMER_DIV12_VALUE_100us);
    TL0 = LOBYTE(TIMER_DIV12_VALUE_100us);
}
