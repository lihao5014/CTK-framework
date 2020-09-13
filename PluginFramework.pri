#使用CTK插件框架所必须需要包括的头文件路径和库。

INCLUDEPATH += $$PWD/Core \
               $$PWD/PluginFramework \
               $$PWD/PluginFramework/application \
               $$PWD/PluginFramework/cm \
               $$PWD/PluginFramework/datalocation \
               $$PWD/PluginFramework/debug \
               $$PWD/PluginFramework/event \
               $$PWD/PluginFramework/log \
               $$PWD/PluginFramework/metatype \
               $$PWD/org.commontk.eventadmin \
               $$PWD/org.commontk.eventadmin/adapter \
               $$PWD/org.commontk.eventadmin/dispatch \
               $$PWD/org.commontk.eventadmin/handler \
               $$PWD/org.commontk.eventadmin/tasks \
               $$PWD/org.commontk.eventadmin/util \

CONFIG(debug,debug|release){
    LIBS += -L$$PWD/lib  -lPluginCored
    LIBS += -L$$PWD/lib  -lPluginFrameworkd
#    LIBS += -L$$PWD/lib  -lorg_commontk_eventadmin
}else{
    LIBS += -L$$PWD/lib  -lPluginCore
    LIBS += -L$$PWD/lib  -lPluginFramework
#    LIBS += -L$$PWD/lib  -lorg_commontk_eventadmin
}
