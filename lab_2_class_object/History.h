#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include <ctime>

class History {
private:
    std::string action;
    std::string timestamp;

public:
    History(const std::string& action);

    std::string getAction() const;
    std::string getTimestamp() const;

    void save(std::ofstream& file) const;
};

#endif