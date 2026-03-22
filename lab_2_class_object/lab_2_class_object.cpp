#include <iostream>
#include "Car.h"
#include "Client.h"
#include "Rental.h"

int main() {

    Vehicle* v = new Car(); // вказівник на базу, об'єкт Car

    v->showInfo(); // ❗ СТАТИЧНА ПРИВ’ЯЗКА

    return 0;

}