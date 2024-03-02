#pragma once

#ifdef MYLIBRARYDYNAMIC1_EXPORTS
	#define LIB_API __declspec(dllexport)
#else
	#define LIB_API __declspec(dllimport)
#endif

#include <string>

class Leaver {
public:
	LIB_API std::string leave(std::string name);
};