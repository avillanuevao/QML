#include "CalculatorModel.hpp"

CalculatorModel::CalculatorModel()
{
}

void CalculatorModel::setInput(CalculatorComponent input)
{
    switch (input) {
    case CalculatorComponent::CLEAR:
        clear();
        break;
    case CalculatorComponent::EQUAL:
        if(m_numberOne != "" && m_numberTwo != "")
        {
            equal();
        }
        break;
    case CalculatorComponent::EMPTY:
        break;
    default:
        if(m_numberOne != "" && m_numberTwo == "")
        {
            m_calculatorComponent = input;
        }

        break;
    }
    setDisplayText();
}

void CalculatorModel::setInput(double input)
{
    if(m_calculatorComponent == CalculatorComponent::EMPTY && m_numberTwo == "")
    {
        m_numberOne += QString::number(input);

    }else
    {
        m_numberTwo += QString::number(input);
    }
    setDisplayText();
}

QString CalculatorModel::getDisplayText()
{
    return m_displayText;
}

void CalculatorModel::setDisplayText()
{
    m_displayText = m_numberOne + m_calculatorComponentConverter.calculatorComponentToString(m_calculatorComponent) + m_numberTwo;
}

void CalculatorModel::addition(double numb1, double numb2)
{
    m_result = numb1 + numb2;
}

void CalculatorModel::subtraction(double numb1, double numb2)
{
    m_result = numb1 - numb2;
}

void CalculatorModel::division(double numb1, double numb2)
{
    m_result = numb1 / numb2;
}

void CalculatorModel::multiplication(double numb1, double numb2)
{
    m_result = numb1 * numb2;
}

void CalculatorModel::equal()
{
    double numberOne = m_numberOne.toDouble();
    double numberTwo = m_numberTwo.toDouble();
    operationSelector(m_calculatorComponent, numberOne, numberTwo);
    m_numberOne = QString::number(m_result);
    m_numberTwo = "";
    m_calculatorComponent = CalculatorComponent::EMPTY;
    setDisplayText();
}

void CalculatorModel::clear()
{
    m_result = 0;
    m_numberOne = "";
    m_numberTwo = "";
    m_calculatorComponent = CalculatorComponent::EMPTY;
    setDisplayText();
}

void CalculatorModel::operationSelector(CalculatorComponent operation, double numberOne, double numberTwo)
{
    switch (operation) {
    case CalculatorComponent::ADD:
        addition(numberOne, numberTwo);
        break;
    case CalculatorComponent::SUBTRACT:
        subtraction(numberOne, numberTwo);
        break;
    case CalculatorComponent::MULTIPLY:
        multiplication(numberOne, numberTwo);
        break;
    case CalculatorComponent::DIVIDE:
        division(numberOne, numberTwo);
        break;
    default:
        qDebug() << "Not valid";
    }
}

