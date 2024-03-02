#pragma once
#include "shape.h"

class Quadrilateral : public Shape {
private:
    int a, b, c, d;
    int A, B, C, D;
protected:
    Quadrilateral(std::string name, int a, int b, int c, int d, int A, int B, int C, int D);
public:
    Quadrilateral();
    void print() override;
};