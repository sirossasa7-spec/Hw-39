#pragma once
#include <string>

class Request {
private:
    static int counter;

public:
    int id;
    std::string destination;
    std::string passenger;
    std::string departureDate;

    Request(const std::string& dest,
        const std::string& pass,
        const std::string& date);
};

struct RequestCompare {
    bool operator()(const Request& a, const Request& b) const;
};
