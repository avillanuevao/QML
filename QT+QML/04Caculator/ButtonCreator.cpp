#include "ButtonCreator.hpp"

ButtonCreator::ButtonCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
}


void ButtonCreator::createButton(QQuickItem* property, QString textButton, const std::function<void()> &connectFunction)
{
    if(property)
    {
        QQmlComponent buttonComponent(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Button{}";
        buttonComponent.setData(qmlCode.toUtf8(), QUrl());

        QObject * buttonCreate = buttonComponent.create();
        QQuickItem *buttonItem = qobject_cast<QQuickItem*>(buttonCreate);
        if(buttonItem)
        {
            buttonItem->setParentItem(property);
            buttonItem->setProperty("text", textButton);
            connect(buttonItem, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));
            connectFunction();
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void ButtonCreator::handleButtonClick()
{
    emit buttonClicked();
}
