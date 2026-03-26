#include "rc522.h"

// Gửi/Nhận 1 byte qua SPI1
uint8_t SPI1_RW(uint8_t dat) {
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
    SPI_I2S_SendData(SPI1, dat);
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
    return SPI_I2S_ReceiveData(SPI1);
}

void Write_RC522(uint8_t addr, uint8_t val) {
    GPIO_WriteBit(RC522_SPI_PORT, RC522_CS_PIN, Bit_RESET);
    SPI1_RW((addr << 1) & 0x7E);
    SPI1_RW(val);
    GPIO_WriteBit(RC522_SPI_PORT, RC522_CS_PIN, Bit_SET);
}

uint8_t Read_RC522(uint8_t addr) {
    uint8_t val;
    GPIO_WriteBit(RC522_SPI_PORT, RC522_CS_PIN, Bit_RESET);
    SPI1_RW(((addr << 1) & 0x7E) | 0x80);
    val = SPI1_RW(0x00);
    GPIO_WriteBit(RC522_SPI_PORT, RC522_CS_PIN, Bit_SET);
    return val;
}

void SetBitMask(uint8_t reg, uint8_t mask) {
    Write_RC522(reg, Read_RC522(reg) | mask);
}

void ClearBitMask(uint8_t reg, uint8_t mask) {
    Write_RC522(reg, Read_RC522(reg) & (~mask));
}

void SPI1_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    SPI_InitTypeDef  SPI_InitStructure = {0};

    // SỬA: Bật Clock cho Port C, Port D và SPI1
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_SPI1, ENABLE);

    // Cấu hình SCK, MOSI (PC5, PC6)
    GPIO_InitStructure.GPIO_Pin = RC522_SCK_PIN | RC522_MOSI_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(RC522_SPI_PORT, &GPIO_InitStructure);

    // Cấu hình MISO (PC7)
    GPIO_InitStructure.GPIO_Pin = RC522_MISO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(RC522_SPI_PORT, &GPIO_InitStructure);

    // Cấu hình CS (PC4)
    GPIO_InitStructure.GPIO_Pin = RC522_CS_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(RC522_SPI_PORT, &GPIO_InitStructure);

    // SỬA: Cấu hình RST (PD0) ở Port D
    GPIO_InitStructure.GPIO_Pin = RC522_RST_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(RC522_RST_PORT, &GPIO_InitStructure);

    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16; 
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_Init(SPI1, &SPI_InitStructure);
    SPI_Cmd(SPI1, ENABLE);
}

void RC522_Init(void) {
    // SỬA: Kéo chân RST (PD0) lên cao để hoạt động
    GPIO_WriteBit(RC522_RST_PORT, RC522_RST_PIN, Bit_SET);
    
    Write_RC522(0x01, PCD_RESETPHASE);
    Write_RC522(0x2A, 0x8D); 
    Write_RC522(0x2B, 0x3E); 
    Write_RC522(0x2C, 0x00); 
    Write_RC522(0x15, 0x40); 
    Write_RC522(0x11, 0x3D);
    SetBitMask(0x14, 0x03); 
}

// --- Giữ nguyên các hàm xử lý logic ToCard, Request, Anticoll ---

uint8_t RC522_ToCard(uint8_t command, uint8_t *sendData, uint8_t sendLen, uint8_t *backData, uint32_t *backLen) {
    uint8_t status = MI_ERR;
    uint8_t irqEn = 0x00;
    uint8_t waitIRq = 0x00;
    uint8_t lastBits, n;
    uint32_t i;

    if (command == PCD_TRANSCEIVE) {
        irqEn = 0x77;
        waitIRq = 0x30;
    }

    Write_RC522(0x02, irqEn | 0x80);
    ClearBitMask(0x04, 0x80);
    SetBitMask(0x0A, 0x80);
    Write_RC522(0x01, 0x00); 

    for (i = 0; i < sendLen; i++) Write_RC522(0x09, sendData[i]);

    Write_RC522(0x01, command);
    if (command == PCD_TRANSCEIVE) SetBitMask(0x0D, 0x80);

    i = 2000; 
    do {
        n = Read_RC522(0x04);
        i--;
    } while ((i != 0) && !(n & 0x01) && !(n & waitIRq));

    ClearBitMask(0x0D, 0x80);

    if (i != 0) {
        if (!(Read_RC522(0x06) & 0x1B)) {
            status = MI_OK;
            if (n & irqEn & 0x01) status = MI_NOTAGERR;
            if (command == PCD_TRANSCEIVE) {
                n = Read_RC522(0x0A);
                lastBits = Read_RC522(0x0C) & 0x07;
                if (lastBits) *backLen = (n - 1) * 8 + lastBits;
                else *backLen = n * 8;
                if (n == 0) n = 1;
                for (i = 0; i < n; i++) backData[i] = Read_RC522(0x09);
            }
        }
    }
    return status;
}

uint8_t RC522_Request(uint8_t reqMode, uint8_t *TagType) {
    uint8_t status;
    uint32_t backBits;
    Write_RC522(0x0D, 0x07);
    TagType[0] = reqMode;
    status = RC522_ToCard(PCD_TRANSCEIVE, TagType, 1, TagType, &backBits);
    if ((status != MI_OK) || (backBits != 0x10)) status = MI_ERR;
    return status;
}

uint8_t RC522_Anticoll(uint8_t *serNum) {
    uint8_t status, i, serNumCheck = 0;
    uint32_t unLen;
    Write_RC522(0x0D, 0x00);
    serNum[0] = PICC_ANTICOLL;
    serNum[1] = 0x20;
    status = RC522_ToCard(PCD_TRANSCEIVE, serNum, 2, serNum, &unLen);
    if (status == MI_OK) {
        for (i = 0; i < 4; i++) serNumCheck ^= serNum[i];
        if (serNumCheck != serNum[i]) status = MI_ERR;
    }
    return status;
}

uint8_t RC522_GetUID(uint8_t *uid) {
    uint8_t status;
    status = RC522_Request(PICC_REQIDL, uid);
    if (status == MI_OK) status = RC522_Anticoll(uid);
    return status;
}