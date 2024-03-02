#pragma once

#ifdef LIBRARYDYNAMIC3_EXPORTS
	#define LIB_API __declspec(dllexport)
#else
	#define LIB_API __declspec(dllimport)
#endif