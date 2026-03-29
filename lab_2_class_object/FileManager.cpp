#include "FileManager.h"
#include <fstream>
#include "Car.h"

void FileManager::saveVehicles(const std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    std::ofstream file("vehicles.txt");

    for (auto& v : vehicles) {
        file << v->getBrand() << " " << v->getModel() <<" " << v->getYear() << std::endl;
    }
}

void FileManager::loadVehicles(std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    std::ifstream file("vehicles.txt");

    std::string brand;
    std::string model;
    int year;
    double prisePerDay;

    while (file >> brand >> model >> year) {
        vehicles.push_back(std::make_shared<Car>(brand, model, year, prisePerDay));
    }
}