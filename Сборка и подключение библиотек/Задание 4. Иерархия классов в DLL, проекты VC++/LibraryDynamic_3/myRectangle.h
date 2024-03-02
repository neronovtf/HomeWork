#pragma once

#include "quadrilateral.h"

#ifdef MY_EXE
    #define FROJ_LIB __declspec(dllexport)
#else
    #define FROJ_LIB __declspec(dllimport)
#endif


class MyRectangle : public Quadrilateral {
public:
    FROJ_LIB MyRectangle();
};