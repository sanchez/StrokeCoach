#ifndef BUTTONS_H
#define BUTTONS_H

#include "util.h"

#define RED_BUTTON_PIN 34
#define BLACK_BUTTON_PIN 35
#define LONG_PRESS 1000

#define RED_BUTTON !getPin(RED_BUTTON_PIN)
#define BLACK_BUTTON !getPin(BLACK_BUTTON_PIN)

void init_buttons();
byte while_red_button();
byte while_black_button();

#endif