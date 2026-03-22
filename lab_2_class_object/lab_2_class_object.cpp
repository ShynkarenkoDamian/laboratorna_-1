#include <iostream>
#include "Car.h"
#include "Client.h"
#include "Rental.h"

int main() {

    Vehicle* v = new Car("Mersedes", "benz", 2007, 20.0);
        v->showInfoStaticBinding();

    Vehicle* c = new Car("Mersedes", "benz", 2007, 20.0);
        c->showInfo();


    delete v;
    delete c;
    return 0;

}