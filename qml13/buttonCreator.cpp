#include "buttonCreator.hpp"

ButtonCreator::ButtonCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}


void ButtonCreator::createButton(QQuickItem* property, int height, int width)
{
    if(property)
    {
        QQmlComponent button(&engine, QUrl("qrc:/button.qml"));
        QObject * buttonCreate = button.create();
        QQuickItem *buttonItem = qobject_cast<QQuickItem*>(buttonCreate);
        if(buttonItem)
        {
            buttonItem->setParentItem(property);
            buttonItem->setWidth(width);
            buttonItem->setHeight(height);
            buttonItem->setProperty("anchors.centerIn", QVariant::fromValue(property));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}
