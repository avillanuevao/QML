#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include <QString>

class StudentModel
{
public:
    StudentModel();
    void setName(QString name);
    void setId(int id);
    QString getName();
    int getId();
private:
    QString m_name;
    int m_id;
};

#endif
