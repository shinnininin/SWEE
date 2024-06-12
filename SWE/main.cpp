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
        cout << "============올림Pick============" << endl << endl;
        cout << "1. 로그인  2. 회원가입  3. 종료" << endl;
        cout << ">> ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            system("cls");
            cout << "===========로그인===========" << endl;

            string id, password;
            cout << "아이디: ";
            cin >> id;
            cout << "비밀번호: ";
            cin >> password;

            User* user = userManager.findUser(id, password);
            if (user) {
                system("cls");
                user->handleMenu(inventory);
            }
            else {
                system("cls");
                cout << "로그인 실패\n";
            }
        }
        else if (choice == 2) {

            system("cls");
            cout << "===========회원가입===========" << endl;

            string id, password, role;
            cout << "아이디: ";
            cin >> id;

            //아이디 중복 체크
            if (userManager.isUserIdTaken(id)) {
                system("cls");
                cout << "이미 존재하는 아이디입니다.\n";
                continue;
            }

            cout << "비밀번호: ";
            cin >> password;
            cout << "역할 (customer/admin/seller): ";
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
