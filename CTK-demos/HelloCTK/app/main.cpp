#include <QCoreApplication>
#include <QDebug>

#include "ctkPluginFramework.h"
#include "ctkPluginFrameworkFactory.h"
#include "ctkPluginContext.h"
#include "ctkPluginException.h"

#include "../plugins/PluginHelloCTK/hello_service.h"

int main(int argc,char* argv[])
{
    QCoreApplication app(argc,argv);

    //启动插件框架
    ctkPluginFrameworkFactory frameworkFactory;       //创建插件框架工厂
    QSharedPointer<ctkPluginFramework> framework = frameworkFactory.getFramework();    //由插件框架工厂类，生产一个插件框架
    try {
        framework->init();       //初始化插件框架
        framework->start();      //启动插件框架
        qDebug()<<"plugin framework start ...";
    } catch (const ctkPluginException& e) {
        qDebug()<<"failed to start plugin framework: "<<e.what();
        return -1;
    }

    //获取插件上下文环境（即获取插件运行环境）
    ctkPluginContext* context = framework->getPluginContext();

    //安装插件
    QString pluginPath = QCoreApplication::applicationDirPath() + "/plugins";
    try {
        QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(pluginPath + "/PluginHelloCTK.dll"));     //向插件运行环境中安装插件
        plugin->start();
        plugin->getHeaders();
        qDebug()<<"plugin PluginHelloCTK.dll start succeed ...";
    } catch (const ctkPluginException& e) {
        qDebug()<<"failed to install plugin PluginHelloCTK.dll: "<<e.what();
        return -1;
    }

    //获取插件提供的服务
    ctkServiceReference helloserviceRef = context->getServiceReference<HelloService>();
    if(helloserviceRef)
    {
        HelloService* helloservice = qobject_cast<HelloService*>(context->getService(helloserviceRef));
        if(helloservice != nullptr)
        {
            helloservice->sayHello();
        }
    }

    return app.exec();
}
