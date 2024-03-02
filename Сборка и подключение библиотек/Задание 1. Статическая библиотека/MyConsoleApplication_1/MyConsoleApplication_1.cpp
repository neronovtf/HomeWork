﻿#include <iostream>
#include <Windows.h>
#include "Greeter.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;

    Greeter greeter;

    std::cout << greeter.greet(name) << std::endl;

    return 0;
}