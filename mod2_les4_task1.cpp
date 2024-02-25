#include <iostream>
#include <Windows.h>

class Shape {
protected:
    int numberCorners;
    std::string name;
    Shape(int number, std::string name){
        this->name = name;
        this->numberCorners = number;
        this->print();
    }
    void print() {
        std::cout << "\t" + name + ": " << this->numberCorners << std::endl;
    }
public:
    Shape() {
        this->name = "Фигура";
        this->numberCorners = 0;
        this->print();
    }
};

class Triangle : public Shape {
public:
    Triangle() :Shape(3, "Треугольник") {};
};

class Quadrilateral : public Shape {
public:
    Quadrilateral() :Shape(4, "Четырёхугольник") {};
};

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Количество сторон:" << std::endl;
    Shape shape;
    Triangle triangle;
    Quadrilateral quadrilateral;

    return 0;
}