#include "studentactivator.h"
#include "student.h"

void StudentActivator::start(ctkPluginContext *context)
{
    pstudent = new Student("none","none");
    context->registerService<IStudent>(pstudent);
}

void StudentActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context);
    delete  pstudent;
}
