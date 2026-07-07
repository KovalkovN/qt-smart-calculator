#ifndef ICALCULATOR_H
#define ICALCULATOR_H

class ICalculator
{
public:
    virtual ~ICalculator() = default;
    virtual double calculate(double price, int qty) = 0;
};

#endif // ICALCULATOR_H
