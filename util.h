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

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define A6 6
#define A7 7

volatile uint32_t clock_ticks;
unsigned long last_fps;

void setPin(byte pin, byte val);
void pinMode(byte pin, byte val);
byte getPin(byte pin);

unsigned long millis();
void init_timers();
float get_fps();

void init_adc();
uint16_t read_adc(byte addr);

#endif