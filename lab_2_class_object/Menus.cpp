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
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Rental>> rentals;
    do {
        system("cls");
        std::cout << "----- Admin Automobile Rent Menu -----\n1. Add Car\n2. Add Electric Car\n3. View rentals\n0. Exit\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1: {
            FileManager::loadVehicles(vehicles);
            int Id;
            std::string brand;
            std::string model;
            int year;
            double pricePerDay;

            std::cin >> Id >> brand >> model >> year >> pricePerDay;

            vehicles.push_back(std::make_shared<Car>(Id, brand, model, year, pricePerDay));

            std::cout << "Car created seccesfully!\n";
            FileManager::saveVehicles(vehicles);
            system("pause");
            break;
        }
        case 2: {
            FileManager::loadVehicles(vehicles);
            int Id;
            std::string brand;
            std::string model;
            int year;
            double pricePerDay;
            double betteryCapacity;
            double range;

            std::cin >> Id >> brand >> model >> year >> pricePerDay >> betteryCapacity >> range;

            vehicles.push_back(std::make_shared<ElectricCar>(Id, brand, model, year, pricePerDay, betteryCapacity, range));

            std::cout << "Electric Car created seccesfully!\n";
            FileManager::saveVehicles(vehicles);
            system("pause");
            break;
        }
        case 3:
            FileManager::loadClients(clients);
            FileManager::loadVehicles(vehicles);
            FileManager::loadRentals(rentals, clients, vehicles);

            for (auto& r : rentals) {
                r->showInfo();
                std::cout << "--------------------\n";
            }
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
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Rental>> rentals;
    do {
        system("cls");
        std::cout << "----- User Automobile Rent Menu -----\n1. See avalible cars\n2. Rent\n0. Exit\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1: {
            FileManager::loadClients(clients);
            FileManager::loadVehicles(vehicles);
            FileManager::loadRentals(rentals, clients, vehicles);
            std::cout << "Avalible cars: " << std::endl;
            for (const auto& vehicle : vehicles) {
                vehicle->showInfo();
            }
            system("pause");
        }

              break;
        case 2: {
			FileManager::loadVehicles(vehicles);
            if (vehicles.empty()) {
                std::cout << "No vehicles available!\n";
                system("pause");
                break;
            }

            for (const auto& v : vehicles) {
                v->showInfo();
            }

            int vehicleId;
            std::cout << "Enter vehicle ID: ";
            std::cin >> vehicleId;

            std::shared_ptr<Vehicle> selectedVehicle = nullptr;

                for (auto& v : vehicles) {
                    if (v->getId() == vehicleId)
                        selectedVehicle = v;
                }

            if (!selectedVehicle) {
                std::cout << "Vehicle not found!\n";
                system("pause");
                break;
            }


            std::string name, license, phone;
            std::cout << "Enter name license phone: ";
            std::cin >> name >> license >> phone;


            int days;
            std::cout << "Enter number of days: ";
            std::cin >> days;

            auto client = std::make_shared<Client>(name, license, phone);
            clients.push_back(client);

            auto rental = std::make_shared<Rental>(selectedVehicle, client, days);
            rentals.push_back(rental);


            FileManager::saveClients(clients);
            FileManager::saveRentals(rentals);

            std::cout << "Car rented successfully!\n";
            system("pause");

            break;
        }

        default:
            break;
        }
    } while (choice != 0);
}