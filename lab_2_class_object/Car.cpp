#include "Car.h"
#include <iostream>

// delegation constructor
Car::Car() : Car("Unknown", "Unknown", 2000, 50.0) {
    std::cout << "delegation constructor was called" << std::endl;
}
// constructor with args
Car::Car(std::string b, std::string m, int y, double price)
    : brand(b), model(m), year(y), pricePerDay(price) {
    std::cout << "car default constructor was called" << std::endl;
}
Car::Car(const Car& other)
    : brand(other.brand),
    model(other.model),
    year(other.year),
    pricePerDay(other.pricePerDay)
{
    std::cout << "Copy car constructor called\n";
}

Car::Car(Car&& other) noexcept
    : brand(other.brand),
    model(other.model),
    year(other.year),
    pricePerDay(other.pricePerDay)
{
    other.brand = nullptr;
    other.model = nullptr;
    other.year = 0;
    other.pricePerDay = 0;

    std::cout << "Move constructor called\n";
}

// destructor
Car::~Car() {
    std::cout << "destructed " << brand << " " << model << std::endl;
}

double Car::calculateCost(int days) const {
    return pricePerDay * days;
}


void Car::showInfo() const {
    std::cout << brand << " " << model << " (" << year << ") - " << pricePerDay << "$/day\n";
}