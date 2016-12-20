#include "util.h"

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

void pinMode(byte pin, byte val) {
    byte bit = pin % 10;
    byte regNum = pin / 10;

    if (val) {
        if (regNum == 2) {
            DDRB |= (1 << bit);
        } else if (regNum == 3) {
            DDRC |= (1 << bit);
        } else if (regNum == 4) {
            DDRD |= (1 << bit);
        }
    } else {
        if (regNum == 2) {
            DDRB &= ~(1 << bit);
        } else if (regNum == 3) {
            DDRC &= ~(1 << bit);
        } else if (regNum == 4) {
            DDRD &= ~(1 << bit);
        }
    }
}

void setPin(byte pin, byte val) {
    byte bit = pin % 10;
    byte regNum = pin / 10;

    if (val) {
        if (regNum == 2) {
            PORTB |= (1 << bit);
        } else if (regNum == 3) {
            PORTC |= (1 << bit);
        } else if (regNum == 4) {
            PORTD |= (1 << bit);
        }
    } else {
        if (regNum == 2) {
            PORTB &= ~(1 << bit);
        } else if (regNum == 3) {
            PORTC &= ~(1 << bit);
        } else if (regNum == 4) {
            PORTD &= ~(1 << bit);
        }
    }
}

byte getPin(byte pin) {
    byte bit = pin % 10;
    byte regNum = pin / 10;
    byte result = 0;

    if (regNum == 2) {
        result = PINB & (1 << bit);
    } else if (regNum == 3) {
        result =  PINC & (1 << bit);
    } else if (regNum == 4) {
        result = PIND & (1 << bit);
    }

    if (result) {
        return 1;
    } else {
        return 0;
    }
}

unsigned long millis() {
    uint32_t rt;
    cli();
    rt = clock_ticks;
    sei();
    return rt;
}

void init_timers() {
    cli();
    // setup the registers for the millis timer
    clock_ticks = 0;
    OCR0A = 124;
    TCCR0A = (1 << WGM01);
    TCCR0B = (1 << CS01) | (1 << CS00);
    TIMSK0 = (1 << 1);
    TIFR0 &= (1 << 1);
    TCNT0 = 0;

    last_fps = 0;

    sei();
}

ISR(TIMER0_COMPA_vect) {
    clock_ticks++;
}

float get_fps() {
    float diff = (float) (millis() - last_fps);
    last_fps = millis();
    return 1000.0/diff;
}