#ifndef __WS2812_H
#define __WS2812_H

#include <stdint.h>
#include <stdbool.h>

/* ================= CONFIG ================= */

#define RGBLED_MAX_LEDS   16   // đổi nếu cần

/* ================= STATUS ================= */

#define RGBLED_OK                    0
#define RGBLED_ERROR_INVALID_PIN     1
#define RGBLED_ERROR_INVALID_INDEX   2
#define RGBLED_ERROR_NOT_INIT        3

/* ================= COLOR ================= */

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGBLED_Color;

#define RGBLED_BLACK   (RGBLED_Color){0, 0, 0}
#define RGBLED_RED     (RGBLED_Color){255, 0, 0}
#define RGBLED_GREEN   (RGBLED_Color){0, 255, 0}
#define RGBLED_BLUE    (RGBLED_Color){0, 0, 255}

/* ================= API ================= */

/* Init WS2812 (1 GPIO pin, fixed in ws2812.c) */
uint8_t RGBLED_Init(uint8_t led_count);

/* Deinit */
void RGBLED_Deinit(void);

/* Brightness */
void RGBLED_SetBrightness(uint8_t brightness);

/* Pixel control */
uint8_t RGBLED_SetPixel(uint8_t index, RGBLED_Color color);
void    RGBLED_Fill(RGBLED_Color color);
void    RGBLED_Clear(void);

/* Update LEDs */
uint8_t RGBLED_Show(void);

/* Color helper */
RGBLED_Color RGBLED_RGB(uint8_t r, uint8_t g, uint8_t b);

#endif /* __WS2812_H */
