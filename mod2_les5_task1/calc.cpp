#include "calc.h" // в cpp файлах обычно включают свой заголовочный файл

int addition(int x, int y){
	return x + y;
}

int subtraction(int x, int y) {
	return x - y;
}

int multiplication(int x, int y) {
	return x * y;
}

double division(int x, int y) {
	return static_cast<double>(x) / static_cast<double>(y);
}

int exponentiation(int x, int y) {
	int h = 1;
	for (int i = 0; i < y; i++) {
		h *= x;
	}
	return h;
}