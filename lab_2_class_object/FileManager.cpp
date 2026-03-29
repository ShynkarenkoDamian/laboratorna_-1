#include "FileManager.h"
#include <fstream>
#include "Car.h"
#include "ElectricCar.h"

void FileManager::saveVehicles(const std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    std::ofstream file("vehicles.txt", std::ios::app);

    for (auto& v : vehicles) {
        v->save(file);
    }
}

void FileManager::loadVehicles(std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    std::ifstream file("vehicles.txt");

    std::string type;

    while (file >> type) {

        if (type == "Car") {
            std::string brand;
            std::string model;
            int year;
            double pricePerDay;

            file >> brand >> model >> year >> pricePerDay;

            vehicles.push_back(std::make_shared<Car>(brand, model, year, pricePerDay));
        }

        else if (type == "ElectricCar") {
            std::string brand;
            std::string model;
            int year;
            double pricePerDay;
            double battery;
            double range;

            file >> brand >> model >> year >> pricePerDay >> battery >> range;

            vehicles.push_back(std::make_shared<ElectricCar>(brand, model, year, pricePerDay, battery, range));
        }
    }
}