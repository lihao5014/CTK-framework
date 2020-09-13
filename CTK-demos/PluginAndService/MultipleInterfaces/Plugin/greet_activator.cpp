#include "greet_impl.h"
#include "greet_activator.h"

void GreetActivator::start(ctkPluginContext* context)
{
    m_pImpl = new GreetImpl();

    // 注册服务
    context->registerService<HelloService>(m_pImpl);     //向插件运行环境中注册HelloService服务，以便插件环境中的其他组件可以访问
    context->registerService<ByeService>(m_pImpl);       //向插件运行环境中注册ByeService接口，以便插件环境中的其他组件可以访问
}

void GreetActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)
    delete m_pImpl;
}
