#include "CalculatorController.hpp"

CalculatorController::CalculatorController(std::shared_ptr<SceneCreator> sceneCreator, QObject *parent)
    : QObject(parent), m_sceneCreator(sceneCreator)
{
    // Conectar la señal y la ranura en el constructor
    QObject::connect(m_sceneCreator.get(), &SceneCreator::buttonOperationalClicked, this, &CalculatorController::getOperationalInput);
    QObject::connect(m_sceneCreator.get(), &SceneCreator::buttonNumericClicked, this, &CalculatorController::getNumericalInput);
}

void CalculatorController::printCalculator()
{
    m_sceneCreator->scenaryDefinition();
}

void CalculatorController::getOperationalInput(CalculatorComponent parameter)
{
    m_model.setInput(parameter);
    updateDisplay();
}

void CalculatorController::getNumericalInput(int parameter)
{
    m_model.setInput(parameter);
    updateDisplay();
}

void CalculatorController::updateDisplay()
{
    QString displayText = m_model.getDisplayText();
    m_sceneCreator->updateText(displayText);
}


