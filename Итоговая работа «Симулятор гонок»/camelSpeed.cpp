#include "camelSpeed.h"

void CamelSpeed::calculate(int distance) {
	float time = 0;

	float t = static_cast<float>(distance) / static_cast<float>(this->speed);
	int t1 = t;
	int countRest = t1 / this->timeBeforeRest;
	if (t1 % this->timeBeforeRest == 0) countRest--;

	float timeRest = 0;
	if (countRest > 0) {
		countRest--;
		timeRest += this->timeFirstRest;
		if (countRest > 0) {
			countRest--;
			timeRest += this->timeSecondRest;
		}
		timeRest += countRest * this->timeNextRest;
	}

	time = t + timeRest;

	this->setFinishTime(time);
};