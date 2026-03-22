#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    std::string brand;
    std::string model;
    int year;

public:
    Vehicle();
    Vehicle(std::string brand, std::string model, int year);

    Vehicle(const Vehicle& other);
    Vehicle(Vehicle&& other) noexcept;

    virtual ~Vehicle();

    virtual void showInfo() const;
    virtual void getPricePerDay() const =0;
    void showInfoStaticBinding() const;

    Vehicle& operator=(const Vehicle& other);
};

#endif