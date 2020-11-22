#include "student.h"
#include <QDebug>

Student::Student(const QString& name,const QString& note)
    :name(name)
    ,note(note)
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

void Student::handleEvent(const ctkEvent &event)
{
    QString author = event.getProperty("author").toString();
    QString word = event.getProperty("word").toString();

    note = word;
    qDebug()<<"student received message, author: "<<author<<" . word: "<<word;
}

void Student::update(const ctkEvent &event)
{
    note = event.getProperty("word").toString();
    QString author = event.getProperty("author").toString();
    qDebug()<<"student received signal, name: "<<author<<" . note: "<<note;
}
