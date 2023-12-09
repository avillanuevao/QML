#ifndef APPMODEL_HPP
#define APPMODEL_HPP

#include <iostream>
#include <map>
#include <QDebug>
#include "BucketType.hpp"
#include "dataBase.json"

class AppModel
{
public:
    AppModel();
    void setFund(BucketType bucketType, int funds);
    void setExpense(BucketType bucketType, int expenses);
    int getFund(BucketType bucketType);
    int getExpense(BucketType bucketType);
    void resetFund(BucketType bucketType);
    void resetExpense(BucketType bucketType);
private:
    std::map<BucketType, int> m_fundList;
    std::map<BucketType, int> m_expenseList;
    void listsManager(BucketType bucketType);
};

#endif // APPMODEL_HPP
