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
#include "Language.hpp"

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
    Bucket,
    Language
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
    WordBook m_WordBook;
    AppController m_AppController;
    QQmlApplicationEngine &engine;
    QVector<QQuickItem*> itemIDColumn;
    QVector<QQuickItem*> itemIDRow;
    std::map<UIButtonType, QQuickItem*> buttonIdContainter;
    std::map<UIItemType, QQuickItem*> comboBoxIdContainter;
    QVector<QQuickItem*> textElement;
    int selectedLanguage = 0;
    int selectedType = 0;
    int selectedBucket = 0;
    int amountMoney = 0;
    void createColumn();
    void createRow(QVector<QQuickItem*> parent, int parentID);
    void createButton(QString textButton, UIButtonType idButton, QVector<QQuickItem*> parent, int parentID);
    void createComboBox(QStringList modelList, UIItemType idComboBox, QVector<QQuickItem*> parent, int parentID);
    void createTextField(QVector<QQuickItem*> parent, int parentID);
    void createTextElement(QVector<QQuickItem*> parent, int parentID);
    void modifyTextElement(int newText);
    void modifyTextLanguage();
};

#endif // SCENECREATOR_HPP
