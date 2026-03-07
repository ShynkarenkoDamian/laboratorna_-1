#include "Rental.h"
#include <iostream>

Rental::Rental(Car& car, Client& client, int days)
    : car(car), client(client), days(days)
{
    totalCost = car.calculateCost(days);
    std::cout << "Rental created\n";
}

Rental::~Rental() {
    std::cout << "Rental destroyed\n";
}

void Rental::showInfo() const {
    std::cout << "\n--- Rental info ---\n";

    car.showInfo();
    client.showInfo();

    std::cout << "Days: " << this->days << std::endl;
    std::cout << "Total cost: " << this->totalCost << "$\n";
}
int Rental::rentalCount = 0;
int Rental::getRentalCount()
{
    return rentalCount;
}
