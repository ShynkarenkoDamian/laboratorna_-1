#ifndef RENTAL_H
#define RENTAL_H
#include <string>
class Rental {
private:
    std::string carBrand;
    std::string clientName;
    int days;
    double pricePerDay;
    double totalCost;

public:
    Rental();
    Rental(std::string brand, std::string client, int d = 1, double price = 50.0);
    ~Rental();
    void showInfo() const;
};

#endif