#ifndef CHANGER_H
#define CHANGER_H
#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QAbstractItemModel>
#include <QLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>

class Changer : public QDialog
{
    Q_OBJECT
public:
    Changer(uint _row, QAbstractItemModel* _model,  QWidget *parent = nullptr);

private slots:
    void on_pushAddButton_clicked();
//    void on_pushRemoveButton_clicked();
    void on_pushConfirmButton_clicked();

private:
    uint row;
    QAbstractItemModel* model;
    QPushButton* addButton;
    //QPushButton* removeButton;
    QPushButton* confirmButton;
    QLabel* label;
};

#endif // CHANGER_H
