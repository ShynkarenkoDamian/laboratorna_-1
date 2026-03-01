#include <iostream>
#include "Car.h"
#include "Client.h"
#include "Rental.h"

int main() {
    Car car1("Toyota", "Camry", 2022, 80);
    car1.showInfo();
    Car car2;
    car2.showInfo();
    Car car3("Mersedes", "Benz");
    car3.showInfo();

    Client client1;
    Client client2("Damian", "AB123456");
    client1.showInfo();
    client2.showInfo();

    Rental rental1(car1, client2, 5);
    rental1.showRentalInfo();
    return 0;

}