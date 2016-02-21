/*
 * CloudConnection.cpp
 *
 *  Created on: Feb 21, 2016
 *      Author: User
 */

#include "CloudConnection.h"
#include "CloudConfig.h"

#include <string>
#include <unistd.h>
#define NAME_MAX 100
CloudConnection::CloudConnection() {
	//maybe we should do some security stuff...

	//nah
}

void CloudConnection::send(ScaleValue v) {
	//zzzzzzzzz
	system((std::string("wget -O - " CLOUD_URL "/add_point/") + v.string()).c_str());
}

std::string CloudConnection::name() {
	FILE* f = popen("wget -O - " CLOUD_URL "/name", "r");
	char s[NAME_MAX+1];
	int len = fread(&s[0], 1, NAME_MAX, f);
	s[len] = '\0';
	pclose(f);
	return std::string(s);
}
