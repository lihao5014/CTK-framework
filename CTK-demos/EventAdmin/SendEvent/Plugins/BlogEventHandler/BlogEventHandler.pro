QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = BlogEventHandler
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../../PluginFramework.pri)

HEADERS += \
    blog_event_handler.h \
    blog_event_handler_activator.h

SOURCES += \
    blog_event_handler_activator.cpp

RESOURCES += Resource.qrc
