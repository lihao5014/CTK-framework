#ifndef STUDENT_H
#define STUDENT_H

#include "istudent.h"
#include <QObject>
#include <service/event/ctkEventHandler.h>

class Student:public QObject,public IStudent,public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(IStudent)
    Q_INTERFACES(ctkEventHandler)
public:
    Student(const QString& name,const QString& note);

    void setName(const QString& name);
    virtual QString getName()const;

    void setNote(const QString& note);
    QString getNote()const override;

    virtual void show()const final;
    void handleEvent(const ctkEvent& event)override;

public slots:
    void update(const ctkEvent& event);

private:
    Student(const Student& other){}
    Student& operator =(const Student& other){}

    QString name;
    QString note;
};

#endif // STUDENT_H
