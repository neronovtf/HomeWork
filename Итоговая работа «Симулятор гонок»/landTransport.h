#pragma once

#include "error.h"
#include "project_api.h"
#include "transport.h"

class LandTransport: public Transport{
public:
	LandTransport(std::string name) : Transport(name, 1) {};
};