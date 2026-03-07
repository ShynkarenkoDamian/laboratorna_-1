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
    carCount++;
}
Car::Car(const Car& other)
    : brand(other.brand),
    model(other.model),
    year(other.year),
    pricePerDay(other.pricePerDay)
{
    std::cout << "Copy car constructor called\n";
    carCount++;
}

Car::Car(Car&& other) noexcept
    : brand(other.brand),
    model(other.model),
    year(other.year),
    pricePerDay(other.pricePerDay)
{
    other.brand = "";
    other.model = "";
    other.year = 0;
    other.pricePerDay = 0;

    std::cout << "Move car constructor called\n";
}

// destructor
Car::~Car() {
    std::cout << "destructed " << brand << " " << model << std::endl;
    carCount--;
}

double Car::calculateCost(int days) const {
    return pricePerDay * days;
}


void Car::showInfo() const {
    std::cout << brand << " " << model << " (" << year << ") - " << pricePerDay << "$/day\n";
}

void Car::setPrice(double price)
{
    this->pricePerDay = price;
}

int Car::carCount = 0;

int Car::getCarCount()
{
    return carCount;
}

Car& Car::operator+=(double extraPrice)
{
    pricePerDay += extraPrice;
    return *this;
};

bool Car::operator!() const
{
    return pricePerDay <= 0;
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    out << car.brand << " "
        << car.model << " "
        << car.year << " "
        << car.pricePerDay;
    return out;
}

std::istream& operator>>(std::istream& in, Car& car)
{
    in >> car.brand >> car.model >> car.year >> car.pricePerDay;
    return in;
}