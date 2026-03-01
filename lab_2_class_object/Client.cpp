#include "Client.h"
#include <iostream>

Client::Client() : Client("Unknown", "000000") {
    std::cout << "delegation client constructor called\n";
}

Client::Client(std::string n,std::string license,std::string p)
    : name(n), licenseNumber(license), phone(p) {
    std::cout << "client default constructor was called\n";
}
Client::~Client() {
    std::cout << "Client destroyed: " << name << std::endl;
}

void Client::showInfo() const {
    std::cout << "Client: "<< name<< ", License: "<< licenseNumber<< ", Phone: "<< phone << std::endl;
}