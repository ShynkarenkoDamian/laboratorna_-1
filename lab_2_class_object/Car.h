#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    int year;
    double pricePerDay;
    static int carCount;
public:
    Car();
    Car(std::string b, std::string m, int y=2000, double price=50.0);
    Car(const Car& other);
    Car(Car&& other) noexcept;
    ~Car();
    double calculateCost(int days) const;
    void showInfo() const;
    void setPrice(double price);
    static int getCarCount();
};

#endif

