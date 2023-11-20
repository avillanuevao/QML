#ifndef SCENECREATOR_H
#define SCENECREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QPair>
#include "ColumnLayoutCreator.hpp"
#include "RowLayoutCreator.hpp"
#include "ButtonCreator.hpp"
#include "TextCreator.hpp"
#include "CalculatorComponent.hpp"

class SceneCreator : public QObject {
    Q_OBJECT
public:
    explicit SceneCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createScene(int numberColumns, int numberRows, QVector<int> numberButtons, QVector<QString> textButton, QVector<std::function<void()>> functionVector);
    void scenaryDefinition();
    void updateText(QString text);
Q_SIGNALS:
    void buttonNumericClicked(int parameter);
    void buttonOperationalClicked(CalculatorComponent parameter);
public slots:
    void handleButtonNumericClicked(int value);
    void handleButtonCalculatorComponentClicked(CalculatorComponent value);
    void handleButtonSolutionClicked();

private:
    QQmlApplicationEngine &engine;
    ColumnLayoutCreator columnLayoutCreator;
    RowLayoutCreator rowLayoutCreator;
    ButtonCreator buttonCreator;
    TextCreator textCreator;

    void createColumn(int numberColumns);
    void createRows(int numberRows);
    void createText(QString text);
    void createButtons(QVector<int> numberButtons, QVector<QString> textButton, QVector<std::function<void ()>> functionVector);
};

#endif
