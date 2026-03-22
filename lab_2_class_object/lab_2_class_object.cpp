#include <iostream>
#include "Car.h"
#include "Client.h"
#include "Rental.h"
#include "ElectricCar.h"

int main() {

    Vehicle* v = new Car("Mersedes", "benz", 2007, 20.0);
        v->showInfoStaticBinding();

    Vehicle* c = new Car("Mersedes", "benz", 2007, 20.0);
        c->showInfo();

    Vehicle* electroCar = new ElectricCar("Hyndai", "someModel", 2020, 13.2, 8000, 100);
        electroCar->getPricePerDay();

    delete electroCar;
    delete v;
    delete c;
    return 0;

}