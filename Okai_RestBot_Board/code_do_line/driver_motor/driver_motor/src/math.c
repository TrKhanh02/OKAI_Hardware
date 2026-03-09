#include "math.h"

uint16_t map(uint16_t x, uint16_t inMin, uint16_t inMax, uint16_t outMin, uint16_t outMax) {
    return (uint16_t)(((uint32_t)(x - inMin) * (outMax - outMin)) 
                      / (inMax - inMin) + outMin);
}