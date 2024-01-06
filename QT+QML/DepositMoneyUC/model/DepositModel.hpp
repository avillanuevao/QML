#ifndef DEPOSITMODEL_HPP
#define DEPOSITMODEL_HPP

#include <iostream>
#include <vector>
#include <map>
#include <model/FundType.hpp>
#include <model/Fund.hpp>

namespace model {

class DepositModel
{
    public:
        DepositModel();
        void recieveDepositData(FundType fundType, int amount);
    private:
        std::map<FundType, Fund> m_funds;
};

}

#endif // DEPOSITMODEL_HPP
