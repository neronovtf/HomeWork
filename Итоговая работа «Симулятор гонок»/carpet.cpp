#include "carpet.h"

float Carpet::reduction(int distance) {
	float newDistance = distance < 1000 ?
		distance :
		(
			distance < 5000 ? this->percent(distance, 3) :
			(
				distance < 10000 ? this->percent(distance, 10) :
				(
					this->percent(distance, 5)
				)
			)
		);

	return this->isEditDistance ? static_cast<float>(distance) - newDistance : newDistance;
};

void Carpet::calculate(int distance) {
	this->setFinishTime(this->reduction(distance) / static_cast<float>(this->speed));
};