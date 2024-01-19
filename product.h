#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>
#include <tuple>
#include <QHash>
class Product
{
public:
    Product();
    Product(QString _name, uint _count, uint _price);
    Product(QString _name, uint _price);

    void setName(QString& _name);
    QString getName() const;

    void setCount(uint _count);
    unsigned getCount() const;

    void setPrice(uint _price);
    unsigned getPrice() const;

private:
    QString name;
    uint count=0;
    uint price;
};

inline bool operator ==(const Product &p1, const Product& p2)
{
    return p1.getName() == p2.getName() && p1.getCount() == p2.getCount() && p1.getPrice() == p2.getPrice();
}

inline uint qHash(const Product& key, uint seed = 0){
    uint hash = qHash(key.getName(), seed);
    hash = qHash(key.getCount(), hash);
    hash = qHash(key.getPrice(), hash);
    return hash;
}

#endif // PRODUCT_H
