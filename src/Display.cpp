/*
 * Display.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#include "Display.h"
#include <string>
#include <sstream>

Display::Display() : display(0) {
	display.clear();
	display.setColor(155, 155, 120);
}

Display::~Display() {
	display.clear();
}

void Display::write(ScaleValue f, ScaleValue e, ScaleValue cur, ScaleRate r, bool p, bool w, float warn_p, const std::string& name) {
	display.clear();
	std::stringstream ss;
	ss << cur.stringWithUnits();
	ss << " (" << f.string() << "-" << e.string() << ") @" << r;
	display.setCursor(0, 0);
	display.write(ss.str());
	ss.str(name);
	if (p) {
		ss << "picked up ";
	}
	if (w) {
		display.setColor(255, 155, 120);
	} else {
		display.setColor(155, 155, 120);
	}
	ss << ScaleValue::interpolate(e, f, warn_p).string();
	display.setCursor(1, 0);
	display.write(ss.str());
}
