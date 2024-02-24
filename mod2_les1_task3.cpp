
#include <iostream>
#include <cstring>
#include <Windows.h>

struct address {
    std::string city;
    std::string street;
    int home;
    int flat;
    int index;
};

void console(address* addr) {
    std::cout <<
        "Город: " << addr->city << "\n" <<
        "Улица: " << addr->street << "\n" <<
        "Номер дома: " << addr->home << "\n" <<
        "Номер квартиры: " << addr->flat << "\n" <<
        "Индекс: " << addr->index << "\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    address addr = { "Москва", "Арбат", 12, 8, 123456 };
    console(&addr);
    std::cout << std::endl;

    addr = { "Псков", "Пушкина", 5, 70, 702900 };
    console(&addr);

    return 0;
}