#pragma once

#include "triangle.h"

#ifdef MY_EXE
    #define FROJ_LIB __declspec(dllexport)
#else
    #define FROJ_LIB __declspec(dllimport)
#endif

class TriangleRightAngled : public Triangle {
public:
    FROJ_LIB TriangleRightAngled();
};