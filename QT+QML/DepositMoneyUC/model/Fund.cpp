#include "Fund.hpp"

model::Fund::Fund(FundType initialFundType, int initialAmount) : m_fundType(initialFundType), m_amount(initialAmount)
{

}


namespace model {
FundType Fund::fundType() const
{
    return m_fundType;
}

int Fund::getAmount() const
{
    return m_amount;
}

void Fund::setAmount(int newAmount)
{
    m_amount = newAmount;
}

}
