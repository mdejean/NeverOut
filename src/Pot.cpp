/*
 * Pot.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#include "Pot.h"

Pot::Pot(int pin) : input(pin) { }

float Pot::value() {
	return input.abs_value();
}

