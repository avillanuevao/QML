#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QmlInterfaceController.h"
#include "QmlInterfacePainter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    std::shared_ptr<QmlInterfacePainter> qmlInterfacePainter = std::make_shared<QmlInterfacePainter>(engine, nullptr);
    return app.exec();
}
