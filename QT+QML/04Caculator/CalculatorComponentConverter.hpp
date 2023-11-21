#ifndef CALCULATORCOMPONENTCONVERTER_H
#define CALCULATORCOMPONENTCONVERTER_H

#include "QString"
#include "CalculatorComponent.hpp"

class CalculatorComponentConverter
{
public:
    CalculatorComponentConverter();
    CalculatorComponent stringToCalculorComponent(QString input);
    QString calculatorComponentToString(CalculatorComponent calculatorComponent);

};

#endif
