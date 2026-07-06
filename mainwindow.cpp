#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    calcModule = new Calculator(this);
    connect(calcModule, &Calculator::calculationDone, this, &MainWindow::displayResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calcButton_clicked()
{
    double price = ui->priceInput->value();
    int qty = ui->qtyInput->value();

    calcModule->calculateTotal(price, qty);
}

void MainWindow::displayResult(double total)
{
    ui->resultLabel->setText(QString("Итого: %1").arg(total));
}