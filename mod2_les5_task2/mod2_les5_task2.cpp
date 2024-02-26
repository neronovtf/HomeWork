#include <iostream>
#include <Windows.h>
#include "calc.h"

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string answer;
    int user_number = 0;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> answer;

    Counter count;

    if (answer.length() == 2) {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> user_number;
        count = Counter(user_number);
    }

    char symbol;
    bool flag = true;
    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> symbol;

        switch (symbol) {
        case '+': count.level_up(); break;
        case '-': count.level_down(); break;
        case '=': count.get_num(); break;
        case 'x':
            std::cout << "До свидания!" << std::endl;
            flag = false;
            break;
        }
    } while (flag);

    return 0;
}