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
    static int rentalCount;

public:
    Rental(Car& car, Client& client, int days);
    ~Rental();
    void showInfo() const;
    static int getRentalCount();
    bool operator==(Rental& rental) const;
    friend std::ostream& operator<<(std::ostream& out, const Rental& rental);
    friend std::istream& operator>>(std::istream& in, Rental& rental);
};

#endif