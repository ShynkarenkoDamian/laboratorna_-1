#ifndef ELECTRIC_CAR
#define ELECTRIC_CAR
#include "Car.h"
class ElectricCar : public Car
{
private:
    double batteryCapacity;
    double rangePerCharge;

public:
    ElectricCar();
    ElectricCar(int Id, std::string brand, std::string model, int year, double price,
        double battery, double range);

    ElectricCar(const ElectricCar& other);
    ElectricCar(ElectricCar&& other) noexcept;
    ~ElectricCar();

    virtual void save(std::ofstream& file) const override;
    ElectricCar& operator=(const ElectricCar& other);

    void showInfo() const;
};

#endif