/*
 * Button.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#include "Button.h"

void button_isr(void* pressed) {
	*(bool*)pressed = true;
}

Button::Button(int pin) : button(upm::GroveButton(pin)), state(false) {
	button.installISR(mraa::EDGE_RISING, button_isr, &state);
}

Button::~Button() {
	button.uninstallISR();
}

bool Button::pressed() {
	return state;
}

void Button::clear() {
	state = false;
}
