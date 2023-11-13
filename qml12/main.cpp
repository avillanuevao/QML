#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "columnLCreator.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ColumnLCreator columLCreator(engine);
    engine.rootContext()->setContextProperty("columLCreator", &columLCreator);



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    columLCreator.createColumnL("principalColumn", 30, 30);


    return app.exec();
}
