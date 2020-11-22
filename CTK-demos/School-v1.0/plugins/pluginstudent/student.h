#ifndef STUDENT_H
#define STUDENT_H

#include "istudent.h"
#include <QObject>

class Student:public QObject,public IStudent
{
    Q_OBJECT
    Q_INTERFACES(IStudent)
public:
    Student(const QString& name,const QString& note);
    Student(const Student& other);

    void setName(const QString& name);
    virtual QString getName()const;

    void setNote(const QString& note);
    QString getNote()const override;

    virtual void show()const final;
private:
    QString name;
    QString note;
};

#endif // STUDENT_H
