#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class withFile {
private:
    std::string pathReadFile;
    std::string pathWriteFile;
    int countRowInBox = 4;
    int countAddr = 0;
    std::string** arr;

    void createArr() {
        this->arr = new std::string* [this->countAddr];
        for (int i = 0; i < this->countAddr; i++) {
            this->arr[i] = new std::string[this->countRowInBox];
        }

        for (int i = 0; i < this->countAddr; i++) {
            for (int j = 0; j < this->countRowInBox; j++) {
                this->arr[i][j] = "-";
            }
        }
    };

    bool readFromFile() {
        std::ifstream readFile(this->pathReadFile);

        if (readFile.is_open()) {
            std::string text;
            bool isFirst = true;
            int index = 0;
            int rows = 0;
        
            while (!readFile.eof()) {
                readFile >> text;
                
                if (isFirst) {
                    this->countAddr = std::stoi(text);
                    createArr();
                    isFirst = false;
                    rows = this->countAddr - 1;
                }
                else {
                    this->arr[rows][index] = text;
                    ++index;

                    if (index == this->countRowInBox) {
                        index = 0;
                        --rows;
                    }
                }
            }
            
            readFile.close();
            std::cout << "Чтение данных из файла (" + this->pathReadFile + "), закончены!" << std::endl;
            return true;
        }
        else {
            std::cout << "Файл (" + this->pathReadFile + ") не доступен!" << std::endl;
            return false;
        }
    }
    
    void writingToFile() {
        std::ofstream writeFile(this->pathWriteFile);

        writeFile << this->countAddr << std::endl;

        std::string text;
        for (int i = 0; i < this->countAddr; i++) {
            for (int j = 0; j < this->countRowInBox; j++) {
                text += this->arr[i][j] + (j == this->countRowInBox-1 ? "" : ", ");
            }
            writeFile << text << std::endl;
            text = "";
        }

        writeFile.close();
        std::cout << "Запись данных в файл (" + this->pathWriteFile + "), закончена!" << std::endl;
    }

public:
    withFile(std::string pathReadFile, std::string pathWriteFile) {
        this->pathReadFile = pathReadFile;
        this->pathWriteFile = pathWriteFile;

        if (this->readFromFile()) {
            this->writingToFile();
        }
        std::cout << "Конец рабочего процесса!" << std::endl;
    }
};

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    withFile work("E:\\files\\in.txt", "E:\\files\\out.txt");

    return 0;
}