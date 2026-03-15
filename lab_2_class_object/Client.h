#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
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
    std::string getName();
    void showInfo() const;
    static int getClientCount();
    Client& operator=(const Client& other);
    friend std::ostream& operator<<(std::ostream& out, const Client& other);
    friend std::istream& operator>>(std::istream& in, Client& other);
};

#endif