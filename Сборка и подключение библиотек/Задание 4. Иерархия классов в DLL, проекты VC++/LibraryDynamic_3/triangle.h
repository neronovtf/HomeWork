#pragma once

#include "shape.h"

#ifdef MY_EXE
    #define FROJ_LIB __declspec(dllexport)
#else
    #define FROJ_LIB __declspec(dllimport)
#endif

class Triangle : public Shape {
private:
    int a, b, c;
    int A, B, C;
protected:
    Triangle(std::string name, int a, int b, int c, int A, int B, int C);
public:
    FROJ_LIB Triangle();
    FROJ_LIB void print() override;
};