#include <iostream>
#include <Windows.h>
#include "Leaver.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string name;
    std::cout << "¬ведите им€: ";
    std::cin >> name;

    Leaver leaver;
    std::cout << leaver.leave(name) << std::endl;

    return 0;
}