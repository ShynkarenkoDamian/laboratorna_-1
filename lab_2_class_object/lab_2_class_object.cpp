#include <iostream>
#include "Car.h"
#include "Client.h"
#include "Rental.h"

int main() {


    Client client1;
    Client client2("Damian", "AB123456");
    client1.showInfo();
    client2.showInfo();
    Car car1("Toyota", "Camry", 2022, 80);

    Rental rental1(car1, client1, 5);
    rental1.showInfo();

    Car car2 = car1;           
    Car car3 = std::move(car2); 

    car1 += 20; 

    std::cout << car1 << std::endl; 

    std::cin >> car1; 


    return 0;

}