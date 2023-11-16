#include "RowLayoutCreator.hpp"

RowLayoutCreator::RowLayoutCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}


void RowLayoutCreator::createRowLayout(QString property)
{
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->property(property.toStdString().c_str()).value<QObject*>();

    if(qmlObject)
    {
        QQmlComponent rowLayout(&engine, QUrl("qrc:/rowLayout.qml"));
        QQuickItem *object = qobject_cast<QQuickItem*>(qmlObject);
        QObject * rowLayoutCreate = rowLayout.create();
        QQuickItem *rowLayoutItem = qobject_cast<QQuickItem*>(rowLayoutCreate);
        if(object)
        {
            rowLayoutItem->setParentItem(object);
            itemID.push_back(rowLayoutItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

QVector<QQuickItem *> RowLayoutCreator::getItemId()
{
    return itemID;
}

void RowLayoutCreator::resetItemId()
{
    itemID.clear();
}
