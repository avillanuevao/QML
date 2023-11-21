#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <QVector>
#include <QDebug>
#include <QVariant>
#include "CalculatorComponent.hpp"
#include "CalculatorComponentConverter.hpp"

class CalculatorModel
{
public:

    CalculatorModel();
    void setInput(CalculatorComponent input);
    void setInput(double input);
    QString getDisplayText();
private:
    QString m_numberOne = "";
    QString m_numberTwo = "";
    QString m_componentCalculator = "";
    QString m_displayText = "";
    double m_result;
    CalculatorComponent m_calculatorComponent = CalculatorComponent::EMPTY;
    CalculatorComponentConverter m_calculatorComponentConverter;
    void setDisplayText();
    void addition(double numb1, double numb2);
    void subtraction(double numb1, double numb2);
    void division(double numb1, double numb2);
    void multiplication(double numb1, double numb2);
    void equal();
    void clear();
    void operationSelector(CalculatorComponent operation, double numberOne, double numberTwo);

};

#endif
