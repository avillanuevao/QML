#include "QmlInterfaceController.h"

QmlInterfaceController::QmlInterfaceController()
{

}

void QmlInterfaceController::handleButtonByType(QQuickItem *senderItem)
{
    if (senderItem)
    {
        int buttonId = senderItem->property("id").toInt();
        switch (buttonId) {
        case UIButton::Accept:
            handleData();
            break;
        }
    }
    else
    {
        qDebug() << "not found";
    }
}

void QmlInterfaceController::handleComboBoxByType(QQuickItem *senderItem)
{
    if (senderItem)
    {
        int id = senderItem->property("id").toInt();
        int item = senderItem->property("currentIndex").toInt();
        switch (id) {
        case UIDropDown::Language:
            handleLanguage(item);
            break;
        case UIDropDown::Operation:
            handleOperation(item);
            break;
        case UIDropDown::Fund:
            handleFund(item);
            break;
        }
    }
    else
    {
        qDebug() << "not found";
    }
}

void QmlInterfaceController::handleTextFieldInput(QQuickItem *senderItem)
{
    if (senderItem)
    {
        QString textFieldText = senderItem->property("text").toString();
        m_QmlInterfaceModel.setUIAmount(textFieldText.toInt());
    }
    else
    {
        qDebug() << "TextField Object not found";
    }
}

void QmlInterfaceController::handleLanguage(int itemIndex)
{
    m_QmlInterfaceModel.setUILanguage(itemIndex);
}

void QmlInterfaceController::handleOperation(int itemIndex)
{
    m_QmlInterfaceModel.setUIOperation(itemIndex);
}

void QmlInterfaceController::handleFund(int itemIndex)
{
    m_QmlInterfaceModel.setUIOperation(itemIndex);
}

void QmlInterfaceController::handleAmount()
{

}

void QmlInterfaceController::handleData()
{
    qDebug() << "handleData";
    //Vista publisher encargada del envío de la información
    m_QmlInterfaceModel.getUILanguage();
    m_QmlInterfaceModel.getUIAmount();
    m_QmlInterfaceModel.getUIFund();
    m_QmlInterfaceModel.getUIOperation();
}
