#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    int year;
    double pricePerDay;

public:
    Car();
    Car(std::string b, std::string m, int y, double price);
    ~Car();
    double calculateCost(int days) const;
    void showInfo() const;
};

#endif

