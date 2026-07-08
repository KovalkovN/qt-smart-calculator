#include "calculator.h"
#include "decorators.h"
#include "factory.h"

Calculator::Calculator(QObject *parent) : QObject(parent) {}

void Calculator::calculateTotal(double price, int qty, int productType, bool hasTax, bool hasDiscount)
{
    // 1. ПАТТЕРН ФАБРИКА
    ICalculator* calc = CalculatorFactory::createProduct(productType);

    // 2. ПАТТЕРН ДЕКОРАТОР
    if (hasTax)
    {
        calc = new TaxDecorator(calc);
    }

    if (hasDiscount)
    {
        calc = new DiscountDecorator(calc);
    }

    // 3. расчет
    double total = calc->calculate(price, qty);

    // 4. ПАТТЕРН НАБЛЮДАТЕЛЬ
    emit calculationDone(total);

    delete calc;
}