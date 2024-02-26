#include <iostream>
#include <Windows.h>
#include "calc.h"

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x, y, z = 0;
	std::cout << "Введите первое число: ";
	std::cin >> x;
	std::cout << "Введите второе число: ";
	std::cin >> y;
	std::cout << std::endl;

	do {
		std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень, 0 - выход): ";
		std::cin >> z;

		switch (z){
			case 1: std::cout << x << " плюс " << y << " = " << addition(x, y) << std::endl; break;
			case 2: std::cout << x << " минус " << y << " = " << subtraction(x, y) << std::endl; break;
			case 3: std::cout << x << " умножить на " << y << " = " << multiplication(x, y) << std::endl; break;
			case 4: std::cout << x << " делить на " << y << " = " << division(x, y) << std::endl; break;
			case 5: std::cout << x << " в степени " << y << " = " << exponentiation(x, y) << std::endl; break;
		}

	} while (z);

	return 0;
}
