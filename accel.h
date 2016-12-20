#ifndef ACCEL_H
#define ACCEL_H

#include "util.h"
#include <math.h>

#define X_AXIS_PIN A1
#define Y_AXIS_PIN A2
#define Z_AXIS_PIN A3

#define XAXIS read_adc(X_AXIS_PIN)
#define YAXIS read_adc(Y_AXIS_PIN)
#define ZAXIS read_adc(Z_AXIS_PIN)

typedef struct {
    uint16_t xAxis;
    uint16_t yAxis;
    uint16_t zAxis;
    byte mag;
} Reading;

uint16_t getMag(uint16_t x, uint16_t y);

byte read_axis();

#endif