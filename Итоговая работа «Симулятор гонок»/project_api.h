#pragma once

#if PROJECT_DLL_EXPORTS
	#define PROJECT_API __declspec(dllexport)
#else
	#define PROJECT_API __declspec(dllimport)
#endif