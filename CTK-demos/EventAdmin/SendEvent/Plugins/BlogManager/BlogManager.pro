QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = BlogManager
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../../PluginFramework.pri)

HEADERS += \
    blog_manager.h \
    blog_manager_activator.h


SOURCES += \
    blog_manager.cpp \
    blog_manager_activator.cpp

RESOURCES += Resource.qrc
