#include "ButtonCreator.hpp"

ButtonCreator::ButtonCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}


void ButtonCreator::createButton(QQuickItem* property, QString textButton, const char* slotFunction, const std::function<void()> &connectFunction)
{
    if(property)
    {
        QQmlComponent button(&engine, QUrl("qrc:/button.qml"));
        QObject * buttonCreate = button.create();
        QQuickItem *buttonItem = qobject_cast<QQuickItem*>(buttonCreate);
        if(buttonItem)
        {
            buttonItem->setParentItem(property);
            buttonItem->setProperty("text", textButton);
            connect(buttonItem, SIGNAL(clicked()), this, slotFunction);
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
