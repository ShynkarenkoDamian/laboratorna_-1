#ifndef RENTAL_H
#define RENTAL_H
#include <string>
#include "Car.h"
#include "Client.h"

class Rental {
private:
    Client& client;
    Car& car;
    int days;
    double totalCost;

public:
    Rental(Car& car, Client& client, int days);
    ~Rental();
    void showInfo() const;
};

#endif