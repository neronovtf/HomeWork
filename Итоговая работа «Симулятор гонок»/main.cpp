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
        std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������" << std::endl;
        std::cout << "1.  ���������������� ���������" << std::endl;
        std::cout << "�������� ��������: ";
        std::cin >> action;
        if (action == 1) {
            flag = false;
        }
        else {
            std::cout << "����� ������������ ����� ���� ... ��������� �������!" << std::endl;
        }
    }
    while (flag);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool flag = true;
    std::cout << "����� ���������� � �������� ��������� !" << std::endl;
    do {
        try {
            int typeTrack, distance, action;
            Track track;
            for (int i = 1; i < 4; i++) {
                std::cout << i << ".  " + track.getDesriptionRacingTrackByNumberType(i)  << std::endl;
            }
            std::cout << "�������� ��� �����: ";
            std::cin >> typeTrack;

            track.setType(typeTrack);

            std::cout << "������� ����� ��������� (������ ���� ������������): ";
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
                std::cout << track.getDesriptionRacingTrackByNumberType(typeTrack) + ". ����������: " << distance << std::endl;

                countTransportInTrack = track.numberAddedTransport();
                if (countTransportInTrack) {
                    std::cout << "������������������ ������������ ��������: ";
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
                std::cout << "0.  ��������� �����������" << std::endl;
                std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
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
                        variants[0] = "���������������� ���������";
                        variants[1] = "������ �����";
                        userSelect = userChoice(size, variants, "�������� ��������: ");
                        delete[] variants;
                        if (userSelect == 1) {
                            flagTransport = true;
                        }
                    }
                    else {
                        switch (track.addNewTransport(userSelectTransport)){
                            case 1:
                                std::cout << (*userSelectTransport).getName() + " ������� ���������!" << std::endl;
                                break;
                            case 0:
                                std::cout << (*userSelectTransport).getName() + " ��� ���������������!" << std::endl;
                                break;
                            case -1:
                                std::cout << "������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
                                break;
                        }
                    }
                }
                else {
                    std::cout << "����� ������������ ����� ���� ... ��������� �������!" << std::endl;
                }
            }
            while (flagTransport);

            track.start();

            std::cout << "��������� �����:" << std::endl;
            Transport* itogListTC = track.getAllTransport();
            for (int i = 0; i < track.numberAddedTransport(); i++) {
                std::cout 
                    << (i + 1) << ".  "
                    << itogListTC[i].getName() << ". "
                    << "�����: " << itogListTC[i].getTime()
                    << std::endl;
            }
            std::cout <<  std::endl;

            size = 2;
            variants = new std::string[size];
            variants[0] = "�������� ��� ���� �����";
            variants[1] = "�����";
            userSelect = userChoice(size, variants, "�������� ��������: ");
            delete[] variants;
            if (userSelect == 2) {
                flag = false;
            }
        }
        catch (Error& ex) {
            std::cout << ex.getText() << std::endl;
            std::cout << std::endl;
            char x;
            std::cout << "������ ������ ������, �� �������� ������?(y/n) ";
            std::cin >> x;
            if (x != 'y') {
                flag = false;
            }
        }
    }
    while (flag);

    return 0;
}