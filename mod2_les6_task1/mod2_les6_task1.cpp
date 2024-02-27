#include <iostream>
#include <Windows.h>
#define MODE 1

#if MODE == 1
void add() {
    int x, y;
    std::cout << "Работаю в боевом режиме" << std::endl;

    std::cout << "Введите число 1: ";
    std::cin >> x;

    std::cout << "Введите число 2: ";
    std::cin >> y;

    std::cout << "Результат сложения: " << (x + y) << std::endl;
}
#endif

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

#if MODE == 0
    std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
    add();
#else
    std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif

    return 0;
}