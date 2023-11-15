#include "StudentView.hpp"

StudentView::StudentView()
{

}

void StudentView::printStudentDetails(const QString &studentName, const int &studentId)
{
    qDebug() << "Student Name: " << studentName << ", Student Id: " << studentId;
}
