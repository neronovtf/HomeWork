#pragma once

#include "error.h"
#include "project_api.h"

class Transport{
private:
	std::string name = "Транспортное средство";
	int type = 0;
	float finishTime = 0;
protected:
	PROJECT_API Transport(std::string name, int type);
	PROJECT_API void setFinishTime(float time);
public:
	Transport();
	PROJECT_API std::string getName();
	PROJECT_API int getType();
	PROJECT_API float getTime();
	PROJECT_API virtual void calculate(int distance);
};