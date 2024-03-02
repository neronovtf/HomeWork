#pragma once

#include <iostream>

#ifdef MY_EXE
    #define FROJ_LIB __declspec(dllexport)
#else
    #define FROJ_LIB __declspec(dllimport)
#endif

class Shape {
protected:
    int numberCorners;
    std::string name;
public:
    FROJ_LIB Shape();
    FROJ_LIB virtual void print();
};