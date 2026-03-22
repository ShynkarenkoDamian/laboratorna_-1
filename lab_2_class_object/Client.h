#ifndef CLIENT_H
#define CLIENT_H

#include "IDisplay.h"
#include <string>

class Client: public IDisplay {
private:
    static int clientCount;
protected:
    std::string name;
    std::string licenseNumber;
    std::string phone;
public:
    Client();
    Client(std::string name,std::string license,std::string phone);
    Client(const Client& other);
    Client(Client&& other) noexcept;
    virtual ~Client();

    void display() const override;
    std::string getName();
    virtual void showInfo() const;

    static int getClientCount();

    Client& operator=(const Client& other);
    friend std::ostream& operator<<(std::ostream& out, const Client& other);
    friend std::istream& operator>>(std::istream& in, Client& other);
};

#endif