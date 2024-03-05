#pragma once

#include "error.h"
#include "project_api.h"
#include "airTransport.h"

class Eagle: public AirTransport{
private:
	int speed = 8;
	float reduction(int distance);
public:
	Eagle(): AirTransport("Îð¸ë") {};
	PROJECT_API void calculate(int distance) override;
};