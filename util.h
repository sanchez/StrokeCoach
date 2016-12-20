#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>

typedef char byte;

#define _BV(bit) (1 << (bit))

volatile uint32_t clock_ticks;
unsigned long last_fps;

void setPin(byte pin, byte val);
void pinMode(byte pin, byte val);
byte getPin(byte pin);

unsigned long millis();
void init_timers();
float get_fps();

#endif