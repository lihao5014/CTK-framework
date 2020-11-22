#include "teacher.h"
#include <QDebug>

Teacher::Teacher(const QString& name,const QString& word)
    :name(name)
    ,word(word)
{

}

Teacher::Teacher(const Teacher &other)
    :name(other.name)
    ,word(other.word)
{

}

void Teacher::setName(const QString& name)
{
    this->name = name;
}

QString Teacher::getName()const
{
    return name;
}

void Teacher::setWord(const QString& word)
{
    this->word = word;
}

QString Teacher::getWord()const
{
    return word;
}

void Teacher::display()const
{
    qDebug()<<"teacher name: "<<name<<" , word: "<<word;
}
