#include <iostream>
#include "Car.h"

int main() {
    Car car1("Toyota", "Camry", 2022, 80);
    car1.showInfo();
    Car car2;
    car2.showInfo();
    Car car3("Mersedes", "Benz", 1999);
    car3.showInfo();
    return 0;
}