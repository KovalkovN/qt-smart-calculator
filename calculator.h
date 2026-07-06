#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Calculator(QObject *parent = nullptr);
    void calculateTotal(double price, int qty);

signals:
    void calculationDone(double result);
};

#endif // CALCULATOR_H
