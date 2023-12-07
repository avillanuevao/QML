#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "AppController.hpp"
#include "SceneCreator.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;


    auto sceneCreator = std::make_shared<SceneCreator>(engine);
    sceneCreator->createScene();
    return app.exec();
}

//int main(int argc, char *argv[]) {
//#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

//    QGuiApplication app(argc, argv);
//    QQmlApplicationEngine engine;
//    AppController appController;
//    engine.rootContext()->setContextProperty("appController", &appController);
//    // Inicia el motor QML con el archivo principal
//    const QUrl url(QStringLiteral("qrc:/main.qml"));

//    // Conecta la creación del objeto QML al cierre de la aplicación si hay errores
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);

//    // Carga el archivo QML principal
//    engine.load(url);

//    return app.exec();
//}
