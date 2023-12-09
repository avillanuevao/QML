#ifndef APPCONTROLLER_HPP
#define APPCONTROLLER_HPP

#include <iostream>
#include "BucketType.hpp"
#include "AppModel.hpp"
#include "PrintOptionDisplay.hpp"
#include "RequerimentOptionDisplay.hpp"

class AppController : public QObject
{
    Q_OBJECT
public:
    AppController();
    Q_INVOKABLE void setFund(int bucketType, int funds);
    Q_INVOKABLE void setExpense(int bucketType, int expenses);
    Q_INVOKABLE int getFund(int bucketType);
    Q_INVOKABLE int getExpense(int bucketType);
    Q_INVOKABLE int getMoneyBalance(int bucketType);
    Q_INVOKABLE void resetBucketType(int bucketType);
    QString bucketTypeformIntToQString(int bucketInt);
private:
    AppModel m_AppModel;
    BucketType formQStringToBucketType(int bucketQString);
};

#endif // APPCONTROLLER_HPP
