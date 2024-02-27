#include <iostream>
#include <Windows.h>

int howLength(std::string str, int forbidden_length) {

    int leng = str.length();
    if (leng != forbidden_length) {
        return leng;
    }

    throw "bad_length";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int lengthWord;
    std::cout << "Введите запретную длину: ";
    std::cin >> lengthWord;

    std::string word;

    try{
        do {
            std::cout << "Введите слово: ";
            std::cin >> word;

            std::cout << "Длина слова \"" << word << "\" равна " << howLength(word, lengthWord) << std::endl;
        }
        while (true);
    }
    catch (const char* error) { std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl; }
    catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

    return 0;
}