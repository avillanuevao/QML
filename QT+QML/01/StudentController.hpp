#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include <QString>
#include <memory>
#include "StudentModel.hpp"
#include "StudentView.hpp"

class StudentController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString studentName READ getStudentName NOTIFY studentNameChanged)
    Q_PROPERTY(int studentId READ getStudentId NOTIFY studentIdChanged)
signals:
    void studentNameChanged();
    void studentIdChanged();
public:
    StudentController(std::shared_ptr<StudentModel> studentModel);
    void setStudentName(QString name);
    void setStudentId(int id);
    QString getStudentName();
    int getStudentId();
    void updateView();
private:
    std::shared_ptr<StudentModel> m_studentModel;
    StudentView m_studentView;
};

#endif
