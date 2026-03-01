#include "Rental.h"
#include <iostream>

Rental::Rental()
    : Rental("Unknown", "Unknown", 1, 50.0) {
    std::cout << "delegation rental constructor called\n";
}
Rental::Rental(std::string brand, std::string client, int d, double price)
    : carBrand(brand), clientName(client), days(d), pricePerDay(price), totalCost(price* d) {
    std::cout << "Rental default constructor was called\n";
}

Rental::~Rental() {
    std::cout << "Rental destroyed\n";
}

void Rental::showInfo() const {
    std::cout << "Car: " << carBrand<<
        "\nClient: " << clientName<< 
        "\nDays: " << days<< 
        "\nTotal cost: " << totalCost<< "$\n";
}