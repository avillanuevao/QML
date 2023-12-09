#include "AppModel.hpp"

AppModel::AppModel()
{
    listsManager(BucketType::Savings);
    listsManager(BucketType::Housing);
    listsManager(BucketType::Food);
    listsManager(BucketType::Transportation);
    listsManager(BucketType::Entertainment);
    listsManager(BucketType::Travel);
    listsManager(BucketType::Clothing);
    listsManager(BucketType::Debts);
    listsManager(BucketType::Car);
}

void AppModel::listsManager(BucketType bucketType)
{
    m_fundList[bucketType] = 0;
    m_expenseList[bucketType] = 0;
}

void AppModel::setFund(BucketType bucketType, int funds)
{
    int expenses = getExpense(bucketType);
    int currentFunds = getFund(bucketType);
    int updateFunds = currentFunds + funds;
    if(funds >= 0 && updateFunds >= expenses)
    {
        m_fundList[bucketType] = updateFunds;
    }
}

void AppModel::setExpense(BucketType bucketType, int expenses)
{
    int currentExpenses = getExpense(bucketType);
    int updateExpenses = currentExpenses + expenses;
    if(expenses >= 0 && getFund(bucketType) >= updateExpenses)
    {
        m_expenseList[bucketType] = updateExpenses;
    }
}

int AppModel::getFund(BucketType bucketType)
{
    return m_fundList[bucketType];
}

int AppModel::getExpense(BucketType bucketType)
{
    return m_expenseList[bucketType];
}

void AppModel::resetFund(BucketType bucketType)
{
    m_fundList[bucketType] = 0;
}

void AppModel::resetExpense(BucketType bucketType)
{
    m_expenseList[bucketType] = 0;
}
