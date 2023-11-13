#include "columnLCreator.hpp"

ColumnLCreator::ColumnLCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}


void ColumnLCreator::createColumnL(QString property, int height, int width)
{
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->property(property.toStdString().c_str()).value<QObject*>();

    if(qmlObject)
    {
        QQmlComponent columLayout(&engine, QUrl("qrc:/columLayout.qml"));
        QQuickItem *object = qobject_cast<QQuickItem*>(qmlObject);
        QObject * columnLayoutCreate = columLayout.create();
        QQuickItem *columnLayoutItem = qobject_cast<QQuickItem*>(columnLayoutCreate);
        if(object)
        {

            columnLayoutItem->setParentItem(object);
            columnLayoutItem->setWidth(width);
            columnLayoutItem->setHeight(height);

            QQmlComponent buttonComponent(&engine, QUrl("qrc:/button.qml"));
            QObject *buttonObject = buttonComponent.create();
            QQuickItem *buttonItem = qobject_cast<QQuickItem*>(buttonObject);

            if (buttonItem)
            {
                buttonItem->setParentItem(columnLayoutItem);
                buttonItem->setWidth(width);
                buttonItem->setHeight(height);

                // Crear un segundo botón
                QQmlComponent button2Component(&engine, QUrl("qrc:/button.qml"));
                QObject *button2Object = button2Component.create();
                QQuickItem *button2Item = qobject_cast<QQuickItem*>(button2Object);

                if (button2Item)
                {
                    button2Item->setParentItem(columnLayoutItem);
                    button2Item->setWidth(width);
                    button2Item->setHeight(height);
                }
                else
                {
                    qDebug() << "Second button creation failed";
                }

            }else
            {
                qDebug() << "qmlObject not found";
            }
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}
