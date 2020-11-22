#include <QCoreApplication>
#include <QDebug>

#include <ctkPluginFramework.h>
#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginContext.h>
#include <ctkPluginException.h>

#include "../plugins/pluginstudent/istudent.h"
#include "../plugins/pluginteacher/iteacher.h"

int main(int argc,char* argv[])
{
    QCoreApplication app(argc,argv);

    qDebug()<<"---main start---";
    //使用插件框架工厂，创建插件框架
    ctkPluginFrameworkFactory frameworkFactory;
    QSharedPointer<ctkPluginFramework> framework = frameworkFactory.getFramework();
    try {
        framework->init();       //初始化插件框架
        framework->start();      //启动插件框架
        qDebug()<<"CTK Plugin Framework start ...";
    } catch (const ctkPluginException& e) {
        qDebug()<<"Failed to initialize the plugin framework: "<<e.what();
        return -1;
    }

    //获取插件上下文（即插件运行环境）
    ctkPluginContext *pcontext = framework->getPluginContext();
    QSharedPointer<ctkPluginContext> context(pcontext);

    //启动事件管理插件
    QString eventAdminPath = QCoreApplication::applicationDirPath() + "/lib";
    try {
        QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(eventAdminPath + "/org_commontk_eventadmin.dll"));
        plugin->start();
        qDebug()<<"plugin org_commontk_eventadmin.dll start ...";
    } catch (const ctkPluginException& e) {
        qDebug()<<"failed to start org_commontk_eventadmin.dll: "<<e.what();
        return -1;
    }

    //启动pluginstudent.dll插件
    QString pluginsPath = QCoreApplication::applicationDirPath() + "/plugins";
    try {
        QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(pluginsPath + "/pluginstudent.dll"));
        plugin->start();
        qDebug()<<"pluginstudent start ...";
    } catch (const ctkPluginException& e) {
        qDebug()<<"failed to start pluginstudent.dll: "<<e.what();
        return -1;
    }

    //启动pluginteacher.dll插件
    try {
        QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(pluginsPath + "/pluginteacher.dll"));
        plugin->start();
        qDebug()<<"pluginteacher.dll start ...";
    } catch (const ctkPluginException& e) {
        qDebug()<<"failed to start pluginteacher.dll: "<<e.what();
        return -1;
    }

    //获取插件pluginstudent.dll提供的服务
    ctkServiceReference studentRef = context->getServiceReference<IStudent>();
    if(studentRef)
    {
        IStudent* pstudent = qobject_cast<IStudent*>(context->getService(studentRef));
        if(nullptr != pstudent)
        {
            pstudent->setName("Bob");
            pstudent->setNote("good good study day day up");
            pstudent->show();
        }
    }

    //获取插件pluginteacher.dll提供的服务
    ctkServiceReference teacherRef = context->getServiceReference<ITeacher>();
    if(teacherRef)
    {
        ITeacher *pteacher = qobject_cast<ITeacher*>(context->getService(teacherRef));
        if(nullptr != pteacher)
        {
            pteacher->setName("Kevin");
            pteacher->setWord("stand up");
            pteacher->display();
            pteacher->notify();

            pteacher->setName("mary");
            pteacher->setWord("go to classroom");
            pteacher->display();
            pteacher->message();
        }
    }

    qDebug()<<"---main end---";
    return app.exec();
}
