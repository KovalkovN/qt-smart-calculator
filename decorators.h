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

class Decorator : public ICalculator
{
protected:
    ICalculator* insideObject;

public:
    Decorator(ICalculator* obj)
    {
        insideObject = obj;
    }
};

class TaxDecorator : public Decorator
{
public:
    TaxDecorator(ICalculator* obj) : Decorator(obj) {}

    double calculate(double price, int qty) override
    {
        double baseResult = insideObject->calculate(price, qty);
        return baseResult * 1.20;
    }
};

class DiscountDecorator : public Decorator
{
public:
    DiscountDecorator(ICalculator* obj) : Decorator(obj) {}

    double calculate(double price, int qty) override
    {
        double baseResult = insideObject->calculate(price, qty);
        return baseResult * 0.90;
    }
};

#endif // DECORATORS_H