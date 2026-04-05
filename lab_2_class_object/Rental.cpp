#include "Rental.h"
#include <iostream>

Rental::Rental(Car& car, Client& client, int days)
    : car(car), client(client), days(days)
{
    totalCost = car.calculateCost(days);
}

Rental::~Rental() {
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

bool Rental::operator==(Rental& rental) const
{
    return (this->client.getName() == rental.client.getName());
}

std::ostream& operator<<(std::ostream& out, const Rental& rental)
{
    out << rental.car << rental.client << rental.days;
    return out;
}

std::istream& operator>>(std::istream& in, Rental& rental)
{
    in >> rental.car >> rental.client >> rental.days;
    return in;
}


