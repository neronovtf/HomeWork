#include "broom.h"

float Broom::reduction(int distance) {
	int percent = distance / 1000;
	float newDistance = this->percent(distance, percent);

	return static_cast<float>(distance) - newDistance;
};

void Broom::calculate(int distance) {
	this->setFinishTime(this->reduction(distance) / static_cast<float>(this->speed));
};