#include <iostream>
#include <cstring>
#include <Windows.h>

class Calculator{
    private:
        double num1;
        double num2;
    public:
        double add(){ return num1 + num2; };
        double multiply(){ return num1 * num2; };
        double subtract_1_2(){ return num1 - num2; };
        double subtract_2_1(){ return num2 - num1; };
        double divide_1_2(){ return num1 / num2; };
        double divide_2_1(){ return num2 / num1; };
        bool set_num1(double num1){
            if(num1 != 0){
                this->num1 = num1;
            }
            else{
                std::cout << "Неверный ввод!" << std::endl;
            }

            return num1 != 0;
        };
        bool set_num2(double num2){
            if(num2 != 0){
                this->num2 = num2;
            }
            else{
                std::cout << "Неверный ввод!" << std::endl;
            }
            
            return num2 != 0;
        };
        void print_all_metods(){
            std::cout << "num1 + num2 = " << add() << std::endl;
            std::cout << "num1 - num2 = " << subtract_1_2() << std::endl;
            std::cout << "num2 - num1 = " << subtract_2_1() << std::endl;
            std::cout << "num1 * num2 = " << multiply() << std::endl;
            std::cout << "num1 / num2 = " << divide_1_2() << std::endl;
            std::cout << "num2 / num1 = " << divide_2_1() << std::endl;
            std::cout << std::endl;
        }
};

int main() // Задача 1. Калькулятор двух чисел
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Calculator calc;

    do{
        double num1, num2;

        do{
            std::cout << "Введите num1: ";
            std::cin >> num1;
        }while(!calc.set_num1(num1));

        do{
            std::cout << "Введите num2: ";
            std::cin >> num2;
        }while(!calc.set_num2(num2));

        calc.print_all_metods();
    }
    while(true); // классика, никогда не устаревает =)

    return 0;
}