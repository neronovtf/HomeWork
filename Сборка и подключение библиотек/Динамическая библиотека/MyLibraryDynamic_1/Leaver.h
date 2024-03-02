#pragma once

#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
	#define MATHPOWERLIBRARY_API __declspec(dllexport)
#else
	#define MATHPOWERLIBRARY_API __declspec(dllimport)
#endif

#include <string>

class Leaver {
public:
	MATHPOWERLIBRARY_API std::string leave(std::string name);
};