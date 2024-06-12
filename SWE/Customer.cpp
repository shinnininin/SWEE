#include "Customer.h"
#include "PickUp.h"
#include <string>
#include <iostream>
using namespace std;

Customer::Customer(string id, string password, Inventory& inv)
    : User(id, password), cart(inv) {}

void Customer::showMenu() const
{
    cout << "===========Customer===========" << endl;
    cout << "1. ��ǰ����\n";
    cout << "2. ��ٱ���\n";
    cout << "3. ���ų���\n";
    cout << "4. �Ⱦ�����\n";
    cout << "5. �������\n";
    cout << "6. �������\n";
    cout << "7. �α׾ƿ�\n";
}

void Customer::handleMenu(Inventory& inventory)
{
    while (true)
    {

        showMenu();
        int choice;
        cout << ">> ";
        cin >> choice;
        if (choice == 1) {
            if(inventory.showProducts())
                addToCart(inventory);
        }
        else if (choice == 2) {
            cart.showCart();
        }
        else if (choice == 3) {
            OrderManager orderManager;
            orderManager.loadOrders();
            showOrders();
        }
        else if (choice == 4) {//pickup
            PickUp p;

            cout << "1. �Ⱦ���ȸ 2. �Ⱦ�����\n";
            int number;
            cin >> number;

            if (number == 1) {
                p.setId(id);
                p.displayPickupReservations();
            }
            else if (number == 2) {

                string date, productName;
                int count;

                inventory.showProducts();

                cout << "��ǰ���� �Է��ϼ���" << endl;
                cin >> productName;
                cout << "������ �Է��ϼ���" << endl;
                cin >> count;
                cout << "�Ⱦ���¥�� �Է��ϼ���" << endl;
                cin >> date;
                p.reservePickUp(date, productName, count, id);
            }
        }
        else if (choice == 5) {

            manageReviews();
        }
        else if (choice == 6) {
            // Add ticket registration functionality here
        }
        else if (choice == 7) {
            system("cls");
            break;
        }
        else if (choice == 8) {
            break;
        }
    }
}

ShoppingCart& Customer::getCart()
{
    return cart; 
}

void Customer::showOrders() const {
    orderManager.showOrders(id);
}

void Customer::addToCart(Inventory& inventory) {
    string productName;
    int quantity;
    cout << "��ǰ���� �Է��ϼ���: ";
    cin >> productName;
    double price = inventory.searchProductPrice(productName);
    if (price != 0) {
        cout << "������ �Է��ϼ���: ";
        cin >> quantity;
        double totalPrice = price * quantity;
        cout << "�� ����: " << totalPrice << endl;
        cout << "1. ��ٱ��Ͽ� �߰�\n";
        cout << "2. �ٷ� ����\n";
        int option;
        cin >> option;
        if (option == 1) {
            cart.addItem(CartItem(productName, quantity, totalPrice));
            cout << "��ٱ��Ͽ� ��ǰ�� �߰��Ǿ����ϴ�." << endl;
        }
        else if (option == 2) {
            cart.addItem(CartItem(productName, quantity, totalPrice));
            bool success = cart.checkout(id);

            if (success) {
                cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
            }
            else {
                cout << "������ �����߽��ϴ�." << endl;
            }
        }
    }
}

void Customer::manageReviews() {
    while (true) {
        cout << "1. ���� �ۼ�\n";
        cout << "2. ���� ����\n";
        cout << "3. ���ư���\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            writeReview();
        }
        else if (choice == 2) {
            reviewManager.showReviews();
        }
        else if (choice == 3) {
            break;
        }
    }
}

void Customer::writeReview() {
    string orderId, product, content;
    int score;
    cout << "������ ��ȣ�� �Է��ϼ���: ";
    cin >> orderId;
    cout << "��ǰ���� �Է��ϼ���: ";
    cin >> product;
    cout << "������ �Է��ϼ��� (1-5): ";
    cin >> score;
    cout << "������ �Է��ϼ���: ";
    cin.ignore();
    getline(cin, content);

    reviewManager.addReview(orderId, product, score, content);
    cout << "���䰡 �ۼ��Ǿ����ϴ�." << endl;
}