#pragma once

#include "project_api.h"
#include "error.h"
#include "landTransport.h"

class CamelSpeed: public LandTransport{
private:
	int speed = 40;
	int timeBeforeRest = 10;
	float timeFirstRest = 5;
	float timeSecondRest = 6.5;
	float timeNextRest = 8;
public:
	CamelSpeed(): LandTransport("Верблюд-быстроход") {};
	PROJECT_API void calculate(int distance) override;
};