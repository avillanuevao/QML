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

    SceneCreator sceneCreator(engine);
    sceneCreator.createScene();
    return app.exec();
}
