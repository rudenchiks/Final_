#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    marketWindow = new MarketWindow();
    QWidget::setFixedSize(window()->width() , window()->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        return;
    }
    QString userName = ui->lineEdit->text();
    marketWindow->setUserName(userName);
    marketWindow->show();
    this->close();
}

