#ifndef RENTAL_H
#define RENTAL_H

#include "Car.h"
#include "Client.h"

class Rental {
private:
    Car car;
    Client client;
    int days;
    double totalCost;

public:
    Rental();
    Rental(Car c, Client cl, int d = 1);
    ~Rental();
    void showRentalInfo() const;
};

#endif