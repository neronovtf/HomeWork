#include "eagle.h"

float Eagle::reduction(int distance) {
	float newDistance = this->percent(distance, 6);

	return static_cast<float>(distance) - newDistance;
};

void Eagle::calculate(int distance) {
	this->setFinishTime(this->reduction(distance) / static_cast<float>(this->speed));
};