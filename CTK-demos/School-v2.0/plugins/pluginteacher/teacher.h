#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <ctkDictionary.h>
#include "iteacher.h"

class ctkPluginContext;

class Teacher : public QObject,public ITeacher
{
    Q_OBJECT
    Q_INTERFACES(ITeacher)
public:
    Teacher(ctkPluginContext *context);

    void setName(const QString& name);
    virtual QString getName()const;

    void setWord(const QString& word)final;
    QString getWord()const override;

    virtual void message()override;
    virtual void notify()const;
    virtual void display()const override;

signals:
    void signalMessage(const ctkDictionary& prop);

private:
    Teacher(const Teacher& other);
    Teacher& operator =(const Teacher& other);

    ctkPluginContext* context;
    QString name;
    QString word;
};

#endif // TEACHER_H
