#include "ColumnLayoutCreator.hpp"

ColumnLayoutCreator::ColumnLayoutCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}


void ColumnLayoutCreator::createColumnLayout()
{

    QObject* rootObject = engine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);
    if(rootWindow)
    {
        QQmlComponent columnLayout(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Layouts 1.15; ColumnLayout{}";
        columnLayout.setData(qmlCode.toUtf8(), QUrl());
        QQuickItem *object = qobject_cast<QQuickItem*>(rootWindow->contentItem());
        QObject * columnLayoutCreate = columnLayout.create();
        QQuickItem *columnLayoutItem = qobject_cast<QQuickItem*>(columnLayoutCreate);
        if(object)
        {
            columnLayoutItem->setParentItem(object);
            itemID.push_back(columnLayoutItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

QVector<QQuickItem *> ColumnLayoutCreator::getItemId()
{
    return itemID;
}

void ColumnLayoutCreator::resetItemId()
{
    itemID.clear();
}
