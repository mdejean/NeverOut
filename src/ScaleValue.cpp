/*
 * ScaleValue.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#include "ScaleValue.h"
#include <sstream>
#include <iomanip>

#define SM (0.1)
#define DT (0.2)

ScaleValue::ScaleValue(int counts) : value(counts) { }

ScaleValue ScaleValue::interpolate(ScaleValue a, ScaleValue b, float c) {
	return ScaleValue(a.value + c * (a.value-b.value));
}

ScaleRate ScaleValue::get_rate(const std::deque<ScaleValue>& hist) {
	double forward = hist[0].value, backward = hist[hist.size()-1].value;
	for (auto p : hist) {
		forward = forward * (1-SM) + SM * (double)p.value;
	}
	for (auto p = hist.rbegin(); p != hist.rend(); p++) {
		backward = backward * (1-SM) + SM * (double)p->value;
	}
	return (forward - backward)/(hist.size() * DT);
}

bool ScaleValue::operator<(const ScaleValue& other) const {
	return value < other.value;
}
bool ScaleValue::operator>(const ScaleValue& other) const {
	return other < *this;
}

std::string ScaleValue::string() {
	std::stringstream ss;
	ss << std::fixed << std::setprecision(1) << value * 0.1;
	return ss.str();
}

std::string ScaleValue::stringWithUnits() {
	return string() + " g";
}
