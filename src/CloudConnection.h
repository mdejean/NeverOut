/*
 * CloudConnection.h
 *
 *  Created on: Feb 21, 2016
 *      Author: User
 */

#ifndef CLOUDCONNECTION_H_
#define CLOUDCONNECTION_H_

#include "ScaleValue.h"
#include <string>

class CloudConnection {
public:
	CloudConnection();
	//send a new datapoint so the good numerical differentiation can do its thing
	void send(ScaleValue v);
	//ask the cloud what we're actually measuring
	std::string name();
};

#endif /* CLOUDCONNECTION_H_ */
