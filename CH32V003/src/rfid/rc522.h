#ifndef RC522_H
#define RC522_H

#include "ch32v00x.h"

// --- Định nghĩa thiếu ---
#define MAX_LEN          16  // Kích thước mảng đệm cho thẻ

// --- Cấu hình Pin ---
#define RC522_SPI_PORT   GPIOC
#define RC522_CS_PIN     GPIO_Pin_4
#define RC522_SCK_PIN    GPIO_Pin_5
#define RC522_MOSI_PIN   GPIO_Pin_6
#define RC522_MISO_PIN   GPIO_Pin_7
#define RC522_RST_PORT   GPIOD
#define RC522_RST_PIN    GPIO_Pin_0

// --- Các mã lệnh & Thanh ghi ---
#define PCD_RESETPHASE   0x0F
#define PCD_TRANSCEIVE   0x0C
#define PICC_REQIDL      0x26
#define PICC_ANTICOLL    0x93

#define MI_OK            0
#define MI_NOTAGERR      1
#define MI_ERR           2

// --- Prototypes (Đã thêm Read_RC522 để hết lỗi cảnh báo) ---
void SPI1_Init(void);
void RC522_Init(void);
void Write_RC522(uint8_t addr, uint8_t val);
uint8_t Read_RC522(uint8_t addr);
uint8_t RC522_Request(uint8_t reqMode, uint8_t *TagType);
uint8_t RC522_Anticoll(uint8_t *serNum);
uint8_t RC522_GetUID(uint8_t *uid);

#endif