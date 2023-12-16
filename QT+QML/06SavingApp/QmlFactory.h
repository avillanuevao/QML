#ifndef QMLFACTORY_H
#define QMLFACTORY_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QtQml>

enum UIButton
{
    Accept,
    Reset
};

enum UIOperation
{
    Deposit,
    Withdrawal
};

enum UIDropDown
{
    Language,
    Operation,
    Fund,

};

class QmlFactory : public QObject
{
    Q_OBJECT
public:
    QmlFactory(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    void createColumn(QVector<QQuickItem*>& containter);
    void createRow(QVector<QQuickItem*>& parent, int& parentId, QVector<QQuickItem*>& containter);
    void createButton(QVector<QQuickItem*>& parent, int& parentId, QVector<QQuickItem*>& containter, UIButton idButton);
    void createComboBox(QVector<QQuickItem*>& parent, int& parentId, QVector<QQuickItem*>& containter, UIDropDown idComboBox);
    void createTextField(QVector<QQuickItem*>& parent, int& parentId, QVector<QQuickItem*>& containter);
    void createTextElement(QVector<QQuickItem*>& parent, int& parentId, QVector<QQuickItem*>& containter);
private:
    QQmlApplicationEngine &m_engine;
};

#endif // QMLFACTORY_H
