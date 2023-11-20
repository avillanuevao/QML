#include "CalculatorModel.hpp"

CalculatorModel::CalculatorModel()
{

}

void CalculatorModel::addition(int numb1, int numb2)
{
    m_result = numb1 + numb2;
}

void CalculatorModel::subtraction(int numb1, int numb2)
{
    m_result = numb1 - numb2;
}

void CalculatorModel::division(int numb1, int numb2)
{
    m_result = numb1 / numb2;
}

void CalculatorModel::multiplication(int numb1, int numb2)
{
    m_result = numb1 * numb2;
}

void CalculatorModel::equal()
{
    int numberOne = m_numberOne.toInt();
    int numberTwo = m_numberTwo.toInt();
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

void CalculatorModel::setInput(int input)
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

void CalculatorModel::setResult(int result)
{
    m_result = result;
}

int CalculatorModel::getResult()
{
    return m_result;
}

void CalculatorModel::operationSelector(CalculatorComponent operation, int numberOne, int numberTwo)
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

int CalculatorModel::completedInt(QVector<int> number)
{
    int completedNumber = 0;
    for(int i = 0; i < number.size(); i++)
    {
        completedNumber = completedNumber * 10 + number.at(i);
    }
    return completedNumber;
}

void CalculatorModel::setDisplayText()
{
    m_displayText = m_numberOne + calculatorComponentString() + m_numberTwo;
    qDebug() << m_numberOne << " NumberO";
    qDebug() << calculatorComponentString() << " calculatorC";
    qDebug() << m_numberTwo << " NumberT";


}

QString CalculatorModel::getDisplayText()
{
    return m_displayText;
}

QString CalculatorModel::calculatorComponentString()
{
    switch (m_calculatorComponent) {
    case CalculatorComponent::ADD:
        return "+";
        break;
    case CalculatorComponent::SUBTRACT:
        return  "-";
        break;
    case CalculatorComponent::MULTIPLY:
        return  "*";
        break;
    case CalculatorComponent::DIVIDE:
        return "/";
        break;
    case CalculatorComponent::EMPTY:
        return "";
        break;
    default:
        return "Not valid";
        break;
    }
}
