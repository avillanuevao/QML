#include "DepositMoneyView.hpp"

view::DepositMoneyView::DepositMoneyView(viewModel::DepositViewModel &depositViewModel, model::AllFunds &allFunds, QObject *parent) :
    m_depositViewModel(depositViewModel), m_allFunds(allFunds), QObject(parent)
{
}

void view::DepositMoneyView::update(model::MoneyDepositedSignal signal)
{
    std::cout << "Signal recieved: " << std::endl;
}

int view::DepositMoneyView::getAmountFromFund()
{
    return m_amountFromFund;
}

void view::DepositMoneyView::setAmountToDeposit(int amount)
{
    m_amountToDeposit = amount;
}

model::FundType view::DepositMoneyView::getFundType()
{
    return m_fundType;
}

void view::DepositMoneyView::setFundType(int fundType)
{
    m_fundType = static_cast<model::FundType>(fundType);
}

void view::DepositMoneyView::depositMoney()
{
    m_depositViewModel.depositMoney(m_amountToDeposit, m_fundType);
}

