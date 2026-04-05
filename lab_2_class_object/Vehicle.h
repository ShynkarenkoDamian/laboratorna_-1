#ifndef VEHICLE_H
#define VEHICLE_H
#include <fstream>
#include <string>
#include "IDisplay.h"

class Vehicle: public IDisplay {
protected:
    int Id;
    std::string brand;
    std::string model;
    int year;

public:
    Vehicle();
    Vehicle(int Id, std::string brand, std::string model, int year);

    Vehicle(const Vehicle& other);
    Vehicle(Vehicle&& other) noexcept;

    virtual ~Vehicle();

    std::string getBrand() const;
    std::string getModel() const;
    int getId() const { return Id; }
    int getYear() const;
    void display() const override;
    virtual void showInfo() const;
    virtual void getPricePerDay() const =0;
    virtual void save(std::ofstream & file) const = 0;

    Vehicle& operator=(const Vehicle& other);
};

#endif