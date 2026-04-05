#include <iostream>
#include <fstream>
#include <vector>
#include "Car.h"
#include "Client.h"
#include "Rental.h"
#include "ElectricCar.h"
#include "VIPClient.h"
#include "Menus.h"
#include "FileManager.h"


int main() {
    
    int choiсe;
    do {
        std::cout << "----- Automobile Rent Menu -----\n1. Login as user\n2. Login as admin\n0. Exit\nYour choise: ";
        std::cin >> choiсe;
        switch (choiсe)
        {
        case 1: {
            userMenu();
            system("cls");
            break;
        }
        case 2: {
            std::string pin = "5834";
            std::string enter;
                std::cout << "Enter pin-code: ";
                std::cin >> enter;
                if (enter == pin) {
                    adminMenu();
                }
                else {
                    std::cout << "Wrong pin!\n";
                    system("pause");
                    system("cls");
                    break;
                }
            
        }
        default:
            break;
        }
    } while (choiсe != 0);
    return 0;

}