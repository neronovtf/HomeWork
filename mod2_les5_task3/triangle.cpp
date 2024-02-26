#include <iostream>
#include "shape.h"
#include "triangle.h"

Triangle::Triangle(std::string name, int a, int b, int c, int A, int B, int C) :Shape() {
    this->name = name;

    this->a = a;
    this->b = b;
    this->c = c;

    this->A = A;
    this->B = B;
    this->C = C;
};

Triangle::Triangle() :Shape() {
    this->name = "Треугольник";

    this->a = 10;
    this->b = 20;
    this->c = 30;

    this->A = 50;
    this->B = 60;
    this->C = 70;
};

void Triangle::print() {
    std::cout << this->name << std::endl;
    std::cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << std::endl;
    std::cout << "Углы: A=" << this->A << " B=" << this->B << " C=" << this->C << std::endl;
    std::cout << std::endl;
}