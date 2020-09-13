QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = Hello
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../PluginFramework.pri)

HEADERS += \
    hello_service.h \
    hello_impl.h \
    hello_activator.h \
    service_factory.h

RESOURCES += Resource.qrc
