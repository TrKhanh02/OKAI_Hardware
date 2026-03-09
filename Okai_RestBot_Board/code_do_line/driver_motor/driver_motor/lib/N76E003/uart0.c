#include "N76E003.h"
#include "uart0.h"
#include "stdio.h"

#define buffer_ring 0

#define RX_BUFFER_SIZE 30

__xdata volatile char rx_buffer[RX_BUFFER_SIZE] = {0};
volatile uint8_t rx_head = 0, rx_tail = 0;

volatile uint8_t tx_busy = 0;

void UART0_Init(uint32_t baudrate)
{
    InitialUART0_Timer3(baudrate);
    ES = 1; // enable UART0 interrupt
    EA = 1;
}

void UART0_PutChar(uint8_t c)
{
    Send_Data_To_UART0(c);
}

void UART0_PutString(const uint8_t *str)
{
    while (*str)
    {
        UART0_PutChar(*str++);
    }
}

#if buffer_ring
char UART0_GetChar(void)
{
    char c = 0;
    if (rx_head != rx_tail)
    {
        c = rx_buffer[rx_tail];
        rx_tail = (rx_tail + 1) % RX_BUFFER_SIZE;
    }
    return c;
}

uint8_t UART0_Available(void)
{
    return (rx_head - rx_tail + RX_BUFFER_SIZE) % RX_BUFFER_SIZE;
}

void UART0_ResetBuffer(void)
{
    rx_head = rx_tail = 0;
}

void SerialPort0_ISR(void) __interrupt(4)
{
    if (RI)
    {
        RI = 0;
        uint8_t next = (rx_head + 1) % RX_BUFFER_SIZE;
        if (next != rx_tail)
        { // chỉ ghi nếu còn chỗ
            rx_buffer[rx_head] = SBUF;
            rx_head = next;
        }
    }
    // if (TI)
    //     TI = 0;
}
#else //shift buffer
char UART0_GetChar(void)
{
    char c;
    if (rx_head == 0)
        return 0; // empty

    c = rx_buffer[0]; // luôn đọc ký tự đầu
    // shift các ký tự còn lại sang trái
    for (uint8_t i = 1; i < rx_head; i++)
    {
        rx_buffer[i - 1] = rx_buffer[i];
    }
    rx_head--;              // giảm head
    rx_buffer[rx_head] = 0; // xóa ký tự cuối sau khi shift
    return c;
}

uint8_t UART0_Available(void)
{
    return rx_head;
}

void UART0_ResetBuffer(void)
{
    rx_head = 0;
}

// ISR
void SerialPort0_ISR(void) __interrupt(4)
{
    if (RI)
    {
        RI = 0;
        if (rx_head < RX_BUFFER_SIZE) // chỉ ghi khi còn chỗ
        {
            rx_buffer[rx_head++] = SBUF;
        }
        // nếu đầy thì bỏ qua dữ liệu mới
    }
}

#endif