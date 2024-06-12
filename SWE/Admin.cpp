#include "Admin.h"
#include <iostream>

Admin::Admin(string id, string password) : User(id, password) {}

void Admin::showMenu() const
{
    cout << "1. �������\n";
    cout << "2. �α׾ƿ�\n";
}
void Admin::handleMenu(Inventory& inventory)
{
    while (true) {
        showMenu();
        int choice;
        cin >> choice;
        if (choice == 1) {
            // Add review deletion functionality here
        }
        else if (choice == 2) {
            break;
        }
    }
}
