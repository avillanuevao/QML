#ifndef FUND_HPP
#define FUND_HPP

#include <model/FundType.hpp>

namespace model {

class Fund
{
    public:
        Fund(FundType initialFundType, int initialAmount);

        FundType getFundType() const;
        int getAmount() const;
        void increaseAmount(int newAmount);

    private:
        const FundType m_fundType;
        int m_amount;
};

}

#endif // FUND_HPP
