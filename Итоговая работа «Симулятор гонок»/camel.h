#pragma once

#include "project_api.h"
#include "error.h"
#include "landTransport.h"

class Camel: public LandTransport{
private:
	int speed = 10;
	int timeBeforeRest = 30;
	int timeFirstRest = 5;
	int timeNextRest = 8;
public:
	Camel(): LandTransport("Верблюд") {};
	PROJECT_API void calculate(int distance) override;
};