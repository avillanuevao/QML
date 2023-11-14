#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "rowLayoutCreator.hpp"
#include "buttonCreator.hpp"

#include "sceneCreator.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    //RowLayoutCreator rowLayoutCreator(engine);
    //ButtonCreator buttonCreator(engine);
    SceneCreator sceneCreator(engine);

    //engine.rootContext()->setContextProperty("rowLayoutCreator", &rowLayoutCreator);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    sceneCreator.createSceneryA();
    return app.exec();
}
