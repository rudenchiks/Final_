#ifndef MARKETWINDOW_H
#define MARKETWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QHash>
#include <QStandardItemModel>
#include <QStringListModel>
#include "product.h"
#include "changer.h"
namespace Ui {
class MarketWindow;
}

class MarketWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MarketWindow(QWidget *parent = nullptr);
    ~MarketWindow();

    void setUserName(const QString& _userName);

private:
    void drawProduct();
    void readFile();
    void clearBacket();
    void clearColumnBacket();
    uint countBasket(int row);

public slots:
    void addProductInList(QModelIndex index);

private slots:
    void on_orderButton_clicked();
    void on_pushAbout_clicked();

private:
    QList<Product> products;
    QHash<Product, unsigned> backet;
    QString userName;
    Ui::MarketWindow *ui;
};

#endif // MARKETWINDOW_H
