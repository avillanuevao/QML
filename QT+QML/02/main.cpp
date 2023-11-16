#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "StudentModel.hpp"
#include "StudentController.hpp"
#include "SceneCreator.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    // Crear una instancia específica de StudentModel
    auto specificStudentModel = std::make_shared<StudentModel>();
    specificStudentModel->setName("John Doe");
    specificStudentModel->setId(123);

    auto sceneCreator = std::make_shared<SceneCreator>(engine);

    StudentController studentController(specificStudentModel, sceneCreator);
    engine.rootContext()->setContextProperty("studentController", QVariant::fromValue(&studentController));
    studentController.setStudentName("Villanueva");
    studentController.setStudentId(000);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    studentController.updateView();

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
