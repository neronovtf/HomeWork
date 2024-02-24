#include <iostream>
#include <cstring>
#include <Windows.h>

class Counter{
    private:
        int number;
    public:
        void level_up(){ ++this->number; };
        void level_down(){ --this->number; };
        void get_num(){ std::cout << this->number << std::endl; };

        Counter(){
            this->number = 1;
        };
        
        Counter(int num){
            if(num != 0)
                this->number = num;
            else
                this->number = 1;
        };

};

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::string answer;
    int user_number = 0;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> answer;

    if(answer.length() == 2){
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> user_number;
    }

    Counter count(user_number);

    char symbol;
    bool flag = true;
    do{
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> symbol;

        switch (symbol){
            case '+': count.level_up(); break;
            case '-': count.level_down(); break;
            case '=': count.get_num(); break;
            case 'x': 
                std::cout << "До свидания!" << std::endl;
                flag = false;
                break;
        }
    }
    while(flag);

    return 0;
}