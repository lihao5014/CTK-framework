QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin c++11
TARGET = PluginB
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../PluginFramework.pri)

HEADERS += \
    plugin_b_service.h \
    plugin_b_impl.h \
    plugin_b_activator.h

SOURCES += \
    plugin_b_impl.cpp \
    plugin_b_activator.cpp

RESOURCES += Resource.qrc
