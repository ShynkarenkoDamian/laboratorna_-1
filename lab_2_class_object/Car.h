#ifndef CAR_H
#define CAR_H

#include <string>
#include "Vehicle.h"

class Car: public Vehicle {
private:
    double pricePerDay;
    static int carCount;
public:
    Car();
    Car(std::string brand, std::string model, int year, double price);
    Car(const Car& other);
    Car(Car&& other) noexcept;
    ~Car();
    double calculateCost(int days) const;
    void showInfo() const;
    static int getCarCount();
    Car& operator+=(double extraPrice);
    bool operator!() const;
    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    friend std::istream& operator>>(std::istream& in, Car& car);
};

#endif

