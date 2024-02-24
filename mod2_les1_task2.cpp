
#include <iostream>
#include <cstring>
#include <Windows.h>

struct bank {
    int accountNumber;
    std::string userName;
    double money;
};

void editMoney(bank* acc, double money) {
    acc->money = money;
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int account;
    std::cout << "Введите номер счёта: ";
    std::cin >> account;

    std::string name;
    std::cout << "Введите имя владельца: ";
    std::cin >> name;

    double money;
    std::cout << "Введите баланс: ";
    std::cin >> money;

    double newMoney;
    std::cout << "Введите новый баланс: ";
    std::cin >> newMoney;

    bank acc = { account, name, money };

    editMoney(&acc, newMoney);

    std::cout << "Ваш счёт: " << acc.userName << ", " << acc.accountNumber << ", " << acc.money << std::endl;

    return 0;
}