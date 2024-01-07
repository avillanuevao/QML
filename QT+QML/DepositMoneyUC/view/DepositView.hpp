#ifndef DEPOSITVIEW_HPP
#define DEPOSITVIEW_HPP

#include <iostream>

#include <controller/DepositController.hpp>
#include <model/DepositModel.hpp>
#include <model/FundType.hpp>

namespace view {

class DepositView
{
    public:
        DepositView(controller::DepositController& depositController, model::DepositModel& depositModel);

        int getInputMoney() const;
        void setInputMoney(int newInputMoney);
        model::FundType getInputFundType() const;
        void setInputFundType(model::FundType newInputFundType);
        void getDepositData();
        void sendDepositData();
        model::FundType convertStringToFundType(std::string stringFundType);
        std::string convertFundTypeToString(model::FundType fundType);

private:
        controller::DepositController& m_depositController;
        model::DepositModel& m_depositModel;
        int m_inputMoney;
        model::FundType m_inputFundType;
};

}

#endif // DEPOSITVIEW_HPP
