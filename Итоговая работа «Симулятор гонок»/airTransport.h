#pragma once

#include <string>
#include "error.h"
#include "project_api.h"
#include "transport.h"

class AirTransport: public Transport{
protected:
	bool isEditDistance = false;
	PROJECT_API float percent(int distance, int percent);
public:
	AirTransport(std::string name) : Transport(name, 2) {};
};