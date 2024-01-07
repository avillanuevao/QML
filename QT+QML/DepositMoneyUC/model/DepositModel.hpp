#ifndef DEPOSITMODEL_HPP
#define DEPOSITMODEL_HPP

#include <iostream>
#include <map>

#include <model/FundType.hpp>
#include <model/Fund.hpp>
#include <utils/SignalPublisher.hpp>
#include <model/signals/Signal.hpp>

namespace model {

class DepositModel : public utils::SignalPublisher<model::Signal>
{
    public:
        DepositModel();
        void recieveDepositData(FundType fundType, int amount);
    private:
        std::map<FundType, Fund> m_funds;
};

}

#endif // DEPOSITMODEL_HPP
