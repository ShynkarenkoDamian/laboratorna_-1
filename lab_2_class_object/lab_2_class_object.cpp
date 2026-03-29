#include <iostream>
#include <fstream>
#include <vector>
#include "Car.h"
#include "Client.h"
#include "Rental.h"
#include "ElectricCar.h"
#include "VIPClient.h"
#include "Menus.h"

void printInfo(const Vehicle& v)
{
    v.showInfo();
}


int main() {
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    int choiсe;
    do {
        std::cout << "----- Automobile Rent Menu -----\n1. Login as user\n2. Login as admin\n0. Exit\nYour choise: ";
        std::cin >> choiсe;
        switch (choiсe)
        {
        case 1: {
            userMenu(vehicles);
            system("cls");
            break;
        }
        case 2:
            adminMenu(vehicles);
            system("cls");
        default:
            break;
        }
    } while (choiсe != 0);
    return 0;

}