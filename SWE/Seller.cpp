#include "Seller.h"
#include "OrderManager.h"
#include <iostream>
#include <thread>

using namespace std;

Seller::Seller(string id, string password, Inventory& inv)
    : User(id, password), inventory(inv) {}

void Seller::showMenu() const
{
    cout << "===========Seller===========" << endl;
    cout << "1. ��ǰ���\n";
    cout << "2. ��۰���\n";
    cout << "3. ��Ű���\n";
    cout << "4. �α׾ƿ�\n";
}

void Seller::handleMenu(Inventory& inventory)
{
    while (true) {
        showMenu();

        int choice;
        cout << ">> ";
        cin >> choice;

        if (choice == 1) {
            string name;
            double price;
            int stock;
            string limitedFlag;

            system("cls");
            cout << "===========��ǰ���===========" << endl;
            cout << "��ǰ��: ";
            cin >> name;
            cout << "����: ";
            cin >> price;
            cout << "���: ";
            cin >> stock;
            cout << "������ ���� (Y/N): ";
            cin >> limitedFlag;
            inventory.addProduct(name, price, stock, limitedFlag);
        }
        else if (choice == 2) {
            system("cls");
            cout << "===========��۰���===========" << endl;
            manageDeliveries();
        }
        else if (choice == 3) {
            system("cls");
            cout << "===========��Ű���===========" << endl;
            inventory.showLimitedProducts();
        }
        else if (choice == 4) {
            break;
        }
    }
}

void Seller::manageDeliveries() {
    OrderManager orderManager;
    orderManager.loadOrders();
    orderManager.showPendingOrders();

    string orderId;
    cout << "��� ���¸� '�����'���� ������ �ֹ���ȣ�� �Է��ϼ���: ";
    cin >> orderId;
    orderManager.updateOrderStatus(orderId, "�����");


    for (int second = 1; second <= 5; second++) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << second << endl;
    }
    orderManager.updateOrderStatus(orderId, "��ۿϷ�");
}

Inventory& Seller::getInventory()
{
    return inventory; 
}