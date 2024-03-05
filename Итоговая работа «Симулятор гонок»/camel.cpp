#include "camel.h"

void Camel::calculate(int distance) {
	float time = 0;

	float t = static_cast<float>(distance) / static_cast<float>(this->speed);
	int t1 = t;
	int countRest = t1 / this->timeBeforeRest;
	if (t1 % this->timeBeforeRest == 0) countRest--;

	float timeRest = 0;
	if (countRest > 0) {
		timeRest = this->timeFirstRest + --countRest * this->timeNextRest;
	}

	time = t + timeRest;

	this->setFinishTime(time);
};