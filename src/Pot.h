/*
 * Pot.h
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#ifndef POT_H_
#define POT_H_
#include <grove.h>

class Pot {
	upm::GroveRotary input;
public:
	Pot(int pin);
	//value from 0-1
	float value();
};

#endif /* POT_H_ */
