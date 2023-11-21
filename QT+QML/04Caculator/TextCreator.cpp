#include "TextCreator.hpp"

TextCreator::TextCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}


void TextCreator::createText(QQuickItem *property, QString text)
{
    if(property)
    {
        QQmlComponent textComponent(&engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Text{}";
        textComponent.setData(qmlCode.toUtf8(), QUrl());
        QObject * textCreate = textComponent.create();
        QQuickItem *textItem = qobject_cast<QQuickItem*>(textCreate);
        if(textItem)
        {
            textItem->setParentItem(property);
            textItem->setProperty("text", text);
            textId = textItem;

        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

QQuickItem *TextCreator::getTextId()
{
    return textId;
}

void TextCreator::updateText(QString newText)
{
    QQuickItem* item = textId;

    if (item) {
        item->setProperty("text", newText);
    } else {
        qDebug() << "El elemento 'solution' es nulo. No se puede actualizar el texto.";
    }
}
