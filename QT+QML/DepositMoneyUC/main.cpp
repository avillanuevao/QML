#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <view/DepositView.hpp>
#include <model/DepositModel.hpp>
#include <controller/DepositController.hpp>

int main()
{
    model::DepositModel depositModel;
    std::cout << "Address in DepositView: " << &depositModel << std::endl;
    controller::DepositController depositController(depositModel);
    view::DepositView depositView(depositController, depositModel);
    depositModel.addSubscriber(depositController);
    depositModel.modifyPrueba(10);
    depositView.getDepositData();
    depositView.sendDepositData();
    std::cout << "Prueba main: " << depositModel.getPrueba() << std::endl;

}
