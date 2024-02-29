#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Address {
private:
    std::string city;
    std::string street;
    std::string house;
    std::string flat;
    int allCountItem; // хранит в себе информацию о количестве адресов из одного файла
public:
    Address() {
        this->city = "";
        this->street = "";
        this->house = "";
        this->flat = "";
        this->allCountItem = 0;
    }
    Address(std::string* arr) {
        this->city = arr[0];
        this->street = arr[1];
        this->house = arr[2];
        this->flat = arr[3];
        this->allCountItem = std::stoi(arr[4]);
    }
    std::string text() {
        return this->city + ", " + this->street + ", " + this->house + ", " + this->flat;
    }
    int totalNumber() {
        return this->allCountItem;
    }
};

Address* readFromFile(std::string pathReadFile) {
    std::ifstream readFile(pathReadFile);
    
    if (readFile.is_open()) {
        std::string text;
        bool isFirst = true;
        int index = 0;
        int countRowInBox = 4;
        std::string* save = new std::string[countRowInBox + 1]; // доп.параметр, это кол-во элементов ..
        
        readFile >> text;
        int countAddr = std::stoi(text);

        Address* arr = new Address[countAddr];
        int rows = countAddr - 1;

        while (!readFile.eof()) {
            readFile >> text;
                
            save[index] = text;
            ++index;

            if (index == countRowInBox) {
                save[index] = std::to_string(countAddr); // вот тут добавляет

                arr[rows] = Address(save);

                index = 0;
                --rows;
            }
        }

        readFile.close();
        std::cout << "Чтение данных из файла (" + pathReadFile + "), закончены!" << std::endl;

        delete[] save;

        return arr;
    }
    else {
        std::cout << "Файл (" + pathReadFile + ") не доступен!" << std::endl;

        Address nullAddr;
        return new Address[0]{ nullAddr };
    }
}

void saveInFile(std::string pathWriteFile, Address* adds) {
    std::ofstream writeFile(pathWriteFile);
    int size = adds[0].totalNumber();
    writeFile << size << std::endl;

    for (int i = 0; i < size; i++) {
        writeFile << adds[i].text() << std::endl;
    }

    writeFile.close();
    std::cout << "Запись данных в файл (" + pathWriteFile + "), закончена!" << std::endl;
}


int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string pathReadFile = "E:\\files\\in.txt";
    std::string pathWriteFile = "E:\\files\\out.txt";

    Address* adds = readFromFile(pathReadFile);

    if (adds[0].totalNumber() > 0) {
        saveInFile(pathWriteFile, adds);
    }
    else {
        std::cout << "Данные из файла (" + pathReadFile + "), не получены!" << std::endl;
    }
    delete[] adds;

    return 0;
}