#include "FileManager.h"
#include <iostream>
#include <fstream>
#include "Car.h"
#include "ElectricCar.h"

std::shared_ptr<Vehicle> findVehicleById(const std::vector<std::shared_ptr<Vehicle>>& vehicles, int id)
{
    for (auto& v : vehicles) {
        if (v->getId() == id)
            return v;
    }
    return nullptr;
}

std::shared_ptr<Client> findClientByLicense(const std::vector<std::shared_ptr<Client>>& clients, const std::string& license)
{
    for (auto& c : clients) {
        if (c->getLicense() == license)
            return c;
    }
    return nullptr;
}

void FileManager::saveVehicles(const std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    std::ofstream file("vehicles.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open vehicles.txt");
    }
    for (auto& v : vehicles) {
        v->save(file);
    }
}

void FileManager::loadVehicles(std::vector<std::shared_ptr<Vehicle>>& vehicles) {
    vehicles.clear();

    std::ifstream file("vehicles.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open vehicles.txt");
    }
    std::string type;

    while (file >> type) {

        if (type == "Car") {
            int Id;
            std::string brand;
            std::string model;
            int year;
            double pricePerDay;

            file >> Id >> brand >> model >> year >> pricePerDay;

            vehicles.push_back(std::make_shared<Car>(Id, brand, model, year, pricePerDay));
        }

        else if (type == "ElectricCar") {
            int Id;
            std::string brand;
            std::string model;
            int year;
            double pricePerDay;
            double battery;
            double range;

            file >> Id >> brand >> model >> year >> pricePerDay >> battery >> range;

            vehicles.push_back(std::make_shared<ElectricCar>(Id, brand, model, year, pricePerDay, battery, range));
        }
    }
}

void FileManager::saveRentals(const std::vector<std::shared_ptr<Rental>>& rentals)
{
    std::ofstream file("rentals.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open rentals.txt");
    }
    for (auto& r : rentals) {
        r->save(file);
    }
}

void FileManager::loadRentals(std::vector<std::shared_ptr<Rental>>& rentals, std::vector<std::shared_ptr<Client>>& clients, std::vector<std::shared_ptr<Vehicle>>& vehicles)
{
    rentals.clear();
            std::ifstream file("rentals.txt");
            if (!file.is_open()) {
                throw std::runtime_error("Cannot open rentals.txt");
            }
            int vehicleId;
            std::string license;
            int days;

            while (file >> license >> vehicleId >> days) {

                auto vehicle = findVehicleById(vehicles, vehicleId);
                auto client = findClientByLicense(clients, license);

                if (vehicle && client) {
                    rentals.push_back(
                        std::make_shared<Rental>(vehicle, client, days)
                    );
                }
                else {
                    std::cout << "Error: vehicle or client not found!\n";
                }
            }
}

void FileManager::saveClients(const std::vector<std::shared_ptr<Client>>& clients)
{
    std::ofstream file("clients.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open clients.txt");
    }
    for (auto& c : clients) {
        c->save(file);
    }
}

void FileManager::loadClients(std::vector<std::shared_ptr<Client>>& clients)
{
    clients.clear();
    std::ifstream file("clients.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open clients.txt");
    }
    std::string name;
    std::string license;
    std::string phone;
    while (file >> name >> license >> phone)
        clients.push_back(std::make_shared<Client>(name, license, phone));
}

void FileManager::saveHistory(const std::vector<History>& history) {
    std::ofstream file("history.txt", std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open history.txt");
    }
    for (const auto& h : history) {
        h.save(file);
    }
}

void FileManager::loadHistory(std::vector<History>& history) {
    history.clear();
    std::ifstream file("history.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open history.txt");
    }
    std::string line;
    while (std::getline(file, line)) {
        history.push_back(History(line));
    }
}