#ifndef DEPOSITVIEW_HPP
#define DEPOSITVIEW_HPP

#include <iostream>

#include <controller/DepositController.hpp>
#include <model/DepositModel.hpp>
#include <model/FundType.hpp>
#include <model/signals/Signal.hpp>
#include <utils/SignalSubscriber.hpp>

namespace view {

class DepositView : public utils::SignalSubscriber<model::Signal>
{
    public:
        DepositView(controller::DepositController& depositController, const model::DepositModel& depositModel);

        void getDepositData();
        void sendDepositData();
        void update(model::Signal signal);

private:
        controller::DepositController& m_depositController;
        const model::DepositModel& m_depositModel;
        int m_inputMoney;
        model::FundType m_inputFundType;

        void displaySuccessNotification();
        int getInputMoney() const;
        void setInputMoney(int newInputMoney);
        model::FundType getInputFundType() const;
        void setInputFundType(model::FundType newInputFundType);
        model::FundType convertStringToFundType(std::string stringFundType);
        std::string convertFundTypeToString(model::FundType fundType);
};

}

#endif // DEPOSITVIEW_HPP
