#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdlib.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "util.h"
#include "lcd.h"
#include "buttons.h"

void status_led(byte value) {
    //PORTB = (PORTB & 0xDF) | (value << 5);
    setPin(25, value);
}

int main(void) {
    //DDRB = 0x20; // setup the led as output
    //PINMODE(25, 1);
    init_timers();
    init_buttons();
    pinMode(25, 1);
    lcd_init();
    clear();
    setCursor(0, 0);
    lcd_printf("Hello World %d", millis());
    clear();

    while (1) {
        //status_led(1);
        //_delay_ms(1000);
        //status_led(0);
        //_delay_ms(1000);
        status_led(1);
        setCursor(0, 0);
        lcd_printf("Hello %.2f", get_fps());
        setCursor(0, 1);
        lcd_printf("%d %d", while_red_button(), while_black_button());
        status_led(0);
        //_delay_ms(100);
    }
}