#include "SceneCreator.hpp"

SceneCreator::SceneCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}

void SceneCreator::createScene()
{
    createColumn();
    QStringList modelListFinances;
    modelListFinances << "Fund" << "Expense";
    QStringList modelListItems;
    modelListItems << "Savings" << "Housing" << "Food" << "Transportation" << "Entertainment" << "Travel" << "Clothing" << "Debts" << "Car";
    createComboBox(modelListFinances, UIItemType::Transaction);
    createComboBox(modelListItems, UIItemType::Bucket);
    createTextField();
    createButton("Accept", UIButtonType::Accept);
    createButton("Reset", UIButtonType::Reset);
    createTextElement();
}

void SceneCreator::handleButtonClicked()
{
    // Obtener el objeto QQuickItem del que se originó la señal
    QQuickItem *clickedButton = qobject_cast<QQuickItem*>(sender());
    // Verificar si se obtuvo con éxito el objeto QQuickItem
    if (clickedButton)
    {
        // Obtener el valor de la propiedad "id" del botón
        int buttonId = clickedButton->property("id").toInt();
        //Acciones basadas en el tipo de botón
        switch (buttonId) {
        case UIButtonType::Accept:
            switch (selectedType) {
            case UITransactionType::Fund:
                m_AppController.setFund(selectedBucket, amountMoney);
                break;
            case UITransactionType::Expense:
                m_AppController.setExpense(selectedBucket, amountMoney);
                break;
            }
            break;
        case UIButtonType::Reset:
            m_AppController.resetBucketType(selectedBucket);
            break;
        }
        modifyTextElement(m_AppController.getMoneyBalance(selectedBucket));
    }
    else
    {
        qDebug() << "clickedButton not found";
    }
}

void SceneCreator::handleCurrentIndexChanged()
{
    // Obtiene el objeto que envió la señal
    QObject* senderObject = QObject::sender();
    // Intenta convertir el objeto a un QQuickItem
    QQuickItem* comboBoxItem = qobject_cast<QQuickItem*>(senderObject);
    // Verifica si la conversión fue exitosa
    if (comboBoxItem)
    {
        // Obtiene el valor de la propiedad "id" del ComboBox
        int comboBoxId = comboBoxItem->property("id").toInt();
        switch (comboBoxId) {
        case UIItemType::Transaction:
            selectedType = comboBoxItem->property("currentIndex").toInt();
            break;
        case UIItemType::Bucket:
            selectedBucket = comboBoxItem->property("currentIndex").toInt();
            break;
        }
    }
    else
    {
        qDebug() << "ComboBox not found";
    }
}

void SceneCreator::handleNumericTextChanged()
{
    // Obtiene el objeto que envió la señal
    QObject* senderObject = QObject::sender();
    // Intenta convertir el objeto a un QQuickItem
    QQuickItem* textFieldItem = qobject_cast<QQuickItem*>(senderObject);
    // Verifica si la conversión fue exitosa
    if (textFieldItem)
    {
        QString textFieldText = textFieldItem->property("text").toString();
        amountMoney = textFieldText.toInt();
    }
    else
    {
        qDebug() << "TextField Object not found";
    }
}

void SceneCreator::createColumn()
{
    QObject* rootObject = engine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);
    if(rootWindow)
    {
        QQmlComponent component(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Layouts 1.15; ColumnLayout{}";
        component.setData(qmlCode.toUtf8(), QUrl());
        QQuickItem *object = qobject_cast<QQuickItem*>(rootWindow->contentItem());
        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(object)
        {
            componentItem->setParentItem(object);
            itemIDColumn.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createButton(QString textButton, UIButtonType idButton)
{
    if(itemIDColumn[0])
    {
        QQmlComponent component(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Button{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(itemIDColumn[0]);
            componentItem->setParentItem(itemIDColumn[0]);
            componentItem->setProperty("id", idButton);
            componentItem->setProperty("text", textButton);
            connect(componentItem, SIGNAL(clicked()), this, SLOT(handleButtonClicked()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createComboBox(QStringList modelList, UIItemType idComboBox)
{
    if(itemIDColumn[0])
    {
        QQmlComponent component(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; ComboBox{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(itemIDColumn[0]);
            componentItem->setParentItem(itemIDColumn[0]);
            componentItem->setProperty("id", idComboBox);
            QQmlProperty(componentItem, "model").write(QVariant::fromValue(modelList));
            connect(componentItem, SIGNAL(currentIndexChanged()), this, SLOT(handleCurrentIndexChanged()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createTextField()
{
    if(itemIDColumn[0])
    {
        QQmlComponent component(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; TextField{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(itemIDColumn[0]);
            componentItem->setParentItem(itemIDColumn[0]);
            connect(componentItem, SIGNAL(textChanged()), this, SLOT(handleNumericTextChanged()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createTextElement()
{
    if (itemIDColumn[0])
    {
        QQmlComponent component(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Text { }";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject* componentCreate = component.create();
        QQuickItem* componentItem = qobject_cast<QQuickItem*>(componentCreate);
        textElement.push_back(componentItem);
        if (componentItem)
        {
            componentItem->setParent(itemIDColumn[0]);
            componentItem->setParentItem(itemIDColumn[0]);
            componentItem->setProperty("text", "0");
        }
        else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::modifyTextElement(int newText)
{
    if (textElement.at(0))
    {
        textElement.at(0)->setProperty("text", newText);
    }
    else
    {
        qDebug() << "Text Element not found";
    }
}
