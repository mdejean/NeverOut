/*
 * ScaleValue.h
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#ifndef SCALEVALUE_H_
#define SCALEVALUE_H_
#include <deque>
#include <string>
#include "ScaleRate.h"


class ScaleValue {
	int value;
public:
	ScaleValue() : value(0) {};
	ScaleValue(int counts);
	bool operator<(const ScaleValue& v) const;
	bool operator>(const ScaleValue& v) const;
	std::string string();
	std::string stringWithUnits();
	static ScaleValue interpolate(ScaleValue a, ScaleValue b, float c);
	static ScaleRate get_rate(const std::deque<ScaleValue>& d);
};


#endif /* SCALEVALUE_H_ */
