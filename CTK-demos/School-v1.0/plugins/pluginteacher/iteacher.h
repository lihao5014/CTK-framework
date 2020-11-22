#ifndef ITEACHER_H
#define ITEACHER_H

#include <QString>
#include <QtPlugin>

class ITeacher
{
public:
    virtual ~ITeacher(){}

    virtual void setName(const QString& name) = 0;
    virtual QString getName()const = 0;

    virtual void setWord(const QString& word) = 0;
    virtual QString getWord()const = 0;

    virtual void display()const = 0;
};

#define ITeacher_iid "plugin.teacher.ITeacher_iid"
Q_DECLARE_INTERFACE(ITeacher,ITeacher_iid)

#endif // ITEACHER_H
