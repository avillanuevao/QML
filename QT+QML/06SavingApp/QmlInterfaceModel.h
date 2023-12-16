#ifndef QMLINTERFACEMODEL_H
#define QMLINTERFACEMODEL_H


class QmlInterfaceModel
{
public:
    QmlInterfaceModel();
    void setUILanguage(int index);
    void setUIOperation(int index);
    void setUIFund(int index);
    void setUIAmount(int index);
    int getUIAmount();
    int getUIFund();
    int getUIOperation();
    int getUILanguage();
private:
    int m_uiLanguage;
    int m_uiOperation;
    int m_uiFund;
    int m_uiAmount;
};

#endif // QMLINTERFACEMODEL_H
