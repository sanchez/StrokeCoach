#include "accel.h"

uint16_t getMag(uint16_t x, uint16_t y) {
    uint16_t mag = (uint16_t) sqrt((x*x) + (y*y));
}

byte read_axis() {
    uint16_t mag = getMag(XAXIS, ZAXIS);
    return mag/4;
}