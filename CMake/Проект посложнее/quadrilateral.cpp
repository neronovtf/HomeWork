#include <iostream>
#include "quadrilateral.h"

Quadrilateral::Quadrilateral(std::string name, int a, int b, int c, int d, int A, int B, int C, int D) :Shape() {
    this->name = name;

    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;

    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
};

Quadrilateral::Quadrilateral() :Shape() {
    this->name = "Четырёхугольник";

    this->a = 10;
    this->b = 20;
    this->c = 30;
    this->d = 40;

    this->A = 50;
    this->B = 60;
    this->C = 70;
    this->D = 80;
};

void Quadrilateral::print() {
    std::cout << this->name << std::endl;
    std::cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << " d=" << this->d << std::endl;
    std::cout << "Углы: A=" << this->A << " B=" << this->B << " C=" << this->C << " D=" << this->D << std::endl;
    std::cout << std::endl;
};