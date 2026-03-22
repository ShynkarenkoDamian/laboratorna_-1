#include <iostream>
#include "Car.h"
#include "Client.h"
#include "Rental.h"
#include "ElectricCar.h"
#include "VIPClient.h"

void printInfo(const Vehicle& v)
{
    v.showInfo();
}


int main() {

    Vehicle* v = new Car("Mersedes", "benz", 2007, 20.0);
        v->showInfoStaticBinding();

    Vehicle* c = new Car("Mersedes", "benz", 2007, 20.0);
        c->showInfo();

    Vehicle* electroCar = new ElectricCar("Hyndai", "someModel", 2020, 13.2, 8000, 100);
        electroCar->getPricePerDay();

    Client* VipClient = new VIPClient("Pavlo", "AP10120023", "+3806798842", 9, 18.3);
        VipClient->showInfo();

        Car car;
        Vehicle& ref_car = car;
        ref_car.showInfo();

        printInfo(ref_car);

    delete VipClient;
    delete electroCar;
    delete v;
    delete c;
    return 0;

}