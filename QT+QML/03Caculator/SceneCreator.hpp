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
    void createScenery();

    Q_INVOKABLE void createScene(QVector<QString> textButton, int numberRows, QVector<int> numberButtons, QVector<std::function<void()>> functionVector);
    void updateText(QString text);
Q_SIGNALS:
    void buttonNumericClicked(int parameter);
    void buttonOperationalClicked(CalculatorComponent parameter);
public slots:
    void handleButtonSolutionClicked();
    void handleButtonSevenClicked();
    void handleButtonEightClicked();
    void handleButtonNineClicked();
    void handleButtonAdditionClicked();
    void handleButtonFourClicked();
    void handleButtonFiveClicked();
    void handleButtonSixClicked();
    void handleButtonSubtractionClicked();
    void handleButtonOneClicked();
    void handleButtonTwoClicked();
    void handleButtonThreeClicked();
    void handleButtonDivisionClicked();
    void handleButtonCeClicked();
    void handleButtonZeroClicked();
    void handleButtonEqualClicked();
    void handleButtonMultiplicationClicked();

private:
    QQmlApplicationEngine &engine;
    ColumnLayoutCreator columnLayoutCreator;
    RowLayoutCreator rowLayoutCreator;
    ButtonCreator buttonCreator;
    TextCreator textCreator;

    void removePreviousScene(QString property);
    void createColumn(int numberColumns);
    void createRows(int numberRows);
    void createText(QString text);

    void createButtons(QVector<int> numberButtons, QVector<QString> textButton, QVector<std::function<void ()>> functionVector);
};

#endif
