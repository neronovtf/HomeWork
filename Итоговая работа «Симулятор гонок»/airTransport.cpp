#include "airTransport.h"

float AirTransport::percent(int distance, int percent) {
	float hundred = 100;
	this->isEditDistance = true;
	return (static_cast<float>(distance) * static_cast<float>(percent)) / hundred;
};