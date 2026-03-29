#include <iostream>
#include <fstream>
#include "Car.h"
#include "Client.h"
#include "Rental.h"
#include "ElectricCar.h"
#include "VIPClient.h"

void printInfo(const Vehicle& v)
{
    v.showInfo();
}


int main() {

    int choise;
    std::cout << "----- Automobile Rent Menu -----\n1. Login as user\n2. Login as admin\n3. Exit\nYour choise: ";
    std::cin >> choise;
    switch (choise)
    {
    case 1:

    default:
        break;
    }
    return 0;

}