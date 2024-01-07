#include "DepositController.hpp"

namespace controller {

    DepositController::DepositController(model::DepositModel& depositModel) : m_depositModel(depositModel)
    {

    }

    void DepositController::sendDepositData(model::FundType fundType, int amount)
    {
        m_depositModel.recieveDepositData(fundType, amount);
    }

    void DepositController::update()
    {
        std::cout << "Signal recieved: " << std::endl;
    }
}


