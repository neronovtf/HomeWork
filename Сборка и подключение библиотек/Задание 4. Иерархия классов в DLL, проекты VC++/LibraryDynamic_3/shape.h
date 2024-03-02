#pragma once

#include <iostream>
#include "determineApi.h"

class Shape {
protected:
    int numberCorners;
    std::string name;
public:
    LIB_API Shape();
    LIB_API virtual void print();
};