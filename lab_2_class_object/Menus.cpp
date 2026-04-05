#include <iostream>
#include <fstream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "ElectricCar.h"
#include "FileManager.h"
#include "Menus.h"

void adminMenu() {
    int choice;
    std::vector<std::shared_ptr<Vehicle>> vehicles;

    do {
        system("cls");
        std::cout << "----- Admin Automobile Rent Menu -----\n1. Add Car\n2. Add Electric Car\n0. Exit\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1: {
            FileManager::loadVehicles(vehicles);
            std::string brand;
            std::string model;
            int year;
            double pricePerDay;

            std::cin >> brand >> model >> year >> pricePerDay;

            vehicles.push_back(std::make_shared<Car>(brand, model, year, pricePerDay));
        }
              std::cout << "Car created seccesfully!\n";
              FileManager::saveVehicles(vehicles);
              system("pause");
              break;
        case 2: {

            std::string brand;
            std::string model;
            int year;
            double pricePerDay;
            double betteryCapacity;
            double range;

            std::cin >> brand >> model >> year >> pricePerDay >> betteryCapacity >> range;

            vehicles.push_back(std::make_shared<ElectricCar>(brand, model, year, pricePerDay, betteryCapacity, range));
        }
              std::cout << "Electric Car created seccesfully!\n";
              system("pause");
              break;

        default:
            break;
        }
    } while (choice != 0);
}

void userMenu(){
    int choice;
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    do {
        system("cls");
        std::cout << "----- User Automobile Rent Menu -----\n1. See avalible cars\n2. Rent\n0. Exit\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1: {
            FileManager::loadVehicles(vehicles);
            std::cout << "Avalible cars: " << std::endl;
            for (const auto& vehicle : vehicles) {
                vehicle->showInfo();
            }
            system("pause");
        }

              break;
        case 2: 

              break;

        default:
            break;
        }
    } while (choice != 0);
}