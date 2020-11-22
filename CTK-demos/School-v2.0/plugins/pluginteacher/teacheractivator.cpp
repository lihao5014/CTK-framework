#include "teacheractivator.h"
#include "teacher.h"

void TeacherActivator::start(ctkPluginContext *context)
{
    pteacher = new Teacher(context);
    context->registerService<ITeacher>(pteacher);
}

void TeacherActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context);
    delete pteacher;
}
