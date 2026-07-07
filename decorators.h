#ifndef DECORATORS_H
#define DECORATORS_H

#include "icalculator.h"

class BaseCalculator : public ICalculator
{
public:
    double calculate(double price, int qty) override
    {
        return price * qty;
    }
};

class CalculatorDecorator : public ICalculator
{
protected:
    ICalculator* m_wrappee;

public:
    CalculatorDecorator(ICalculator* wrappee) : m_wrappee(wrappee) {}

    double calculate(double price, int qty) override
    {
        return m_wrappee->calculate(price, qty);
    }
};

class TaxDecorator : public CalculatorDecorator
{
public:
    TaxDecorator(ICalculator* wrappee) : CalculatorDecorator(wrappee) {}

    double calculate(double price, int qty) override
    {
        double result = CalculatorDecorator::calculate(price, qty);
        return result * 1.20;
    }
};

class DiscountDecorator : public CalculatorDecorator
{
public:
    DiscountDecorator(ICalculator* wrappee) : CalculatorDecorator(wrappee) {}

    double calculate(double price, int qty) override
    {
        double result = CalculatorDecorator::calculate(price, qty);
        return result * 0.90;
    }
};

#endif // DECORATORS_H