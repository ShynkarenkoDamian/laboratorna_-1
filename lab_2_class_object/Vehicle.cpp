#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle() : brand("Unknown"), model("Unknown"), year(0) {
    std::cout << "Vehicle default constructor\n";
}

Vehicle::Vehicle(std::string b, std::string m, int y)
    : brand(b), model(m), year(y) {
    std::cout << "Vehicle parameter constructor\n";
}

Vehicle::Vehicle(const Vehicle& other)
    : brand(other.brand), model(other.model), year(other.year) {
    std::cout << "Vehicle copy constructor\n";
}

Vehicle::Vehicle(Vehicle&& other) noexcept
    : brand(other.brand), model(other.model), year(other.year) {

    other.brand = "";
    other.model = "";
    other.year = 0;

    std::cout << "Vehicle move constructor\n";
}

Vehicle::~Vehicle() {
    std::cout << "Vehicle destroyed\n";
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
    std::cout << brand << " " << model << " (" << year << ")" << std::endl;
}

void Vehicle::getPricePerDay() const
{}

void Vehicle::showInfoStaticBinding() const
{
    std::cout << "Base class function\n";
}
