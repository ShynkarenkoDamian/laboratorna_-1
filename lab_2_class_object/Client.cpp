#include "Client.h"
#include <iostream>
#include <fstream>

Client::Client() :name("unknown"), phone("unknown"), licenseNumber("unknown") {}

Client::Client(std::string name,std::string license,std::string phone)
    : name(name), licenseNumber(license), phone(phone) 
{clientCount++;}

Client::Client(const Client& other)
    :name(other.name), licenseNumber(other.licenseNumber), phone(other.phone)
{clientCount++;}

Client::Client(Client&& other) noexcept
    :name(other.name), licenseNumber(other.licenseNumber), phone(other.phone)
{
    other.name = "";
    other.licenseNumber = "";
    other.phone = "";
}

Client::~Client() {
    std::cout << "Client destroyed: " << name << std::endl;
    clientCount--;
}

void Client::display() const
{
   std::cout << "Client: " << this->name << ", License: " << this->licenseNumber << ", Phone: " << this->phone << std::endl;
}

std::string Client::getName()
{
    return std::string(this->name);
}

std::string Client::getLicense() const
{
    return this->licenseNumber;
}

void Client::showInfo() const {
    std::cout << "Client: "<< this->name<< ", License: "<< this->licenseNumber<< ", Phone: "<< this->phone << std::endl;
}

void Client::save(std::ofstream & file) const {
    file << name << " " << licenseNumber << " " << phone << std::endl;
}

int Client::clientCount = 0;
int Client::getClientCount()
{
    return clientCount;
}

Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        name = other.name;
        licenseNumber = other.licenseNumber;
        phone = other.phone;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Client& other)
{
    out << other.name << " "
        << other.licenseNumber << " "
        << other.phone;
    return out;
}

std::istream& operator>>(std::istream& in, Client& other)
{
    in >> other.name >> other.licenseNumber >> other.phone;
    return in;
}