/*
 * Scale.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#include "Scale.h"
#include <unistd.h>

Scale::Scale() : adc(1) {
	// TODO Auto-generated constructor stub
}

Scale::~Scale() {
	// TODO Auto-generated destructor stub
}

ScaleValue Scale::read() {
	float raw = adc.readFloat();
	//FIXME: MAGIC!
	int grams = (raw - 0.51) * 2000.0 / (0.562 - 0.51);
	return ScaleValue(grams);
}

void Scale::wait() {
	usleep(200000);
}
