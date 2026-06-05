#include <iostream>
#include "RequestManager.h"

using namespace std;

int main()
{
    RequestManager manager;
    int choice;

    do
    {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Додати заявку\n";
        cout << "2. Видалити заявку\n";
        cout << "3. Вивести заявки за пунктом призначення\n";
        cout << "4. Порахувати заявки\n";
        cout << "5. Вивести всі заявки\n";
        cout << "0. Вихід\n";

        cin >> choice;

        switch (choice)
        {
        case 1: manager.addRequest(); break;
        case 2: manager.deleteRequest(); break;
        case 3: manager.showByDestination(); break;
        case 4: manager.countRequests(); break;
        case 5: manager.showAll(); break;
        }
    } while (choice != 0);

    return 0;
}