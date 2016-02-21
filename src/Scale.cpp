/*
 * Scale.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#include "Scale.h"
#include <unistd.h>

Scale::Scale() {
	// TODO Auto-generated constructor stub

}

Scale::~Scale() {
	// TODO Auto-generated destructor stub
}

ScaleValue Scale::read() {
	// TODO
	return ScaleValue(0);
}

void Scale::wait() {
	usleep(200000);
}
