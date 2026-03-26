#ifndef __LINE_H
#define __LINE_H

#include "ch32v00x.h"

#define LINE_COUNT 5

/* API */
void Line_Init(void);
void Line_Read(uint8_t *results);
uint8_t Line_Get_Byte(void);

/* Có lọc nhiễu */
uint8_t Line_Get_Byte_Filtered(void);

#endif
