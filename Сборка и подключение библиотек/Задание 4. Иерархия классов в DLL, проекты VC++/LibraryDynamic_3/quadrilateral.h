#pragma once

#include "shape.h"

#ifdef MY_EXE
    #define FROJ_LIB __declspec(dllexport)
#else
    #define FROJ_LIB __declspec(dllimport)
#endif

class Quadrilateral : public Shape {
private:
    int a, b, c, d;
    int A, B, C, D;
protected:
    Quadrilateral(std::string name, int a, int b, int c, int d, int A, int B, int C, int D);
public:
    FROJ_LIB Quadrilateral();
    FROJ_LIB void print() override;
};