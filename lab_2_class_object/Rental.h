#ifndef RENTAL_H
#define RENTAL_H
#include <string>
#include "Car.h"
#include "Client.h"

class Rental {
private:
    std::shared_ptr<Client>& client;
    std::shared_ptr<Vehicle>& vehicle;
    int days;
    static int rentalCount;

public:
    Rental(std::shared_ptr<Vehicle> v,std::shared_ptr<Client> c,int days);
    ~Rental();
    void showInfo() const;
    static int getRentalCount();
    void save(std::ofstream& file) const;
};

#endif