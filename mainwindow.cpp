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
    double p = ui->priceInput->value();
    int q = ui->qtyInput->value();
    int type = ui->productTypeCombo->currentIndex();
    bool tax = ui->taxCheck->isChecked();
    bool discount = ui->discountCheck->isChecked();

    calcModule->calculateTotal(p, q, type, tax, discount);
}

void MainWindow::displayResult(double total)
{
    ui->resultLabel->setText(QString("Итого: %1").arg(total));
}