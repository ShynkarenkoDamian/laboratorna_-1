#include "Car.h"
#include <iostream>

Car::Car() : Vehicle(999, "Unknown", "Unknown", 0), pricePerDay(0) {}

Car::Car(int Id, std::string brand, std::string model, int year, double price)
    : Vehicle(Id, brand, model, year), pricePerDay(price) 
{carCount++;}

Car::Car(const Car& other)
    : Vehicle(other),           
    pricePerDay(other.pricePerDay)
{carCount++;}

Car::Car(Car&& other) noexcept
    : Vehicle(std::move(other)),
    pricePerDay(other.pricePerDay)
{
    other.pricePerDay = 0;
}

Car::~Car()
{carCount--;}


double Car::calculateCost(int days) const {
    return pricePerDay * days;
}


void Car::showInfo() const
{
    Vehicle::showInfo();
    std::cout << " Price per day: " << pricePerDay << "$\n";
}
void Car::showInfoStaticBinding() const 
{
    std::cout << "Derived class function\n";
}

void Car::getPricePerDay() const
{
    std::cout << "Price per day = " << this->pricePerDay << "$\n" << std::endl;
}

void Car::save(std::ofstream& file) const
{
    file << "Car " << Id << " " << brand << " " << model << " " << year << " " << pricePerDay << std::endl;
}

int Car::carCount = 0;
int Car::getCarCount()
{
    return carCount;
}

Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        Vehicle::operator=(other);
        pricePerDay = other.pricePerDay;
    }

    return *this;
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