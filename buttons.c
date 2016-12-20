#include "buttons.h"

void init_buttons() {
    pinMode(RED_BUTTON_PIN, 0);
    pinMode(BLACK_BUTTON_PIN, 0);
    setPin(RED_BUTTON_PIN, 1);
    setPin(BLACK_BUTTON_PIN, 1);
}

byte while_red_button() {
    if (RED_BUTTON) {
        while (RED_BUTTON);
        return 1;
    }
    return 0;
}

byte while_black_button() {
    if (BLACK_BUTTON) {
        while (BLACK_BUTTON);
        return 1;
    }
    return 0;
}