/*
 * ScaleValue.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: User
 */

#include "ScaleValue.h"

ScaleValue::ScaleValue(int counts) : value(0) {
	// TODO Auto-generated constructor stub
}

ScaleValue ScaleValue::interpolate(ScaleValue a, ScaleValue b, float c) {
	return ScaleValue(0); //TODO
}

ScaleRate ScaleValue::get_rate(const std::deque<ScaleValue>& vals) {
	return 0.0f; //TODO
}

bool ScaleValue::operator<(const ScaleValue& other) {
	return false; //TODO
}
bool ScaleValue::operator>(const ScaleValue& other) {
	return *this < other;
}
