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
    cout << "1. 상품보기\n";
    cout << "2. 장바구니\n";
    cout << "3. 구매내역\n";
    cout << "4. 픽업예약\n";
    cout << "5. 리뷰관리\n";
    cout << "6. 경매참여\n";
    cout << "7. 로그아웃\n";
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

            cout << "1. 픽업조회 2. 픽업예약\n";
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

                cout << "상품명을 입력하세요" << endl;
                cin >> productName;
                cout << "수량을 입력하세요" << endl;
                cin >> count;
                cout << "픽업날짜를 입력하세요" << endl;
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
    cout << "상품명을 입력하세요: ";
    cin >> productName;
    double price = inventory.searchProductPrice(productName);
    if (price != 0) {
        cout << "수량을 입력하세요: ";
        cin >> quantity;
        double totalPrice = price * quantity;
        cout << "총 가격: " << totalPrice << endl;
        cout << "1. 장바구니에 추가\n";
        cout << "2. 바로 결제\n";
        int option;
        cin >> option;
        if (option == 1) {
            cart.addItem(CartItem(productName, quantity, totalPrice));
            cout << "장바구니에 상품이 추가되었습니다." << endl;
        }
        else if (option == 2) {
            cart.addItem(CartItem(productName, quantity, totalPrice));
            bool success = cart.checkout(id);

            if (success) {
                cout << "결제가 완료되었습니다." << endl;
            }
            else {
                cout << "결제에 실패했습니다." << endl;
            }
        }
    }
}

void Customer::manageReviews() {
    while (true) {
        cout << "1. 리뷰 작성\n";
        cout << "2. 리뷰 보기\n";
        cout << "3. 돌아가기\n";
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
    cout << "영수증 번호를 입력하세요: ";
    cin >> orderId;
    cout << "상품명을 입력하세요: ";
    cin >> product;
    cout << "별점을 입력하세요 (1-5): ";
    cin >> score;
    cout << "내용을 입력하세요: ";
    cin.ignore();
    getline(cin, content);

    reviewManager.addReview(orderId, product, score, content);
    cout << "리뷰가 작성되었습니다." << endl;
}