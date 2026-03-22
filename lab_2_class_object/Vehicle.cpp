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

void Vehicle::showInfo() const {
    std::cout << brand << " " << model << " (" << year << ")";
}