#include "QmlFactory.h"

QmlFactory::QmlFactory(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    m_engine(engine)
{

}

void QmlFactory::createColumn(QVector<QQuickItem *> &containter)
{
    QObject* rootObject = m_engine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);
    if(rootWindow)
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Layouts 1.15; ColumnLayout{}";
        component.setData(qmlCode.toUtf8(), QUrl());
        QQuickItem *object = qobject_cast<QQuickItem*>(rootWindow->contentItem());
        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(object)
        {
            componentItem->setParent(object);
            componentItem->setParentItem(object);
            containter.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void QmlFactory::createRow(QVector<QQuickItem *> &parent, int &parentId, QVector<QQuickItem *> &containter)
{
    if(parent[parentId])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Layouts 1.15; RowLayout{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentId]);
            componentItem->setParentItem(parent[parentId]);
            containter.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void QmlFactory::createButton(QVector<QQuickItem *> &parent, int &parentId, QVector<QQuickItem *> &containter, UIButton idButton)
{
    if(parent[parentId])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Button{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentId]);
            componentItem->setParentItem(parent[parentId]);
            componentItem->setProperty("id", idButton);
            containter.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void QmlFactory::createComboBox(QVector<QQuickItem *> &parent, int &parentId, QVector<QQuickItem *> &containter, UIDropDown idComboBox)
{
    if(parent[parentId])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; ComboBox{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentId]);
            componentItem->setParentItem(parent[parentId]);
            componentItem->setProperty("id", idComboBox);
            containter.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void QmlFactory::createTextField(QVector<QQuickItem *> &parent, int &parentId, QVector<QQuickItem *> &containter)
{
    if(parent[parentId])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; TextField{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentId]);
            componentItem->setParentItem(parent[parentId]);
            containter.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void QmlFactory::createTextElement(QVector<QQuickItem *> &parent, int &parentId, QVector<QQuickItem *> &containter)
{
    if (parent[parentId])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Text { }";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject* componentCreate = component.create();
        QQuickItem* componentItem = qobject_cast<QQuickItem*>(componentCreate);
        containter.push_back(componentItem);
        if (componentItem)
        {
            componentItem->setParent(parent[parentId]);
            componentItem->setParentItem(parent[parentId]);
            componentItem->setProperty("text", "0");
            containter.push_back(componentItem);
        }
        else
        {
            qDebug() << "qmlObject not found";
        }
    }
}
