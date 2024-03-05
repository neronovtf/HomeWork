#include <iostream>
#include <Windows.h>

#include "transport.h"
#include "airTransport.h"
#include "landTransport.h"
#include "transport.h"
#include "track.h"
#include "error.h"
#include "boots.h"
#include "broom.h"
#include "camel.h"
#include "centaur.h"
#include "eagle.h"
#include "camelSpeed.h"
#include "carpet.h"

int userChoice(int count, std::string* variants, std::string question) {
    int choice = 0;
    int userSelect = 0;
    bool flag = true;
    do {
        for (int i = 0; i < count; i++) {
            std::cout << (i + 1) << ".  " + variants[i] << std::endl;
        }
        std::cout << question;
        std::cin >> userSelect;

        if (userSelect > 0 && userSelect <= count) {
            flag = false;
            choice = userSelect;
        }
    }
    while (flag);

    return choice;
}

void minTwoTransport() {
    int action;
    bool flag = true;
    do {
        std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
        std::cout << "1.  Зарегистрировать транспорт" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> action;
        if (action == 1) {
            flag = false;
        }
        else {
            std::cout << "Введён некорректный пункт меню ... Повторите попытку!" << std::endl;
        }
    }
    while (flag);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool flag = true;
    std::cout << "Добро пожаловать в гоночный симулятор !" << std::endl;
    do {
        try {
            int typeTrack, distance, action;
            Track track;
            for (int i = 1; i < 4; i++) {
                std::cout << i << ".  " + track.getDesriptionRacingTrackByNumberType(i)  << std::endl;
            }
            std::cout << "Выберите тип гонки: ";
            std::cin >> typeTrack;

            track.setType(typeTrack);

            std::cout << "Укажите длину дистанции (должна быть положительна): ";
            std::cin >> distance;

            track.setDistance(distance);

            minTwoTransport();

            Boots boots;
            Broom broom;
            Camel camel;
            Centaur centaur;
            Eagle eagle;
            CamelSpeed camelSpeed;
            Carpet carpet;

            int size, userSelect;
            std::string* variants;

            bool flagTransport = true;
            bool canAdded = true;
            int countTransportInTrack = 0;
            Transport* userSelectTransport;
            do {
                std::cout << track.getDesriptionRacingTrackByNumberType(typeTrack) + ". Расстояние: " << distance << std::endl;

                countTransportInTrack = track.numberAddedTransport();
                if (countTransportInTrack) {
                    std::cout << "Зарегистрированные транспортные средства: ";
                    for (int i = 0; i < countTransportInTrack; i++) {
                        std::cout << track.getTransportByIndex(i).getName() + ( i != countTransportInTrack -1 ? ", " : "");
                    }
                    std::cout << std::endl;
                }

                int userSelect;
                std::cout << "1.  " + boots.getName() << std::endl;
                std::cout << "2.  " + broom.getName() << std::endl;
                std::cout << "3.  " + camel.getName() << std::endl;
                std::cout << "4.  " + centaur.getName() << std::endl;
                std::cout << "5.  " + eagle.getName() << std::endl;
                std::cout << "6.  " + camelSpeed.getName() << std::endl;
                std::cout << "7.  " + carpet.getName() << std::endl;
                std::cout << "0.  Закончить регистрацию" << std::endl;
                std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
                std::cin >> userSelect;

                if (userSelect >= 0 && userSelect < 8) {
                    switch (userSelect) {
                        case 1: userSelectTransport = &boots; break;
                        case 2: userSelectTransport = &broom; break;
                        case 3: userSelectTransport = &camel; break;
                        case 4: userSelectTransport = &centaur; break;
                        case 5: userSelectTransport = &eagle; break;
                        case 6: userSelectTransport = &camelSpeed; break;
                        case 7: userSelectTransport = &carpet; break;
                        case 0:
                            if (track.numberAddedTransport() < 2) {
                                minTwoTransport();
                            }
                            else {
                                flagTransport = false;
                            }
                            break;
                    }

                    if (!flagTransport) {
                        size = 2;
                        variants = new std::string[size];
                        variants[0] = "Зарегистрировать транспорт";
                        variants[1] = "Начать гонку";
                        userSelect = userChoice(size, variants, "Выберите действие: ");
                        delete[] variants;
                        if (userSelect == 1) {
                            flagTransport = true;
                        }
                    }
                    else {
                        switch (track.addNewTransport(userSelectTransport)){
                            case 1:
                                std::cout << (*userSelectTransport).getName() + " успешно добавлена!" << std::endl;
                                break;
                            case 0:
                                std::cout << (*userSelectTransport).getName() + " уже зарегистрирован!" << std::endl;
                                break;
                            case -1:
                                std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                                break;
                        }
                    }
                }
                else {
                    std::cout << "Введён некорректный пункт меню ... Повторите попытку!" << std::endl;
                }
            }
            while (flagTransport);

            track.start();

            std::cout << "Результат гонки:" << std::endl;
            Transport* itogListTC = track.getAllTransport();
            for (int i = 0; i < track.numberAddedTransport(); i++) {
                std::cout 
                    << (i + 1) << ".  "
                    << itogListTC[i].getName() << ". "
                    << "Время: " << itogListTC[i].getTime()
                    << std::endl;
            }
            std::cout <<  std::endl;

            size = 2;
            variants = new std::string[size];
            variants[0] = "Провести ещё одну гонку";
            variants[1] = "Выйти";
            userSelect = userChoice(size, variants, "Выберите действие: ");
            delete[] variants;
            if (userSelect == 2) {
                flag = false;
            }
        }
        catch (Error& ex) {
            std::cout << ex.getText() << std::endl;
            std::cout << std::endl;
            char x;
            std::cout << "Хотите начать заново, не допуская ошибок?(y/n) ";
            std::cin >> x;
            if (x != 'y') {
                flag = false;
            }
        }
    }
    while (flag);

    return 0;
}