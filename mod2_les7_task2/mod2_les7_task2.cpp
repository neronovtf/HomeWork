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

#include "errors.h"

void print_info(Shape* other_shape) {
    other_shape->print();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Quadrilateral quadrilateral;
    try{
        // Good
        MyRectangle rectangleGood(&quadrilateral, 10, 20, 10, 20, 90, 90, 90, 90);
        // Bad
        MyRectangle rectangleBad(&quadrilateral, 10, 20, 10, 20, 90, 90, 80, 90);
    }
    catch (Errors& ex){
        std::cout << ex.text() << std::endl;
    }

    return 0;
}