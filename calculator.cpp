#include "calculator.h"
#include "decorators.h"

Calculator::Calculator(QObject *parent) : QObject(parent)
{
}

void Calculator::calculateTotal(double price, int qty)
{
    ICalculator* calc = new BaseCalculator();

    calc = new TaxDecorator(calc);

    calc = new DiscountDecorator(calc);

    double total = calc->calculate(price, qty);

    emit calculationDone(total);

    delete calc;
}