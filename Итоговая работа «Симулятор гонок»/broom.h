#pragma once

#include "project_api.h"
#include "error.h"
#include "airTransport.h"

class Broom: public AirTransport{
private:
	int speed = 20;
	float reduction(int distance);
public:
	Broom(): AirTransport("Метла") {};
	PROJECT_API void calculate(int distance) override;
};