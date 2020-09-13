QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin c++11
TARGET = PluginA
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../PluginFramework.pri)

HEADERS += \
    plugin_a_service.h \
    plugin_a_impl.h \
    plugin_a_activator.h

SOURCES += \
    plugin_a_impl.cpp \
    plugin_a_activator.cpp

RESOURCES += Resource.qrc
