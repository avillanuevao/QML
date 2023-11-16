#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include <QString>
#include <memory>
#include "StudentModel.hpp"
#include "StudentView.hpp"
#include "SceneCreator.hpp"
#include "ButtonSlot.hpp"

class StudentController : public QObject
{
    Q_OBJECT
public:
    StudentController(std::shared_ptr<StudentModel> studentModel, std::shared_ptr<SceneCreator> sceneCreator);
    void setStudentName(QString name);
    void setStudentId(int id);
    QString getStudentName();
    int getStudentId();
    void updateView();
private:
    std::shared_ptr<StudentModel> m_studentModel;
    std::shared_ptr<SceneCreator> m_sceneCreator;
    StudentView m_studentView;
};

#endif
