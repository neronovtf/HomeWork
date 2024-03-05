#pragma once

#include "project_api.h"
#include "error.h"
#include "landTransport.h"

class Centaur: public LandTransport{
private:
	int speed = 15;
	int timeBeforeRest = 8;
	int timeNextRest = 2;
public:
	Centaur(): LandTransport("Кентавр") {};
	PROJECT_API void calculate(int distance) override;
};