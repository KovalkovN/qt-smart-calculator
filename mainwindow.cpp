#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    calcModule = new Calculator(this);
    connect(calcModule, &Calculator::calculationDone, this, &MainWindow::displayResult);

    this->setStyleSheet(
        "QMainWindow "
        "QPushButton {"
        "   background-color: #4CAF50;"
        "   color: white;"
        "   font-size: 14px;"
        "   padding: 10px;"
        "}"
        "QPushButton:hover { background-color: #45a049; }"
        "QTextEdit {"
        "   background-color: #ffffff;"
        "   border: 1px solid #cccccc;"
        "   border-radius: 5px;"
        "   font-family: 'Courier New';"
        "   font-size: 13px;"
        " color: black; "
        "}"
        );
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
    ui->resultLabel->setText(QString("Итого: %1 руб.").arg(total));

    QString type = ui->productTypeCombo->currentText();
    double p = ui->priceInput->value();
    int q = ui->qtyInput->value();

    QString receipt = QString(" Товар: %1\n" " Цена: %2 x %3 шт.\n" " Налоги/Скидки учтены.\n"" К оплате: %4 руб.\n")
                          .arg(type).arg(p).arg(q).arg(total);

    ui->historyEdit->append(receipt);
}