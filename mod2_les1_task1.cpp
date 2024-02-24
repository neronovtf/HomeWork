
#include <iostream>
#include <cstring>
#include <Windows.h>

enum mount {
    january = 1,
    february = 2,
    march = 3,
    april = 4,
    may = 5,
    june = 6,
    july = 7,
    august = 8,
    september = 9,
    october = 10,
    november = 11,
    december = 12
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numberMount = 0;
    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> numberMount;
        if (numberMount > 0)
            switch (numberMount) {
            case mount::january:    std::cout << "Январь" << std::endl;       break;
            case mount::february:   std::cout << "Февраль" << std::endl;      break;
            case mount::march:      std::cout << "Март" << std::endl;         break;
            case mount::april:      std::cout << "Апрель" << std::endl;       break;
            case mount::may:        std::cout << "Май" << std::endl;          break;
            case mount::june:       std::cout << "Июнь" << std::endl;         break;
            case mount::july:       std::cout << "Июль" << std::endl;         break;
            case mount::august:     std::cout << "Август" << std::endl;       break;
            case mount::september:  std::cout << "Сентябрь" << std::endl;     break;
            case mount::october:    std::cout << "Октябрь" << std::endl;      break;
            case mount::november:   std::cout << "Ноябрь" << std::endl;       break;
            case mount::december:   std::cout << "Декабрь" << std::endl;      break;
            default:    std::cout << "Неправильный номер!" << std::endl;      break;
            }
    } while (numberMount > 0);
    std::cout << "До свидания" << std::endl;

    return 0;
}