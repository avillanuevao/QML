#include "StudentController.hpp"

StudentController::StudentController(std::shared_ptr<StudentModel> studentModel, std::shared_ptr<SceneCreator> sceneCreator)
    : m_studentModel(studentModel), m_sceneCreator(sceneCreator) {}

void StudentController::setStudentName(QString name)
{
    m_studentModel->setName(name);
}

void StudentController::setStudentId(int id)
{
    m_studentModel->setId(id);
}

QString StudentController::getStudentName()
{
    return m_studentModel->getName();
}

int StudentController::getStudentId()
{
    return m_studentModel->getId();
}

void StudentController::updateView()
{
    m_studentView.printStudentDetails(m_studentModel->getName(), m_studentModel->getId());
    QString property = "principalColumn";
    QString text01 = m_studentModel->getName();
    QString text02 =  QString::number(m_studentModel->getId());
    QVector<QString> textButton = {text01, text02};
    int numberRows = 1;
    QVector<int> numberButtons = {2};
    QVector<std::function<void()>> functionVector;
    functionVector.append([this]() { m_sceneCreator->handleNameButtonClick(); });
    functionVector.append([this]() { m_sceneCreator->handleIdButtonClick(); });
    m_sceneCreator->createScene(property, textButton, numberRows, numberButtons, functionVector);
}
