#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include "CalculatorModel.hpp"
#include "CalculatorView.hpp"
#include "CalculatorComponent.hpp"
#include <QObject>

class CalculatorController : public QObject
{
    Q_OBJECT
public:
    CalculatorController(QObject *parent = nullptr);
    QString getOperationalInput();
    QString getNumericalInput();
    void setOperationalInput(CalculatorComponent parameter);
    void setNumericalInput(int parameter);
private:
    CalculatorModel m_model;
    QString updateDisplay();
};

#endif
