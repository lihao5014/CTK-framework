#include "teacheractivator.h"
#include "teacher.h"

void TeacherActivator::start(ctkPluginContext *context)
{
    pteacher = new Teacher("none","none");
    context->registerService<ITeacher>(pteacher);
}

void TeacherActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context);
    delete pteacher;
}
