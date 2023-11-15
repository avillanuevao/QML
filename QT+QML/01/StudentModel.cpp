#include "StudentModel.hpp"

StudentModel::StudentModel()
{

}

void StudentModel::setName(QString name)
{
    m_name = name;
}

void StudentModel::setId(int id)
{
    m_id = id;
}

QString StudentModel::getName()
{
    return m_name;
}

int StudentModel::getId()
{
    return m_id;
}
