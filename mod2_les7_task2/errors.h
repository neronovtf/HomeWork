#pragma once
#include <string>

class Errors : public std::exception {
public:
	std::string textError;
	Errors(std::string textError);
	std::string text();
};