#include "CartItem.h"
#include <iostream>

CartItem::CartItem(string product, int count, double price)
    : product(product), count(count), price(price) {}

string CartItem::getProduct() const
{
    return product;
}
int CartItem::getCount() const
{
    return count;
}
double CartItem::getPrice() const
{
    return price;
}
void CartItem::showItem() const
{
    cout << "��ǰ: " << product << ", ����: " << count << ", ����: " << price << endl;
}