#include "QmlInterfaceModel.h"

QmlInterfaceModel::QmlInterfaceModel()
{
    
}

void QmlInterfaceModel::setUILanguage(int index)
{
    m_uiLanguage = index;
}

void QmlInterfaceModel::setUIOperation(int index)
{
    m_uiOperation = index;
}

void QmlInterfaceModel::setUIFund(int index)
{
    m_uiFund = index;
}

void QmlInterfaceModel::setUIAmount(int index)
{
    m_uiAmount = index;
}

int QmlInterfaceModel::getUIAmount()
{
    return m_uiAmount;
}

int QmlInterfaceModel::getUIFund()
{
    return m_uiFund;
}

int QmlInterfaceModel::getUIOperation()
{
    return m_uiOperation;
}

int QmlInterfaceModel::getUILanguage()
{
    return m_uiLanguage;
}
