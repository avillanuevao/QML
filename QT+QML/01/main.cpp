#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "StudentModel.hpp"
#include "StudentController.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    // Crear una instancia específica de StudentModel
    auto specificStudentModel = std::make_shared<StudentModel>();
    specificStudentModel->setName("John Doe");
    specificStudentModel->setId(123);

    // Crear una instancia de StudentController con un StudentModel específico
    StudentController studentController(specificStudentModel);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("studentController", QVariant::fromValue(&studentController));


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
