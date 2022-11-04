#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Hello, World!");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    num_clicks_++;
//    QString message;
//    message = "Hello, World!" + std::to_string(num_clicks_);
    ui->statusbar->showMessage(("Hello, World! The button was pressed ") + QString::number(num_clicks_) + " time(s)!");
}
