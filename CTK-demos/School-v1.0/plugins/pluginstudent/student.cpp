#include "student.h"
#include <QDebug>

Student::Student(const QString& name,const QString& note)
    :name(name)
    ,note(note)
{

}

Student::Student(const Student &other)
    :name(other.name)
    ,note(other.note)
{

}

void Student::setName(const QString& name)
{
    this->name = name;
}

QString Student::getName()const
{
    return name;
}

void Student::setNote(const QString& note)
{
    this->note = note;
}

QString Student::getNote()const
{
    return note;
}

void Student::show()const
{
    qDebug()<<"student name: "<<name<<" , note: "<<note;
}
