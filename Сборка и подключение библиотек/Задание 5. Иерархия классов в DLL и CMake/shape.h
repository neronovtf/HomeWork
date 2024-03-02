#pragma once

#include <iostream>

class Shape {
protected:
    int numberCorners;
    std::string name;
public:
    Shape();
    virtual void print();
};