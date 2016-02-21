/*
 * Scale.h
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#ifndef SCALE_H_
#define SCALE_H_
#include <mraa.hpp>
#include "ScaleValue.h"

class Scale {
	mraa::Aio adc;
public:
	Scale();
	~Scale();
	//Get the current value
	ScaleValue read();
	//Wait until a new value is available
	void wait();
};

#endif /* SCALE_H_ */
