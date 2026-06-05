#pragma once
#include <set>
#include "Request.h"

class RequestManager {
private:
    std::set<Request, RequestCompare> requests;

public:
    void addRequest();
    void deleteRequest();
    void showByDestination() const;
    void countRequests() const;
    void showAll() const;
};