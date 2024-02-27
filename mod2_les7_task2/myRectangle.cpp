#include "myRectangle.h"
#include "errors.h"

bool MyRectangle::isTry(int a, int b, int c, int d, int A, int B, int C, int D) {
    // стороны a,c и b,d попарно равны, все углы равны 90
    if (a != c) throw Errors("Стороны a и c, не равны друг другу");
    if (a != c) throw Errors("Стороны a и c, не равны друг другу");
    if (b != d) throw Errors("Стороны b и d, не равны друг другу");
    if (A != 90) throw Errors("Угол A не равен 90°");
    if (B != 90) throw Errors("Угол B не равен 90°");
    if (C != 90) throw Errors("Угол C не равен 90°");
    if (D != 90) throw Errors("Угол D не равен 90°");

    return true;
}

MyRectangle::MyRectangle(Quadrilateral* quadrilateral, int a, int b, int c, int d, int A, int B, int C, int D){
    std::cout << 
        this->name + " (стороны " << a << ", " << b << ", " << c << ", " << d << "; "
        "углы " << A << ", " << B << ", " << C << ", " << D << ") создан"
        << std::endl;

	if (isTry(a, b, c, d, A, B, C, D)) {
        quadrilateral->name = this->name;

        quadrilateral->a = a;
        quadrilateral->b = b;
        quadrilateral->c = c;
        quadrilateral->d = d;
        quadrilateral->A = A;
        quadrilateral->B = B;
        quadrilateral->C = C;
        quadrilateral->D = D;

        quadrilateral->print();
	}
};