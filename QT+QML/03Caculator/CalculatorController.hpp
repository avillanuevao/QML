#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include "CalculatorModel.hpp"
#include "CalculatorView.hpp"
#include "CalculatorComponent.hpp"
#include "SceneCreator.hpp"
#include <QObject>

class CalculatorController : public QObject
{
    Q_OBJECT
public:
    CalculatorController(std::shared_ptr<SceneCreator> sceneCreator, QObject *parent = nullptr);
    void printCalculator();
    void getOperationalInput(CalculatorComponent parameter);
    void getNumericalInput(int parameter);
    void display(QString parameter);
    void updateDisplay();
private:
    CalculatorModel m_model;
    CalculatorView m_view;
    std::shared_ptr<SceneCreator> m_sceneCreator;
    QString m_label;
};

#endif
