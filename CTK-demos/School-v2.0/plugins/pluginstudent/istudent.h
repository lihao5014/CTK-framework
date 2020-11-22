#ifndef ISTUDENT_H
#define ISTUDENT_H

#include <QString>
#include <QtPlugin>

class IStudent
{
public:
    virtual ~IStudent(){}

    virtual void setName(const QString& name) = 0;
    virtual QString getName()const = 0;

    virtual void setNote(const QString& note) = 0;
    virtual QString getNote()const = 0;

    virtual void show()const = 0;
};

#define ISTUDENT_iid "plugin.student.IStudent_iid"
Q_DECLARE_INTERFACE(IStudent,ISTUDENT_iid)

#endif // ISTUDENT_H
