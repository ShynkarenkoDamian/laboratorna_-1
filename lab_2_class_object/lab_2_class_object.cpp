#include <iostream>
#include "Car.h"
#include "Client.h"
#include "Rental.h"

int main() {


    Client client1;
    Client client2("Damian", "AB123456");
    client1.showInfo();
    client2.showInfo();

    Rental rental1("Mersedes", "Damian", 5, 20);
    rental1.showInfo();

    Car car1("Toyota", "Camry", 2022, 80);

    Car car2 = car1;           // copy constructor
    Car car3 = std::move(car2); // move constructor

    car1 += 20; 

    std::cout << car1 << std::endl; 

    std::cin >> car1; 


    return 0;

}