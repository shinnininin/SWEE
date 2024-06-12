#include "Inventory.h"
#include <fstream>
#include <sstream>
#include <iostream>

Inventory::Inventory() {
        loadProducts();
    }

Inventory::~Inventory() {
    saveProducts();
}
void Inventory::addProduct(const string& name, double price, int stock, const string& limitedFlag) {
    products.emplace_back(name, price, stock, limitedFlag);
    saveProducts();
}


double Inventory::searchProductPrice(const string& search) {
    for (const auto& product : products) {
        if (product.getName() == search) {
            return product.getPrice();
        }
    }
    cout << "�ش��ϴ� ��ǰ�� ã�� ���߽��ϴ�." << endl;
    return 0;
}

double Inventory::searchProductStock(const string& search) {
    for (const auto& product : products) {
        if (product.getName() == search) {
            return product.getStock();
        }
    }
    cout << "�ش��ϴ� ��ǰ�� ã�� ���߽��ϴ�." << endl;
    return 0;
}
bool Inventory::updateStock(const string& product, int quantity) {
    for (auto& p : products) {
        if (p.getName() == product) {
            p.setStock(quantity);
            saveProducts();
            return true;
        }
    }

    return false;
}

bool Inventory::showProducts() const {
    if (products.empty()) {
        system("cls");
        cout << "**��ǰ�� �������� �ʽ��ϴ�**" << endl;
        return false;
    }
    else {
        for (const Product& product : products) {
            product.showProduct();
        }
        return true;
    }
}

void Inventory::showLimitedProducts() const {
    if (products.empty()) {
        cout << "��ǰ�� �������� �ʽ��ϴ�." << endl;
    }
    else {
        for (const Product& product : products) {
            if (product.getLimited() == "Y") {
                product.showProduct();
            }
        }
    }
}
void Inventory::saveProducts() {
    ofstream file(productFile);
    for (const Product& product : products) {
        file << product.getName() << "," << product.getPrice() << "," << product.getStock() << "," << product.getLimited() << endl;
    }
    file.close();
}
void Inventory::loadProducts() {
    ifstream file(productFile);
    products.clear();
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, priceStr, stockStr, limitedFlagStr;
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        getline(ss, stockStr, ',');
        getline(ss, limitedFlagStr, ',');
        double price = stod(priceStr);
        int stock = stoi(stockStr);
        string limitedFlag = limitedFlagStr;
        products.emplace_back(name, price, stock, limitedFlag);
    }
    file.close();
}