#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include <QDebug>
#include "decorators.h"
#include "factory.h"

class MockCalculator : public ICalculator
{
public:
    double calculate(double price, int qty) override
    {
        Q_UNUSED(price);
        Q_UNUSED(qty);
        return 100.0;
    }
};

class CalculatorTests : public QObject
{
    Q_OBJECT

private slots:

    void testPremiumProductLogic()
    {
        ICalculator* premium = CalculatorFactory::createProduct(1);

        QCOMPARE(premium->calculate(10, 2), 30.0);

        delete premium;
    }

    void testTaxDecoratorWithMock()
    {
        ICalculator* mock = new MockCalculator();
        TaxDecorator tax(mock);

        QCOMPARE(tax.calculate(0, 0), 120.0);

        delete mock;
    }

    void testDiscountDecoratorWithMock()
    {
        ICalculator* mock = new MockCalculator();
        DiscountDecorator discount(mock);

        QCOMPARE(discount.calculate(0, 0), 90.0);

        delete mock;
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CalculatorTests tests;
    QTest::qExec(&tests);

    MainWindow w;
    w.show();
    return a.exec();
}

// Магия Qt: нужна для компиляции тестов внутри main.cpp
#include "main.moc"