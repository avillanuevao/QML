#include "Fund.hpp"

namespace model {

    Fund::Fund(FundType initialFundType, int initialAmount) : m_fundType(initialFundType), m_amount(initialAmount)
    {

    }

    FundType Fund::getFundType() const
    {
        return m_fundType;
    }

    int Fund::getAmount() const
    {
        return m_amount;
    }

    void Fund::increaseAmount(int newAmount)
    {
        m_amount += newAmount;
    }

}
