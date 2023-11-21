#include "CalculatorController.hpp"

CalculatorController::CalculatorController(QObject *parent)
    : QObject(parent)
{
}

QString CalculatorController::getOperationalInput()
{
    return updateDisplay();
}

QString CalculatorController::getNumericalInput()
{
    return updateDisplay();
}

void CalculatorController::setOperationalInput(CalculatorComponent parameter)
{
    m_model.setInput(parameter);
}

void CalculatorController::setNumericalInput(int parameter)
{
    m_model.setInput(parameter);
}

QString CalculatorController::updateDisplay()
{
    QString displayText = m_model.getDisplayText();
    return displayText;
}


