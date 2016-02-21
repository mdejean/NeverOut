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

void go(std::string command) {
	system((std::string("wget -O - " CLOUD_URL) + command).c_str());
}

void CloudConnection::send(ScaleValue v) {
	//zzzzzzzzz
	go(std::string("/add_point/") + v.string());
}

void CloudConnection::send_empty(ScaleValue v) {
	go(std::string("/set_empty/") + v.string());
}

void CloudConnection::send_full(ScaleValue v) {
	go(std::string("/set_full/") + v.string());
}

std::string CloudConnection::name() {
	FILE* f = popen("wget -O - " CLOUD_URL "/name", "r");
	char s[NAME_MAX+1];
	int len = fread(&s[0], 1, NAME_MAX, f);
	s[len] = '\0';
	pclose(f);
	return std::string(s);
}
