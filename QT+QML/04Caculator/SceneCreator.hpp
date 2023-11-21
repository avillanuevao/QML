#ifndef SCENECREATOR_H
#define SCENECREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QPair>
#include <memory>
#include "ColumnLayoutCreator.hpp"
#include "RowLayoutCreator.hpp"
#include "ButtonCreator.hpp"
#include "TextCreator.hpp"
#include "CalculatorComponent.hpp"
#include "CalculatorComponentConverter.hpp"
#include "CalculatorController.hpp"

class SceneCreator : public QObject {
    Q_OBJECT
public:
    explicit SceneCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createScene();
private:
    QQmlApplicationEngine &engine;
    ColumnLayoutCreator m_columnLayoutCreator;
    RowLayoutCreator m_rowLayoutCreator;
    ButtonCreator m_buttonCreator;
    TextCreator m_textCreator;
    CalculatorController m_calculatorController;
    CalculatorComponentConverter m_calculatorComponentConverter;

    void createColumn(int numberColumns);
    void createRows(int numberRows);
    void createText(QVector<int> numberTexts, QVector<QQuickItem *> itemID, QVector<QString> textLabel);
    void updateText(QString text);
    void createButtons(QVector<int> numberButtons, QVector<QQuickItem *> itemID, QVector<QString> textButton);
    void handleButtonNumericClicked(int value);
    void handleButtonCalculatorComponentClicked(CalculatorComponent value);
    std::function<void ()> buttonHandlerSelector(QString input);
};

#endif
