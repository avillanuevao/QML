#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <QVector>
#include <QDebug>
#include <QVariant>
#include "CalculatorComponent.hpp"

class CalculatorModel
{
public:

    CalculatorModel();
    void addition(int numb1, int numb2);
    void subtraction(int numb1, int numb2);
    void division(int numb1, int numb2);
    void multiplication(int numb1, int numb2);
    void equal();
    void clear();
    void setInput(CalculatorComponent input);
    void setInput(int input);
    void setResult(int result);
    int getResult();
    void operationSelector(CalculatorComponent operation, int numberOne, int numberTwo);
    int completedInt(QVector<int> number);
    void setDisplayText();
    QString getDisplayText();
    QString calculatorComponentString();
private:
    QString m_numberOne = "";
    QString m_numberTwo = "";
    QString m_componentCalculator = "";
    QString m_displayText = "";
    QVector<int> m_numberShedOne;
    QVector<int> m_numberShedTwo;
    CalculatorComponent m_calculatorComponent = CalculatorComponent::EMPTY;
    int m_result;
};

#endif
