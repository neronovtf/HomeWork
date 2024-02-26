#include <iostream>
#include <Windows.h>

#include "shape.h"

#include "triangle.h"
#include "triangleRightAngled.h"
#include "triangleIsosceles.h"
#include "triangleEquilateral.h"

#include "quadrilateral.h"
#include "MyRectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"

void print_info(Shape* other_shape) {
    other_shape->print();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Shape shape;

    Triangle triangle;
    TriangleRightAngled rightAngled;
    TriangleIsosceles isosceles;
    TriangleEquilateral equilateral;

    Quadrilateral quadrilateral;
    MyRectangle rectangle;
    Square square;
    Parallelogram parallelogram;
    Rhomb rhomb;

    print_info(&triangle);
    print_info(&rightAngled);
    print_info(&isosceles);
    print_info(&equilateral);

    print_info(&quadrilateral);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhomb);

    return 0;
}