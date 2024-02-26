#include <iostream>
#include <Windows.h>

class Shape {
protected:
    int numberCorners;
    std::string name;
    std::string status;
    virtual std::string isTry() {
        return "Правильная";
    }
public:
    Shape() {
        this->name = "Фигура";
        this->numberCorners = 0;
    }
    void print() {
        std::cout << this->name + ": " << std::endl;
        std::cout << this->isTry() << std::endl;
        std::cout << "Количество сторон : " << this->numberCorners << std::endl;
        std::cout << std::endl;
    }
    virtual void isRight() {
        std::cout << this->name + ": " << this->numberCorners << std::endl;
    }
};

class Triangle : public Shape {
private:
    int numberCorners = 3;
    // стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180
    std::string isTry() {
        return (this->numberCorners == 3 && (A + B + C == 180)) ? "Правильная" : "Неправильная";
    }
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
    std::string name;
    int a, b, c;
    int A, B, C;
    Triangle() :Shape() {
        this->name = "Треугольник";

        this->a = 10;
        this->b = 20;
        this->c = 30;

        this->A = 50;
        this->B = 60;
        this->C = 70;
    };
    void print() {
        std::cout << this->name + ":" << std::endl;
        std::cout << isTry() << std::endl;
        std::cout << "Количество сторон: " << this->numberCorners << std::endl;
        std::cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << std::endl;
        std::cout << "Углы: A=" << this->A << " B=" << this->B << " C=" << this->C << std::endl;
        std::cout << std::endl;
    }
};

// -- >> for Triangle -----------------------------------------------------------------
class TriangleRightAngled : public Triangle {
private:
    std::string name = "Прямоугольный треугольник";
public: // угол C всегда равен 90
    TriangleRightAngled(Triangle* triangle, int a, int b, int c, int A, int B, int C){
        triangle->name = this->name;
        triangle->a = a;
        triangle->b = b;
        triangle->c = c;
        triangle->A = A;
        triangle->B = B;
        triangle->C = C;

        triangle->print();
    }
};

class TriangleIsosceles : public Triangle {
public: // стороны a и c равны, углы A и C равны
    TriangleIsosceles() :Triangle("Равнобедренный треугольник", 10, 20, 10, 50, 60, 50) {}
};

class TriangleEquilateral : public Triangle {
public: // все стороны равны, все углы равны 60
    TriangleEquilateral() : Triangle("Равносторонний треугольник", 30, 30, 30, 60, 60, 60) {}
};
// -- << for Triangle -----------------------------------------------------------------



class Quadrilateral : public Shape {
private:
    int a, b, c, d;
    int A, B, C, D;
    int numberCorners = 4;
    // стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360
    std::string isTry() {
        return (this->numberCorners == 4 && (A + B + C + D == 360)) ? "Правильная" : "Неправильная";
    }
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
    void print() {
        std::cout << this->name << std::endl;
        std::cout << isTry() << std::endl;
        std::cout << "Количество сторон: " << this->numberCorners << std::endl;
        std::cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << " d=" << this->d << std::endl;
        std::cout << "Углы: A=" << this->A << " B=" << this->B << " C=" << this->C << " D=" << this->D << std::endl;
        std::cout << std::endl;
    }
};

// -- >> for Quadrilateral -----------------------------------------------------------------
class MyRectangle : public Quadrilateral { // хотел назвать класс "Rectangle", но видимо это зарезервированное имя =(
public: // стороны a,c и b,d попарно равны, все углы равны 9
    MyRectangle() :Quadrilateral("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {}
};

class Square : public Quadrilateral {
public: // все стороны равны, все углы равны 90
    Square() :Quadrilateral("Квадрат", 20, 20, 20, 20, 90, 90, 90, 90) {}
};

class Parallelogram : public Quadrilateral {
public: // стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны
    Parallelogram() :Quadrilateral("Параллелограмм", 20, 30, 20, 30, 30, 40, 30, 40) {}
};

class Rhomb : public Quadrilateral {
public: // все стороны равны, углы A,C и B,D попарно равны
    Rhomb() :Quadrilateral("Ромб", 30, 30, 30, 30, 30, 40, 30, 40) {}
};
// -- << for Quadrilateral -----------------------------------------------------------------

/*
void print_info(Shape* other_shape) {
    other_shape->print();
}
*/

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Shape shape;
    shape.print();

    // -----------------------------------------
    Triangle triangle;
    triangle.print();


    TriangleRightAngled triangleRightAngled_1(&triangle, 10, 20, 30, 50, 60, 90);
    TriangleRightAngled triangleRightAngled_2(&triangle, 10, 20, 30, 50, 40, 90);

    TriangleIsosceles isosceles;
    Triangle* _isosceles = &isosceles;
    _isosceles->print();

    TriangleEquilateral equilateral;
    Triangle* _equilateral = &equilateral;
    _equilateral->print();
    // -----------------------------------------


    Quadrilateral quadrilateral;
    quadrilateral.print();

    // -----------------------------------------
    MyRectangle rectangle;
    Quadrilateral* _rectangle = &rectangle;
    _rectangle->print();

    Square square;
    Quadrilateral* _square = &square;
    _square->print();

    Parallelogram parallelogram;
    Quadrilateral* _parallelogram = &parallelogram;
    _parallelogram->print();

    Rhomb rhomb;
    Quadrilateral* _rhomb = &rhomb;
    _rhomb->print();
    // -----------------------------------------
    


    /*
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
    */

    return 0;
}