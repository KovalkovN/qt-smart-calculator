#include "calculator.h"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
{}

void Calculator::calculateTotal(double price, int qty)
{
    double total = price * qty;
    emit calculationDone(total);
}