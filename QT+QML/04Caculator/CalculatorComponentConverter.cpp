#include "CalculatorComponentConverter.hpp"

CalculatorComponentConverter::CalculatorComponentConverter()
{

}

CalculatorComponent CalculatorComponentConverter::stringToCalculorComponent(QString input)
{
    if(input == "+")
    {
        return CalculatorComponent::ADD;
    }else if(input == "-")
    {
        return CalculatorComponent::SUBTRACT;
    }else if(input == "/")
    {
        return CalculatorComponent::DIVIDE;
    }else if(input == "*")
    {
        return CalculatorComponent::MULTIPLY;
    }else if(input == "Ce")
    {
        return CalculatorComponent::CLEAR;
    }else if(input == "=")
    {
        return CalculatorComponent::EQUAL;
    }else
    {
        return CalculatorComponent::EMPTY;
    }
}

QString CalculatorComponentConverter::calculatorComponentToString(CalculatorComponent calculatorComponent)
{
    switch (calculatorComponent) {
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
