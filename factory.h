#ifndef FACTORY_H
#define FACTORY_H

#include "icalculator.h"

class StandardProduct : public ICalculator
{
public:
    double calculate(double price, int qty) override
    {
        return price*qty;
    }
};

class PremiumProduct : public ICalculator
{
public:
    double calculate(double price, int qty) override
    {
        return 1.5*price*qty;
    }
};

class CalculatorFactory
{
public:
    static ICalculator* createProduct(int type)
    {
        if (type == 0)
        {
            return new StandardProduct();
        }
        else
        {
            return new PremiumProduct();
        }
    }
};

#endif // FACTORY_H
