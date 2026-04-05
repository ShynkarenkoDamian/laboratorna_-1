#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle() : Id(999), brand("Unknown"), model("Unknown"), year(0) {
    
}

Vehicle::Vehicle(int Id, std::string b, std::string m, int y)
    : Id(Id), brand(b), model(m), year(y) {
}

Vehicle::Vehicle(const Vehicle& other)
    : Id(other.Id), brand(other.brand), model(other.model), year(other.year) {
    
}

Vehicle::Vehicle(Vehicle&& other) noexcept
    : Id(other.Id), brand(other.brand), model(other.model), year(other.year) {

    other.Id = 0;
    other.brand = "";
    other.model = "";
    other.year = 0;

    
}

Vehicle::~Vehicle() {
    
}

std::string Vehicle::getBrand() const
{
    return this->brand;
}

std::string Vehicle::getModel() const
{
    return this->model;
}

int Vehicle::getYear() const
{
    return this->year;
}


Vehicle& Vehicle::operator=(const Vehicle& other)
{
    if (this != &other)
    {
        Id = other.Id;
        brand = other.brand;
        model = other.model;
        year = other.year;
    }
    return *this;
}

void Vehicle::display() const {
    std::cout << brand << " " << model << " (" << year << ")" << std::endl;
}

void Vehicle::showInfo() const {
    std::cout << "--------------------\n" << "Id: " << Id << std::endl
        <<"Brand: " << brand <<std::endl<< " " 
        <<"Model: "<< model << " (" << year << ")" << std::endl;
}

void Vehicle::getPricePerDay() const
{}
