/*
 * Button.h
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <grove.h>

class Button {
	upm::GroveButton button;
	bool state;
public:
	Button(int pin);
	~Button();
	//has the button been pressed since the last time clear was called
	bool pressed();
	void clear();
};

#endif /* BUTTON_H_ */
