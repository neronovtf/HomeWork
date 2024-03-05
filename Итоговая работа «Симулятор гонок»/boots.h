#pragma once

#include "project_api.h"
#include "error.h"
#include "landTransport.h"

class Boots: public LandTransport{
private:
	int speed = 6;
	int timeBeforeRest = 60;
	int timeFirstRest = 10;
	int timeNextRest = 5;
public:
	Boots(): LandTransport("Ѕотинки-вездеходы") {}; // сапоги-скороходы ? )))
	PROJECT_API void calculate(int distance) override;
};