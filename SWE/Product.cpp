// Product Class
#include "Product.h"
#include <iostream>

Product::Product(string _name, double _price, int _stock, string _limitedFlag)
    : name(_name), price(_price), stock(_stock), limitedFlag(_limitedFlag) {}

string Product::getName() const 
{
    return name;
}
double Product::getPrice() const 
{
    return price;
}
int Product::getStock() const 
{
    return stock; 
}
string Product::getLimited() const 
{
    return limitedFlag; 
}

void Product::setStock(int newStock) 
{ 
    stock = newStock; 
}

void Product::showProduct() const {
    cout << "��ǰ��: " << name << ", ����: " << price << ", ���: " << stock << ", ������: " << (limitedFlag == "Y" ? "Yes" : "No") << endl;
}
