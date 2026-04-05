#include "Rental.h"
#include <iostream>

Rental::Rental(std::shared_ptr<Vehicle> v, std::shared_ptr<Client> c, int days) 
    : vehicle(v), client(c), days(days) {}

Rental::~Rental() {
}

void Rental::showInfo() const {
    std::cout << "Rental Info:\n--------------------\n";
    client->showInfo();
    vehicle->showInfo();
	std::cout << "Days: " << days << "\n";
}

int Rental::rentalCount = 0;
int Rental::getRentalCount()
{
    return rentalCount;
}

void Rental::save(std::ofstream & file) const
{
    file << client->getLicense() << " " << vehicle->getId() << " " << days << std::endl;
}

