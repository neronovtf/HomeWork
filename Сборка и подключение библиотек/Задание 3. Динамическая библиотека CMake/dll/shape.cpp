#include <iostream>
#include "shape.h"

Shape::Shape() {
    this->name = "������";
    this->numberCorners = 0;
};
void Shape::print() {
    std::cout << this->name + ": " << this->numberCorners << std::endl;
};