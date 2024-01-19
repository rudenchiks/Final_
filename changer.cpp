#include "changer.h"


Changer::Changer(uint _row, QAbstractItemModel *_model, QWidget *parent)
{
    row = _row;
    model = _model;

    uint count = model->data(model->index(row,3)).toUInt();
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QBoxLayout* layout = new QBoxLayout(QBoxLayout::Direction::LeftToRight, this);
    addButton = new QPushButton("добавить");
    label = new QLabel(QString::number(count));
    //removeButton = new QPushButton("-");

    //layout->addWidget(removeButton);
    layout->addWidget(label);
    layout->addWidget(addButton);

    QBoxLayout* layout2 = new QBoxLayout(QBoxLayout::Down, this);
    confirmButton = new QPushButton("сохранить");
    layout2->addWidget(confirmButton);

    mainLayout->addLayout(layout);
    mainLayout->addLayout(layout2);
    setLayout(mainLayout);

    //connect(removeButton, SIGNAL(clicked()), this, SLOT(on_pushRemoveButton_clicked()));
    connect(addButton, SIGNAL(clicked()), this, SLOT(on_pushAddButton_clicked()));
    connect(confirmButton, SIGNAL(clicked()), this, SLOT(on_pushConfirmButton_clicked()));
}

void Changer::on_pushAddButton_clicked()
{
    uint count = label->text().toUInt();
    uint maxCount = model->data(model->index(row, 1)).toUInt();
    count = (count == maxCount) ? maxCount : count+1;
    label->setText(QString::number(count));
}

//void Changer::on_pushRemoveButton_clicked()
//{
//    uint count = label->text().toUInt();
//    count = (count == 0) ? 0 : count-1;
//    label->setText(QString::number(count));
//}

void Changer::on_pushConfirmButton_clicked()
{
    uint count = label->text().toUInt();
    model->setData(model->index(row,3),count);
    this->close();//закрывыет диалоговое окно
}
