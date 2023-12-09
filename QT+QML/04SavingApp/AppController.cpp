#include "AppController.hpp"

AppController::AppController()
{

}

void AppController::setFund(int bucketType, int funds)
{
    BucketType bucketT = formQStringToBucketType(bucketType);
    m_AppModel.setFund(bucketT, funds);
}

void AppController::setExpense(int bucketType, int expenses)
{
    BucketType bucketT = formQStringToBucketType(bucketType);
    m_AppModel.setExpense(bucketT, expenses);
}

int AppController::getFund(int bucketType)
{
    BucketType bucketT = formQStringToBucketType(bucketType);
    int fund = m_AppModel.getFund(bucketT);
    return fund;
}

int AppController::getExpense(int bucketType)
{
    BucketType bucketT = formQStringToBucketType(bucketType);
    int expense = m_AppModel.getExpense(bucketT);
    return expense;
}

int AppController::getMoneyBalance(int bucketType)
{
    BucketType bucketT = formQStringToBucketType(bucketType);
    int fund = m_AppModel.getFund(bucketT);
    int expense = m_AppModel.getExpense(bucketT);
    qDebug() << fund - expense << " getMoneyBalance";
    return fund - expense;
}

void AppController::resetBucketType(int bucketType)
{
    BucketType bucketT = formQStringToBucketType(bucketType);
    m_AppModel.resetFund(bucketT);
    m_AppModel.resetExpense(bucketT);
}

BucketType AppController::formQStringToBucketType(int bucketQString)
{
    switch (bucketQString) {
    case 0:
        return BucketType::Savings;
        break;
    case 1:
        return BucketType::Housing;
        break;
    case 2:
        return BucketType::Food;
        break;
    case 3:
        return BucketType::Transportation;
        break;
    case 4:
        return BucketType::Entertainment;
        break;
    case 5:
        return BucketType::Clothing;
        break;
    case 6:
        return BucketType::Debts;
        break;
    case 7:
        return BucketType::Car;
        break;
    }
}

QString AppController::bucketTypeformIntToQString(int bucketInt)
{
    switch (bucketInt) {
    case 0:
        return "Savings";
        break;
    case 1:
        return "Housing";
        break;
    case 2:
        return "Food";
        break;
    case 3:
        return "Transportation";
        break;
    case 4:
        return "Entertainment";
        break;
    case 5:
        return "Clothing";
        break;
    case 6:
        return "Debts";
        break;
    case 7:
        return "Car";
        break;
    }
}

