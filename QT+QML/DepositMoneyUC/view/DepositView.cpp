#include "DepositView.hpp"

namespace view {

    DepositView::DepositView(controller::DepositController &depositController, const model::DepositModel &depositModel) :
        m_depositController(depositController),
        m_depositModel(depositModel)
    {
    }

    int DepositView::getInputMoney() const
    {
        return m_inputMoney;
    }

    void DepositView::setInputMoney(int newInputMoney)
    {
        m_inputMoney = newInputMoney;
    }

    model::FundType DepositView::getInputFundType() const
    {
        return m_inputFundType;
    }

    void DepositView::setInputFundType(model::FundType newInputFundType)
    {
        m_inputFundType = newInputFundType;
    }

    void DepositView::getDepositData()
    {
        bool isInteger = false;
        bool isFundType = false;
        std::string stringInputMoney;
        std::string stringInputFundType;
        int integerInputMoney;
        model::FundType fundTypeInputFund;

        while(!isFundType)
        {
            std::cout << "Enter the fund type to deposit to: " << std::endl;
            stringInputFundType = "Car";

            try
            {
                fundTypeInputFund = convertStringToFundType(stringInputFundType);
                isFundType = true;
            }  catch (const std::invalid_argument&) {
                std::cout << "Invalid. Please, enter an fundType." << std::endl;
            }
        }
        m_inputFundType = fundTypeInputFund;

        while(!isInteger)
        {
            std::cout << "Enter the amount to deposit: " << std::endl;
            stringInputMoney = "100";

            try
            {
                integerInputMoney = std::stoi(stringInputMoney);
                isInteger = true;
            }  catch (const std::invalid_argument&) {
                std::cout << "Invalid. Please, enter an integer." << std::endl;
            }
        }
        m_inputMoney = integerInputMoney;
    }

    void DepositView::sendDepositData()
    {
        m_depositController.sendDepositData(m_inputFundType, m_inputMoney);
    }

    model::FundType DepositView::convertStringToFundType(std::string stringFundType)
    {
        if(stringFundType == "Activities")
        {
            return model::FundType::ACTIVITIES;
        }else if(stringFundType == "Car")
        {
            return model::FundType::CAR;
        }else if(stringFundType == "Food"){
            return model::FundType::FOOD;
        }else if(stringFundType == "Transport")
        {
            return model::FundType::TRANSPORT;
        }else if(stringFundType == "Travel")
        {
            return model::FundType::TRAVEL;
        }else
        {
            return model::FundType::INVALID;
        }
    }

    std::string DepositView::convertFundTypeToString(model::FundType fundType)
    {
        switch (fundType) {
            case model::FundType::ACTIVITIES:
                return "Activities";
            break;
            case model::FundType::CAR:
                return "Car";
            break;
            case model::FundType::FOOD:
                return "Food";
            break;
            case model::FundType::TRANSPORT:
                return "Transport";
            break;
            case model::FundType::TRAVEL:
                return "Travel";
            break;
            case model::FundType::INVALID:
                return "Invalid";
            break;
        }
    }

    void DepositView::update(model::Signal signal)
    {
        displaySuccessNotification();
    }

    void DepositView::displaySuccessNotification()
    {
        std::cout << "Deposit succesfully completed." << std::endl;
    }

}
