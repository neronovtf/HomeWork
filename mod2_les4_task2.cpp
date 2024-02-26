#include <iostream>
#include <Windows.h>

class Shape {
protected:
    int numberCorners;
    std::string name;
public:
    Shape() {
        this->name = "Фигура";
        this->numberCorners = 0;
    }
    virtual void print() {
        std::cout << this->name + ": " << this->numberCorners << std::endl;
    }
};

class Triangle : public Shape {
private:
    int a, b, c;
    int A, B, C;
protected:
    Triangle(std::string name, int a, int b, int c, int A, int B, int C) :Shape() {
        this->name = name;

        this->a = a;
        this->b = b;
        this->c = c;

        this->A = A;
        this->B = B;
        this->C = C;
    };
public:
    Triangle() :Shape() {
        this->name = "Треугольник";

        this->a = 10;
        this->b = 20;
        this->c = 30;

        this->A = 50;
        this->B = 60;
        this->C = 70;
    };
    void print() override {
        std::cout << this->name << std::endl;
        std::cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << std::endl;
        std::cout << "Углы: A=" << this->A << " B=" << this->B << " C="  << this->C << std::endl;
        std::cout << std::endl;
    }
};

// -- >> for Triangle -----------------------------------------------------------------
class TriangleRightAngled: public Triangle{
public:
    TriangleRightAngled() :Triangle("Прямоугольный треугольник", 10, 20, 30, 50, 60, 90) {}
};

class TriangleIsosceles : public Triangle {
public:
    TriangleIsosceles() :Triangle("Равнобедренный треугольник", 10, 20, 10, 50, 60, 50) {}
};

class TriangleEquilateral : public Triangle {
public:
    TriangleEquilateral() : Triangle("Равносторонний треугольник", 30, 30, 30, 60, 60, 60) {}
};
// -- << for Triangle -----------------------------------------------------------------



class Quadrilateral : public Shape {
private:
    int a, b, c, d;
    int A, B, C, D;
protected:
    Quadrilateral(std::string name, int a, int b, int c, int d, int A, int B, int C, int D) :Shape() {
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
public:
    Quadrilateral() :Shape() {
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
    void print() override {
        std::cout << this->name << std::endl;
        std::cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << " d=" << this->d << std::endl;
        std::cout << "Углы: A=" << this->A << " B=" << this->B << " C=" << this->C << " D=" << this->D << std::endl;
        std::cout << std::endl;
    }
};

// -- >> for Quadrilateral -----------------------------------------------------------------
class MyRectangle : public Quadrilateral { // хотел назвать класс "Rectangle", но видимо это зарезервированное имя =(
public:
    MyRectangle() :Quadrilateral("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {}
};

class Square : public Quadrilateral {
public:
    Square() :Quadrilateral("Квадрат", 20, 20, 20, 20, 90, 90, 90, 90) {}
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram() :Quadrilateral("Параллелограмм", 20, 30, 20, 30, 30, 40, 30, 40) {}
};

class Rhomb : public Quadrilateral {
public:
    Rhomb() :Quadrilateral("Ромб", 30, 30, 30, 30, 30, 40, 30, 40) {}
};
// -- << for Quadrilateral -----------------------------------------------------------------


void print_info(Shape* other_shape) {
    other_shape->print();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // ------------------------------------------------
    // (!) Инициализацию длин сторон и величин углов нужно выполнить с помощью вызова базовых конструкторов.
    // ------------------------------------------------

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