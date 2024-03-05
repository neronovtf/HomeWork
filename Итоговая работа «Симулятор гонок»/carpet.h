#pragma once

#include "project_api.h"
#include "error.h"
#include "airTransport.h"

class Carpet: public AirTransport{
private:
	int speed = 10;
	float reduction(int distance);
public:
	Carpet(): AirTransport("Ковёр-самолёт") {};
	PROJECT_API void calculate(int distance) override;
};