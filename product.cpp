#include "product.h"

Product::Product(){}

Product::Product(QString _name, uint _count, uint _price) : name(_name), count(_count), price(_price){}

Product::Product(QString _name, uint _price) : name(_name), price(_price){}

void Product::setName(QString &_name)
{
    name = _name;
}

QString Product::getName() const
{
    return name;
}

void Product::setCount(uint _count)
{
    count = _count;
}

uint Product::getCount() const
{
    return count;
}

void Product::setPrice(uint _price)
{
    price = _price;
}

uint Product::getPrice() const
{
    return price;
}


