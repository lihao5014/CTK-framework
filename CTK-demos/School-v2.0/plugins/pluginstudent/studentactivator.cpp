#include "studentactivator.h"
#include "student.h"
#include <service/event/ctkEventAdmin.h>
#include <service/event/ctkEventConstants.h>

void StudentActivator::start(ctkPluginContext *context)
{
    pstudent = new Student("none","none");
    context->registerService<IStudent>(pstudent);

    ctkDictionary prop;
    prop[ctkEventConstants::EVENT_TOPIC] = "school/teacher/notify";
    context->registerService<ctkEventHandler>(pstudent,prop);

    prop[ctkEventConstants::EVENT_TOPIC] = "school/teacher/message";
    ctkServiceReference eventAdminRef = context->getServiceReference<ctkEventAdmin>();
    if(eventAdminRef)
    {
        ctkEventAdmin *eventAdmin = qobject_cast<ctkEventAdmin*>(context->getService(eventAdminRef));
        eventAdmin->subscribeSlot(pstudent,SLOT(update(const ctkEvent&)),prop,Qt::DirectConnection);
    }
}

void StudentActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context);
    delete  pstudent;
}
