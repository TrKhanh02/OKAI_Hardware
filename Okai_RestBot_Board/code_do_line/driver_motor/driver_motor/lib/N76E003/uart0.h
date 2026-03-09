#ifndef UART0_H
#define UART0_H

#include <stdint.h>

void SerialPort0_ISR(void) __interrupt(4);
void UART0_Init(uint32_t baudrate);
void UART0_ResetBuffer(void);
void UART0_PutChar(uint8_t c);
void UART0_PutString(const uint8_t *str);
uint8_t UART0_GetChar(void);      // lấy 1 byte từ RX buffer
uint8_t UART0_Available(void); // số byte còn trong RX buffer

#endif

