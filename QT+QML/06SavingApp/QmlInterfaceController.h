#ifndef QMLINTERFACECONTROLLER_H
#define QMLINTERFACECONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QtQml>
#include "QmlInterfaceModel.h"
#include "QmlFactory.h"
#include "Language.hpp"

enum FundType
{
    Savings,
    Housing,
    Food,
    Transportation,
    Entertainment,
    Travel,
    Clothing,
    Debts,
    Car
};

class QmlInterfaceController : public QObject
{
    Q_OBJECT
public:
    QmlInterfaceController();
    void handleButtonByType(QQuickItem *senderItem);
    void handleComboBoxByType(QQuickItem *senderItem);
    void handleTextFieldInput(QQuickItem *senderItem);

private:
    QmlInterfaceModel m_QmlInterfaceModel;
    void handleLanguage(int itemIndex);
    void handleOperation(int itemIndex);
    void handleFund(int itemIndex);
    void handleAmount();
    void handleData();
};

#endif // QMLINTERFACECONTROLLER_H
