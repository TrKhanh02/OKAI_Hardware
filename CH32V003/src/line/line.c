#include "line.h"

/**
 * @brief Khởi tạo GPIO cho 5 mắt Line
 * Line1: PD1, Line2: PC2, Line3: PC3, Line4: PA2, Line5: PA1
 */
void Line_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // Bật Clock cho các Port A, C, D
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);

    // Cấu hình PD1 (Line 1) - Cẩn thận vì trùng chân SWIO
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Input Pull-up
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // Cấu hình PC2, PC3 (Line 2, Line 3)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // Cấu hình PA1, PA2 (Line 4, Line 5)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/**
 * @brief Đọc giá trị từng mắt vào mảng
 */
void Line_Read(uint8_t *results) {
    results[0] = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_1); // L1
    results[1] = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2); // L2
    results[2] = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3); // L3
    results[3] = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2); // L4
    results[4] = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1); // L5
}

/**
 * @brief Đọc 5 mắt và gộp thành 1 byte duy nhất (Tiện cho xử lý Case-Switch)
 * Ví dụ: Nếu mắt 1 và 3 thấy vạch, trả về 0b00000101 (5)
 */
uint8_t Line_Get_Byte(void) {
    uint8_t val = 0;
    if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_1)) val |= (1 << 0);
    if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2)) val |= (1 << 1);
    if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3)) val |= (1 << 2);
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)) val |= (1 << 3);
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)) val |= (1 << 4);
    return val;
}