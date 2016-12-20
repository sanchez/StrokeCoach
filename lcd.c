#include "lcd.h"

void write4bits(byte value) {
    setPin(LCD_D0, value & 0x01);
    setPin(LCD_D1, value & 0x02);
    setPin(LCD_D2, value & 0x04);
    setPin(LCD_D3, value & 0x08);

    setPin(LCD_ENABLE, 0);
    _delay_us(1);
    setPin(LCD_ENABLE, 1);
    _delay_us(1);
    setPin(LCD_ENABLE, 0);
    _delay_us(1);
}

void send(byte value, byte mode) {
    setPin(LCD_RS, mode);
    write4bits(value >> 4);
    write4bits(value);
    //write4bits(value >> 4);
}

void command(byte value) {
    send(value, 0);
}

void write(byte value) {
    send(value, 1);
}

void lcd_init() {
    pinMode(LCD_ENABLE, 1);
    pinMode(LCD_RS, 1);
    pinMode(LCD_CONTRAST, 1);
    pinMode(LCD_D0, 1);
    pinMode(LCD_D1, 1);
    pinMode(LCD_D2, 1);
    pinMode(LCD_D3, 1);

    _delay_ms(50);
    setPin(LCD_CONTRAST, 0);
    setPin(LCD_RS, 0);
    setPin(LCD_ENABLE, 0);

    write4bits(0x03);
    _delay_ms(4.1);
    write4bits(0x03);
    _delay_ms(4.1);
    write4bits(0x03);
    _delay_ms(4.1);
    write4bits(0x02);

    command(LCD_FUNCTIONSET | LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS);
    command(LCD_DISPLAYCONTROL | LCD_CURSOROFF | LCD_BLINKOFF | LCD_DISPLAYON);

    // byte displayfunction = LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS;
    // command(LCD_FUNCTIONSET | displayfunction);
    // command(LCD_ENTRYMODESET | LCD_DISPLAYON);
}

void clear() {
    command(LCD_CLEARDISPLAY);
    // _delay_ms(2);
}

void setCursor(byte col, byte row) {
    int row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

void lcd_puts(char *string) {
    for (char *it = string; *it; it++) {
        write(*it);
    }
}

void lcd_printf(char *format, ...) {
    va_list args;

    char lcd_buffer[17];

    va_start(args, format);
    vsnprintf(lcd_buffer, 17, format, args);
    va_end(args);

    lcd_puts(lcd_buffer);
}