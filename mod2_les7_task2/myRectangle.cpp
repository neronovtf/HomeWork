#include "myRectangle.h"
#include "errors.h"

bool MyRectangle::isTry(int a, int b, int c, int d, int A, int B, int C, int D) {
    // ������� a,c � b,d ������� �����, ��� ���� ����� 90
    if (a != c) throw Errors("������� a � c, �� ����� ���� �����");
    if (a != c) throw Errors("������� a � c, �� ����� ���� �����");
    if (b != d) throw Errors("������� b � d, �� ����� ���� �����");
    if (A != 90) throw Errors("���� A �� ����� 90�");
    if (B != 90) throw Errors("���� B �� ����� 90�");
    if (C != 90) throw Errors("���� C �� ����� 90�");
    if (D != 90) throw Errors("���� D �� ����� 90�");

    return true;
}

MyRectangle::MyRectangle(Quadrilateral* quadrilateral, int a, int b, int c, int d, int A, int B, int C, int D){
    std::cout << 
        this->name + " (������� " << a << ", " << b << ", " << c << ", " << d << "; "
        "���� " << A << ", " << B << ", " << C << ", " << D << ") ������"
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