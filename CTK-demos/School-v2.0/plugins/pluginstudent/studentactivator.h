#ifndef STUDENTACTIVATOR_H
#define STUDENTACTIVATOR_H

#include <QObject>
#include <ctkPluginActivator.h>

class Student;

class StudentActivator : public QObject,public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "PLUGIN_STUDENT")
public:
    void start(ctkPluginContext *context);
    void stop(ctkPluginContext *context);
private:
    Student *pstudent;
};

#endif // STUDENTACTIVATOR_H
