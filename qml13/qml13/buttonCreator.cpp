#include "buttonCreator.hpp"

ButtonCreator::ButtonCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}


void ButtonCreator::createButton(QQuickItem* property, QString textButton, int action)
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
            setActionButton(action);
            connect(buttonItem, SIGNAL(clicked()), this, SLOT(handleButtonClick()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void ButtonCreator::setActionButton(int action)
{
    actionButton = action;
}

int ButtonCreator::getActionButton()
{
    return actionButton;
}

void ButtonCreator::handleButtonClick()
{
    switch (actionButton) {
    case 0:
        buttonActionHandler.handleButtonSoftware();
        break;
    case 1:
        buttonActionHandler.handleButtonHardware();
        break;
    case 2:
        buttonActionHandler.handleButtonVillanueva();
        break;
    case 3:
        buttonActionHandler.handleButtonFernandez();
        break;
    case 4:
        buttonActionHandler.handleButtonMoran();
        break;
    }
}
