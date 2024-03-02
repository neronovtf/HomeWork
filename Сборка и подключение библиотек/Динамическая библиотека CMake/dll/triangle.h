#pragma once
#include "shape.h"

class Triangle : public Shape {
private:
    int a, b, c;
    int A, B, C;
protected:
    Triangle(std::string name, int a, int b, int c, int A, int B, int C);
public:
    Triangle();
    void print() override;
};