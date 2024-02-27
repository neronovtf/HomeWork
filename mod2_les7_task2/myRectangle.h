#pragma once
#include <string>
#include "quadrilateral.h"

class MyRectangle : public Quadrilateral {
private:
    std::string name = "Прямоугольник";
    bool isTry(int a, int b, int c, int d, int A, int B, int C, int D);
public:
    MyRectangle(Quadrilateral* quadrilateral, int a, int b, int c, int d, int A, int B, int C, int D);
};