#pragma once

#include <string>
#include "project_api.h"

class Error {
private:
	std::string textError;
public:
	PROJECT_API Error(std::string text);
	PROJECT_API std::string getText();
};