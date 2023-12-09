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
    createRow(itemIDColumn, 0);
    createRow(itemIDColumn, 0);
    createRow(itemIDColumn, 0);
    createRow(itemIDColumn, 0);
    createRow(itemIDColumn, 0);
    createRow(itemIDColumn, 0);
    createComboBox(UIItemType::Language, itemIDRow, 0);
    createComboBox(UIItemType::Transaction, itemIDRow, 1);
    createComboBox(UIItemType::Bucket, itemIDRow, 1);
    createTextField(itemIDRow, 2);
    createButton(UIButtonType::Accept, itemIDRow, 3);
    createButton(UIButtonType::Reset, itemIDRow, 3);
    createTextElement(itemIDRow, 4);
    initializeTextLanguage();
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
            modifyTextElement(m_AppController.getMoneyBalance(selectedBucket));
            break;
        case UIItemType::Language:
            selectedLanguage = comboBoxItem->property("currentIndex").toInt();
            setTextLanguage();
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

void SceneCreator::createRow(QVector<QQuickItem*> parent, int parentID)
{
    if(itemIDColumn[0])
    {
        QQmlComponent component(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Layouts 1.15; RowLayout{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentID]);
            componentItem->setParentItem(parent[parentID]);
            itemIDRow.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createButton(UIButtonType idButton, QVector<QQuickItem*> parent, int parentID)
{
    if(itemIDRow[2])
    {
        QQmlComponent component(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Button{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentID]);
            componentItem->setParentItem(parent[parentID]);
            componentItem->setProperty("id", idButton);
            buttonIdContainter[idButton] = componentItem;
            connect(componentItem, SIGNAL(clicked()), this, SLOT(handleButtonClicked()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createComboBox(UIItemType idComboBox, QVector<QQuickItem*> parent, int parentID)
{
    if(itemIDRow[0])
    {
        QQmlComponent component(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; ComboBox{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentID]);
            componentItem->setParentItem(parent[parentID]);
            componentItem->setProperty("id", idComboBox);
            comboBoxIdContainter[idComboBox] = componentItem;
            connect(componentItem, SIGNAL(currentIndexChanged()), this, SLOT(handleCurrentIndexChanged()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createTextField(QVector<QQuickItem*> parent, int parentID)
{
    if(itemIDRow[1])
    {
        QQmlComponent component(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; TextField{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentID]);
            componentItem->setParentItem(parent[parentID]);
            connect(componentItem, SIGNAL(textChanged()), this, SLOT(handleNumericTextChanged()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createTextElement(QVector<QQuickItem *> parent, int parentID)
{
    if (itemIDRow[3])
    {
        QQmlComponent component(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Text { }";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject* componentCreate = component.create();
        QQuickItem* componentItem = qobject_cast<QQuickItem*>(componentCreate);
        textElement.push_back(componentItem);
        if (componentItem)
        {
            componentItem->setParent(parent[parentID]);
            componentItem->setParentItem(parent[parentID]);
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
        QString bucketType = m_AppController.bucketTypeformIntToQString(selectedBucket);
        QString message = bucketType + ": " + QString::number(newText);
        textElement.at(0)->setProperty("text", message);
    }
    else
    {
        qDebug() << "Text Element not found";
    }
}

void SceneCreator::initializeTextLanguage()
{
    std::map<Vocabulary, QString> word = m_WordBook.getLanguage(Languages::English);
    QStringList modelListLanguage;
    modelListLanguage << word[Vocabulary::EnglishWord] << word[Vocabulary::SpanishWord];
    QQmlProperty(comboBoxIdContainter[UIItemType::Language], "model").write(QVariant::fromValue(modelListLanguage));
    setTextLanguage();
}

void SceneCreator::setTextLanguage()
{
    std::map<Vocabulary, QString> word;
    QStringList modelListFinances;
    QStringList modelListItems;

    switch (selectedLanguage) {
    case 0:
        word = m_WordBook.getLanguage(Languages::English);
        break;
    case 1:
        word = m_WordBook.getLanguage(Languages::Spanish);
        break;
    }
    modelListFinances << word[Vocabulary::FundWord] << word[Vocabulary::ExpenseWord];
    QQmlProperty(comboBoxIdContainter[UIItemType::Transaction], "model").write(QVariant::fromValue(modelListFinances));

    modelListItems << word[Vocabulary::SavingsWord] << word[Vocabulary::HousingWord] << word[Vocabulary::FoodWord]<< word[Vocabulary::TransportationWord] << word[Vocabulary::EntertainmentWord] << word[Vocabulary::TravelWord] << word[Vocabulary::ClothingWord] << word[Vocabulary::DebtsWord] << word[Vocabulary::CarWord];
    QQmlProperty(comboBoxIdContainter[UIItemType::Bucket], "model").write(QVariant::fromValue(modelListItems));

    buttonIdContainter[UIButtonType::Accept]->setProperty("text", word[Vocabulary::AcceptWord]);
    buttonIdContainter[UIButtonType::Reset]->setProperty("text", word[Vocabulary::ResetWord]);
}
