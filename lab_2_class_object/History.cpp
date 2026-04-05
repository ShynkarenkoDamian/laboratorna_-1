#include "History.h"
#include <fstream>

History::History(const std::string& action) : action(action) {
    time_t now = time(0);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
    timestamp = buffer;

    if (!timestamp.empty() && timestamp.back() == '\n')
        timestamp.pop_back();
}

std::string History::getAction() const {
    return action;
}

std::string History::getTimestamp() const {
    return timestamp;
}

void History::save(std::ofstream& file) const {
    file << timestamp << "|" << action << "\n";
}