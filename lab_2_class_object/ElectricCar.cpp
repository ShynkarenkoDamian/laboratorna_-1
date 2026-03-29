#include "ElectricCar.h"
#include <iostream>

ElectricCar::ElectricCar()
    : Car(), batteryCapacity(0), rangePerCharge(0) {}

ElectricCar::ElectricCar(std::string brand, std::string model, int year, double price,
    double battery, double range)
    : Car(brand, model, year, price),
    batteryCapacity(battery), rangePerCharge(range) {}

ElectricCar::ElectricCar(const ElectricCar& other)
    : Car(other), batteryCapacity(other.batteryCapacity), rangePerCharge(other.rangePerCharge) {}

ElectricCar::ElectricCar(ElectricCar&& other) noexcept
    : Car(std::move(other)), batteryCapacity(other.batteryCapacity), rangePerCharge(other.rangePerCharge)
{
    other.batteryCapacity = 0;
    other.rangePerCharge = 0;
}

ElectricCar::~ElectricCar() {}

void ElectricCar::save(std::ofstream& file) const{
        file << "ElectricCar " << brand << " "<< model << " " << year << " " << pricePerDay << " " << batteryCapacity << " "<< rangePerCharge<< std::endl;
}

ElectricCar& ElectricCar::operator=(const ElectricCar& other)
{
    if (this != &other)
    {
        Car::operator=(other);
        batteryCapacity = other.batteryCapacity;
        rangePerCharge = other.rangePerCharge;
    }

    return *this;
}

void ElectricCar::showInfo() const
{
    Car::showInfo();
    std::cout << "Battery: " << batteryCapacity << " kWh, Range: "
        << rangePerCharge << " km\n";
}