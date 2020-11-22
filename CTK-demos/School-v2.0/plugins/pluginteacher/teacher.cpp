#include "teacher.h"
#include <QDebug>
#include <ctkPluginContext.h>
#include <service/event/ctkEventAdmin.h>

Teacher::Teacher(ctkPluginContext *context)
    :context(context)
    ,name("none")
    ,word("none")
{
    ctkServiceReference eventAdminRef = context->getServiceReference<ctkEventAdmin>();
    if(eventAdminRef)
    {
        ctkEventAdmin *eventAdmin = qobject_cast<ctkEventAdmin*>(context->getService(eventAdminRef));
        eventAdmin->publishSignal(this,SIGNAL(signalMessage(const ctkDictionary&)),"school/teacher/message",Qt::DirectConnection);
    }
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

void Teacher::message()
{
    ctkDictionary prop;
    prop["author"] = name;
    prop["word"] = word;

    qDebug()<<"teacher send, word: "<<word<<" , author: "<<name;
    emit signalMessage(prop);
}

void Teacher::notify()const
{
    if(context != nullptr)
    {
        ctkServiceReference eventAdminRef = context->getServiceReference<ctkEventAdmin>();
        if(eventAdminRef)
        {
            ctkEventAdmin *eventAdmin = qobject_cast<ctkEventAdmin*>(context->getService(eventAdminRef));
            if(eventAdmin != nullptr)
            {
                ctkDictionary prop;
                prop["author"] = name;
                prop["word"] = word;

                qDebug()<<"teacher sent message, author: "<<name<<" , word: "<<word;
                ctkEvent event("school/teacher/notify",prop);
                eventAdmin->sendEvent(event);
            }
        }
    }
}

void Teacher::display()const
{
    qDebug()<<"teacher name: "<<name<<" , word: "<<word;
}
