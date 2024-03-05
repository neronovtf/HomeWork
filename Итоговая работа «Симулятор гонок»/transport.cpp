#include "transport.h"

Transport::Transport() {
	this->name = "Транспортное средство";
	this->type = 0;
};

Transport::Transport(std::string name, int type) {
	this->name = name;
	this->type = type;
};

std::string Transport::getName() {
	return this->name;
};

int Transport::getType() {
	return this->type;
};

void Transport::setFinishTime(float time) {
	this->finishTime = time;
};

void Transport::calculate(int distance) {};

float Transport::getTime() {
	return this->finishTime;
};