#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include "iteacher.h"

class Teacher : public QObject,public ITeacher
{
    Q_OBJECT
    Q_INTERFACES(ITeacher)
public:
    Teacher(const QString& name,const QString& word);
    Teacher(const Teacher& other);

    void setName(const QString& name);
    virtual QString getName()const;

    void setWord(const QString& word)final;
    QString getWord()const override;

    virtual void display()const override;
private:
    QString name;
    QString word;
};

#endif // TEACHER_H
