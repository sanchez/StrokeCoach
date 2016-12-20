#ifndef LCD_H
#define LCD_H

#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>
#include <avr/io.h>
#include <stdarg.h>

// #define LCD_RS 7
// #define LCD_ENABLE 6
// #define LCD_D4 5
// #define LCD_D5 4
// #define LCD_D6 3
// #define LCD_D7 2

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// LCD pins
#define LCD_ENABLE 44
#define LCD_RS 43
#define LCD_CONTRAST 21
#define LCD_D0 45
#define LCD_D1 46
#define LCD_D2 47
#define LCD_D3 20

void write4bits(byte value);
void send(byte value, byte mode);
void lcd_init();
void clear();
void setCursor(byte col, byte row);
void lcd_printf(char *format, ...);

#endif