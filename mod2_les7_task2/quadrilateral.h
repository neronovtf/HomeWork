#pragma once
#include <string>
#include "shape.h"

class Quadrilateral : public Shape {
private:
protected:
    Quadrilateral(std::string name, int a, int b, int c, int d, int A, int B, int C, int D);
public:
    int a, b, c, d;
    int A, B, C, D;
    std::string name;
    Quadrilateral();
    void print() override;
};