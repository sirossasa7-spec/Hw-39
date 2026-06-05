#include "Request.h"

int Request::counter = 0;

Request::Request(const std::string& dest,
    const std::string& pass,
    const std::string& date)
    : destination(dest),
    passenger(pass),
    departureDate(date)
{
    id = ++counter;
}

bool RequestCompare::operator()(const Request& a,
    const Request& b) const
{
    if (a.destination != b.destination)
        return a.destination < b.destination;

    if (a.departureDate != b.departureDate)
        return a.departureDate < b.departureDate;

    return a.id < b.id;
}