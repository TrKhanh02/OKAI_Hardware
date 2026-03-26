/**
 * @file ws2812.c
 * @brief Simple WS2812B RGB LED Library for CH32V003 (1 GPIO pin)
 */

#include "ws2812.h"
#include "ch32v00x.h"
#include <stdbool.h>
#include <stddef.h>

/* ================= USER CONFIG ================= */
// >>> ĐỔI PIN Ở ĐÂY NẾU CẦN <<<
#define WS2812_PORT GPIOC
#define WS2812_PIN  1               // PC1
#define WS2812_PIN_MASK (1 << WS2812_PIN)
/* =============================================== */

static RGBLED_Color led_buffer[RGBLED_MAX_LEDS];
static uint8_t led_count = 0;
static bool rgbled_initialized = false;
static uint8_t global_brightness = 255;

/* Internal GPIO reference */
static GPIO_TypeDef* led_port = NULL;
static uint32_t led_pin_mask = 0;

/* ================= INTERNAL ================= */

static inline void Delay_Us(uint32_t us)
{
    while (us--) {
        for (volatile uint8_t i = 0; i < 8; i++) {
            __asm__("nop");
        }
    }
}

static uint8_t configure_gpio_hardware(void)
{
    /* Enable GPIO clock */
    if (WS2812_PORT == GPIOA) RCC->APB2PCENR |= RCC_APB2Periph_GPIOA;
    if (WS2812_PORT == GPIOC) RCC->APB2PCENR |= RCC_APB2Periph_GPIOC;
    if (WS2812_PORT == GPIOD) RCC->APB2PCENR |= RCC_APB2Periph_GPIOD;

    /* Configure pin as output push-pull 50MHz */
    uint32_t pin_cfg  = (GPIO_Speed_50MHz | GPIO_Mode_Out_PP) << (WS2812_PIN * 4);
    uint32_t pin_mask = 0xF << (WS2812_PIN * 4);

    WS2812_PORT->CFGLR =
        (WS2812_PORT->CFGLR & ~pin_mask) | pin_cfg;

    WS2812_PORT->BCR = WS2812_PIN_MASK;

    led_port = WS2812_PORT;
    led_pin_mask = WS2812_PIN_MASK;

    return RGBLED_OK;
}

/* ================= WS2812 TIMING ================= */

static inline void send_bit(uint8_t bit)
{
    if (bit) {
        /* T1H ~0.8us */
        led_port->BSHR = led_pin_mask;
        asm volatile(
            "nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n"
            "nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n"
        );
        /* T1L ~0.45us */
        led_port->BCR = led_pin_mask;
        asm volatile(
            "nop\nnop\nnop\nnop\nnop\nnop\nnop\n"
        );
    } else {
        /* T0H ~0.4us */
        led_port->BSHR = led_pin_mask;
        asm volatile(
            "nop\nnop\nnop\nnop\nnop\nnop\n"
        );
        /* T0L ~0.85us */
        led_port->BCR = led_pin_mask;
        asm volatile(
            "nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n"
            "nop\nnop\nnop\nnop\nnop\nnop\nnop\n"
        );
    }
}

static inline void send_byte(uint8_t byte)
{
    for (int8_t i = 7; i >= 0; i--) {
        send_bit((byte >> i) & 0x01);
    }
}

static inline uint8_t apply_brightness(uint8_t c)
{
    return (uint16_t)c * global_brightness / 255;
}

/* ================= PUBLIC API ================= */

uint8_t RGBLED_Init(uint8_t led_count_param)
{
    if (led_count_param == 0 || led_count_param > RGBLED_MAX_LEDS)
        return RGBLED_ERROR_INVALID_INDEX;

    configure_gpio_hardware();

    led_count = led_count_param;
    rgbled_initialized = true;

    RGBLED_Clear();
    RGBLED_Show();

    return RGBLED_OK;
}

void RGBLED_Deinit(void)
{
    if (!rgbled_initialized) return;

    RGBLED_Clear();
    RGBLED_Show();

    rgbled_initialized = false;
}

void RGBLED_SetBrightness(uint8_t brightness)
{
    global_brightness = brightness;
}

uint8_t RGBLED_SetPixel(uint8_t index, RGBLED_Color color)
{
    if (!rgbled_initialized) return RGBLED_ERROR_NOT_INIT;
    if (index >= led_count)  return RGBLED_ERROR_INVALID_INDEX;

    led_buffer[index] = color;
    return RGBLED_OK;
}

void RGBLED_Fill(RGBLED_Color color)
{
    if (!rgbled_initialized) return;

    for (uint8_t i = 0; i < led_count; i++) {
        led_buffer[i] = color;
    }
}

void RGBLED_Clear(void)
{
    RGBLED_Fill(RGBLED_BLACK);
}

uint8_t RGBLED_Show(void)
{
    if (!rgbled_initialized) return RGBLED_ERROR_NOT_INIT;

    /* Disable interrupts */
    uint32_t oldmask;
    asm volatile("csrr %0, mstatus" : "=r"(oldmask));
    asm volatile("csrci mstatus, 8");

    for (uint8_t i = 0; i < led_count; i++) {
        uint8_t r = apply_brightness(led_buffer[i].r);
        uint8_t g = apply_brightness(led_buffer[i].g);
        uint8_t b = apply_brightness(led_buffer[i].b);

        /* WS2812 uses GRB order */
        send_byte(g);
        send_byte(r);
        send_byte(b);
    }

    /* Reset latch >50us */
    led_port->BCR = led_pin_mask;
    Delay_Us(60);

    /* Restore interrupt */
    if (oldmask & 0x8) {
        asm volatile("csrsi mstatus, 8");
    }

    return RGBLED_OK;
}

RGBLED_Color RGBLED_RGB(uint8_t r, uint8_t g, uint8_t b)
{
    RGBLED_Color c = { r, g, b };
    return c;
}
