#include "DepositModel.hpp"

namespace model {

    DepositModel::DepositModel() : m_funds
    {
    {model::FundType::ACTIVITIES, model::Fund(model::FundType::ACTIVITIES, 0)},
    {model::FundType::CAR, model::Fund(model::FundType::CAR, 0)},
    {model::FundType::FOOD, model::Fund(model::FundType::FOOD, 0)},
    {model::FundType::TRANSPORT, model::Fund(model::FundType::TRANSPORT, 0)},
    {model::FundType::TRAVEL, model::Fund(model::FundType::TRAVEL, 0)}
    }
    {

    }

    void DepositModel::recieveDepositData(FundType fundType, int amount)
    {
        for (auto& pair : m_funds) {
            FundType currentType = pair.first;
            Fund& currentFund = pair.second;

            if(currentType == fundType)
            {
                currentFund.increaseAmount(amount);
                Signal signal = Signal();
                notifySubscribers(signal);
            }
        }
    }
}

