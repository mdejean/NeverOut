/*
 * Scale.h
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#ifndef SCALE_H_
#define SCALE_H_
#include "ScaleValue.h"

class Scale {
public:
	Scale();
	~Scale();
	//Get the current value
	ScaleValue read();
	//Wait until a new value is available
	void wait();
};

#endif /* SCALE_H_ */
