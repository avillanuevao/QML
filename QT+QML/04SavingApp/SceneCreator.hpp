#ifndef SCENECREATOR_HPP
#define SCENECREATOR_HPP

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QtQml>
#include <QString>
#include <QVector>
#include "AppController.hpp"

enum UIButtonType
{
    Accept,
    Reset
};

enum UITransactionType
{
    Fund,
    Expense
};

enum UIItemType
{
    Transaction,
    Bucket
};

class SceneCreator : public QObject
{
    Q_OBJECT
public:
    explicit SceneCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    void createScene();
public slots:
    void handleButtonClicked();
    void handleCurrentIndexChanged();
    void handleNumericTextChanged();
private:
    AppController m_AppController;
    QQmlApplicationEngine &engine;
    QVector<QQuickItem*> itemIDColumn;
    QVector<QQuickItem*> textElement;
    int selectedType = 0;
    int selectedBucket = 0;
    int amountMoney = 0;
    void createColumn();
    void createButton(QString textButton, UIButtonType idButton);
    void createComboBox(QStringList modelList, UIItemType idComboBox);
    void createTextField();
    void createTextElement();
    void modifyTextElement(int newText);
};

#endif // SCENECREATOR_HPP
