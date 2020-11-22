#ifndef TEACHERACTIVATOR_H
#define TEACHERACTIVATOR_H

#include <QObject>
#include <ctkPluginActivator.h>

class Teacher;

class TeacherActivator : public QObject,public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "PLUGIN_TEACHER")
public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);
private:
    Teacher *pteacher;
};

#endif // TEACHERACTIVATOR_H
