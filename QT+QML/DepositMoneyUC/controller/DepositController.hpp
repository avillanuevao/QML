#ifndef DEPOSITCONTROLLER_HPP
#define DEPOSITCONTROLLER_HPP

#include <model/DepositModel.hpp>
#include <model/FundType.hpp>

namespace controller {

class DepositController
{
    public:
        DepositController();
        void sendDepositData(model::FundType fundType, int amount);

    private:
        model::DepositModel m_depositModel;
};
}

#endif // DEPOSITCONTROLLER_HPP
