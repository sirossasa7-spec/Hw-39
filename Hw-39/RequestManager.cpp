#include "RequestManager.h"

#include <iostream>

using namespace std;

static void printRequest(const Request& r)
{
    cout << "ID: " << r.id
        << " | Пункт призначення: " << r.destination
        << " | Пасажир: " << r.passenger
        << " | Дата вильоту: " << r.departureDate
        << endl;
}

void RequestManager::addRequest()
{
    string destination, passenger, date;

    cin.ignore();

    cout << "Введіть пункт призначення: ";
    getline(cin, destination);

    cout << "Введіть прізвище та ініціали пасажира: ";
    getline(cin, passenger);

    cout << "Введіть дату вильоту (YYYY-MM-DD): ";
    getline(cin, date);

    requests.insert(Request(destination, passenger, date));

    cout << "Заявку додано.\n";
}

void RequestManager::deleteRequest()
{
    int id;

    cout << "Введіть ID заявки: ";
    cin >> id;

    for (auto it = requests.begin(); it != requests.end(); ++it)
    {
        if (it->id == id)
        {
            requests.erase(it);
            cout << "Заявку видалено.\n";
            return;
        }
    }

    cout << "Заявку не знайдено.\n";
}

void RequestManager::showByDestination() const
{
    string destination;

    cin.ignore();

    cout << "Введіть пункт призначення: ";
    getline(cin, destination);

    bool found = false;

    for (const auto& r : requests)
    {
        if (r.destination == destination)
        {
            printRequest(r);
            found = true;
        }
    }

    if (!found)
        cout << "Заявок не знайдено.\n";
}

void RequestManager::countRequests() const
{
    string destination;
    string dateFrom;
    string dateTo;

    cin.ignore();

    cout << "Введіть пункт призначення: ";
    getline(cin, destination);

    cout << "Початкова дата (YYYY-MM-DD): ";
    getline(cin, dateFrom);

    cout << "Кінцева дата (YYYY-MM-DD): ";
    getline(cin, dateTo);

    int count = 0;

    for (const auto& r : requests)
    {
        if (r.destination == destination &&
            r.departureDate >= dateFrom &&
            r.departureDate <= dateTo)
        {
            count++;
        }
    }

    cout << "Кількість заявок: " << count << endl;
}

void RequestManager::showAll() const
{
    if (requests.empty())
    {
        cout << "Список порожній.\n";
        return;
    }

    for (const auto& r : requests)
        printRequest(r);
}