#ifndef BUTTONCREATOR_H
#define BUTTONCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>
#include "buttonActionHandler.hpp"

class ButtonCreator : public QObject {
    Q_OBJECT
public:
    explicit ButtonCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createButton(QQuickItem* property, QString textButton, int action);
    void setActionButton(int action);
    int getActionButton();
public slots:
    void handleButtonClick();
private:
    QQmlApplicationEngine &engine;
    ButtonActionHandler buttonActionHandler;
    int actionButton;
};

#endif
