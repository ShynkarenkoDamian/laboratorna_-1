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

    Vehicle& operator=(const Vehicle& other);

    virtual void showInfo() const;
    void showInfoStaticBinding() const;
};

#endif