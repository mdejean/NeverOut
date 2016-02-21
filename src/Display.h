/*
 * Display.h
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <string>
#include <jhd1313m1.h>

#include "ScaleValue.h"

class Display {
	upm::Jhd1313m1 display;
public:
	Display();
	~Display();
	void write(ScaleValue f, ScaleValue e, ScaleValue cur, ScaleRate r, bool p, bool w, float warn_p);
};

#endif /* DISPLAY_H_ */
