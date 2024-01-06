#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <view/DepositView.hpp>
#include <model/DepositModel.hpp>
#include <controller/DepositController.hpp>

int main()
{
    model::DepositModel depositModel;
    controller::DepositController depositController;
    view::DepositView depositView(depositController, depositModel);

    depositView.getDepositData();
    depositView.sendDepositData();
}
