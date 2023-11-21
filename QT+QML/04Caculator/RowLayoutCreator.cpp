#include "RowLayoutCreator.hpp"

RowLayoutCreator::RowLayoutCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}


void RowLayoutCreator::createRowLayout(QQuickItem* property)
{

    if(property)
    {
        QQmlComponent rowComponent(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Layouts 1.15; RowLayout{}";
        rowComponent.setData(qmlCode.toUtf8(), QUrl());

        QObject * rowCreate = rowComponent.create();
        QQuickItem *rowItem = qobject_cast<QQuickItem*>(rowCreate);
        if(rowItem)
        {
            rowItem->setParentItem(property);
            itemID.push_back(rowItem);
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
