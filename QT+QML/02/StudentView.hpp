#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H
#include <QString>
#include <QDebug>

class StudentView
{
public:
    StudentView();
    void printStudentDetails(const QString &studentName, const int &studentId);
};

#endif
