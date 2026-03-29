#ifndef VEHICLE_H
#define VEHICLE_H
#include <fstream>
#include <string>
#include "IDisplay.h"

class Vehicle: public IDisplay {
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

    std::string getBrand() const;
    std::string getModel() const;
    int getYear() const;
    void display() const override;
    virtual void showInfo() const;
    virtual void getPricePerDay() const =0;
    void showInfoStaticBinding() const;
    virtual void save(std::ofstream & file) const = 0;

    Vehicle& operator=(const Vehicle& other);
};

#endif