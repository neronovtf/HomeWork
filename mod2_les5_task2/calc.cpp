#include "iostream"
#include "calc.h"

void Counter::level_up() { ++this->number; };
void Counter::level_down() { --this->number; };
void Counter::get_num() { std::cout << this->number << std::endl; };
Counter::Counter() { this->number = 1; };
Counter::Counter(int num) {
    if (num != 0)
        this->number = num;
    else
        this->number = 1;
};