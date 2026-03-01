#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    std::string name;
    std::string licenseNumber;
    std::string phone;

public:
    Client();
    Client(std::string n,std::string license,std::string p = "Not provided");
    ~Client();
    void showInfo() const;
};

#endif