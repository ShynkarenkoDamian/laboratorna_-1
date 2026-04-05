#ifndef CAR_H
#define CAR_H

#include <string>
#include "Vehicle.h"

class Car: public Vehicle {
private:
    static int carCount;
protected:
    double pricePerDay;
public:
    Car();
    Car(int Id, std::string brand, std::string model, int year, double price);

    Car(const Car& other);
    Car(Car&& other) noexcept;

    virtual ~Car();

    double calculateCost(int days) const;
    void showInfo() const override;
    void showInfoStaticBinding() const;
    void getPricePerDay() const override;
    virtual void save(std::ofstream& file) const override;

    static int getCarCount();

    Car& operator=(const Car& other);
    Car& operator+=(double extraPrice);
    bool operator!() const;
    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    friend std::istream& operator>>(std::istream& in, Car& car);
};

#endif

