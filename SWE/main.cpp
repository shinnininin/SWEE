#include "Inventory.h"
#include "UserManager.h"
#include "Customer.h"
#include "Seller.h"
#include "Admin.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {

    Inventory inventory;
    UserManager userManager(inventory);

    while (true) {

        system("cls");
        cout << "============�ø�Pick============" << endl << endl;
        cout << "1. �α���  2. ȸ������  3. ����" << endl;
        cout << ">> ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            system("cls");
            cout << "===========�α���===========" << endl;

            string id, password;
            cout << "���̵�: ";
            cin >> id;
            cout << "��й�ȣ: ";
            cin >> password;

            User* user = userManager.findUser(id, password);
            if (user) {
                system("cls");
                user->handleMenu(inventory);
            }
            else {
                system("cls");
                cout << "�α��� ����\n";
            }
        }
        else if (choice == 2) {

            system("cls");
            cout << "===========ȸ������===========" << endl;

            string id, password, role;
            cout << "���̵�: ";
            cin >> id;

            //���̵� �ߺ� üũ
            if (userManager.isUserIdTaken(id)) {
                system("cls");
                cout << "�̹� �����ϴ� ���̵��Դϴ�.\n";
                continue;
            }

            cout << "��й�ȣ: ";
            cin >> password;
            cout << "���� (customer/admin/seller): ";
            cin >> role;

            if (role == "customer") {
                userManager.addUser(new Customer(id, password, inventory));
            }
            else if (role == "admin") {
                userManager.addUser(new Admin(id, password));
            }
            else if (role == "seller") {
                userManager.addUser(new Seller(id, password, inventory));
            }
        }
        else if (choice == 3) {
            break;
        }
    }

    return 0;
}
