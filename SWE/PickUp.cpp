#include "PickUp.h"
#include <fstream>
#include <iostream>
#include <sstream>

string PickUp::getId() const
{
    return id;
}
void PickUp::setId(string id)
{
    this->id = id;
}
void PickUp::displayPickupReservations() const
{
    ifstream file("pickup.txt");
    if (!file) {
        cout << "������ �� �� �����ϴ�.\n";
        return;
    }

    string line;
    cout << "���� ���� ���:\n";
    cout << "-------------------------\n";
    cout << "|   ��¥   | ��ǰ�� | ���� |\n";
    cout << "-------------------------\n";

    while (getline(file, line)) {
        stringstream ss(line);
        string date, productName, quantity, userId;
        getline(ss, date, ',');
        getline(ss, productName, ',');
        getline(ss, quantity, ',');
        getline(ss, userId, ',');
        if (userId == getId()) {
            cout << "| " << date << " | " << productName << " | " << quantity << " | \n";
        }
    }

    cout << "-------------------------\n";
    file.close();
}

void PickUp::reservePickUp(string date, string productName, int count, string id) {
    ofstream file(pickUpFile);
    file << date << "," << productName << "," << count << "," << id << endl;
    file.close();
}
