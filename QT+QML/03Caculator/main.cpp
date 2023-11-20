#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "CalculatorController.hpp"
#include "SceneCreator.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;


    auto sceneCreator = std::make_shared<SceneCreator>(engine);
    CalculatorController calculatorController(sceneCreator);
    calculatorController.printCalculator();
    return app.exec();
}
