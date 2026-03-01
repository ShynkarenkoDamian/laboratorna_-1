#include "Car.h"
#include <iostream>

// defoult constructor
Car::Car() : Car("Unknown", "Unknown", 2000, 50.0) {
    std::cout << "delegation constructor was called" << std::endl;
}
// constructor with args
Car::Car(std::string b, std::string m, int y, double price)
    : brand(b), model(m), year(y), pricePerDay(price) {
    std::cout << "car constructor with arguments was called" << std::endl;
}

// destructor
Car::~Car() {
    std::cout << "car destructed " << brand << " " << model << std::endl;
}

double Car::calculateCost(int days) const {
    return pricePerDay * days;
}


void Car::showInfo() const {
    std::cout << brand << " " << model
        << " (" << year << ") - "
        << pricePerDay << "$/day\n";
}