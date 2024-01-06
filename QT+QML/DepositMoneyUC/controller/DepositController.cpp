#include "DepositController.hpp"

namespace controller {

    DepositController::DepositController()
    {

    }

    void DepositController::sendDepositData(model::FundType fundType, int amount)
    {
        m_depositModel.recieveDepositData(fundType, amount);
    }

}


