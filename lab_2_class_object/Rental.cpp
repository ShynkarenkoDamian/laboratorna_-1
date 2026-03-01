#include "Rental.h"
#include <iostream>

Rental::Rental() : Rental(Car(), Client(), 1) {
    std::cout << "delegation rental constructor called\n";
}

Rental::Rental(Car c, Client cl, int d)
    : car(c), client(cl), days(d), totalCost(c.calculateCost(d)) {

    std::cout << "default rental constructor called\n";
}

Rental::~Rental() {
    std::cout << "Rental destroyed\n";
}

void Rental::showRentalInfo() const {
    std::cout << "Rental for " << days<< " day(s). Total cost: " << totalCost << "$\n";
}