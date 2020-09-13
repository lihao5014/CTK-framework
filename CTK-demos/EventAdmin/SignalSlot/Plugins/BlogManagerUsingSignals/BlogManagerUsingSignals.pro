QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = BlogManagerUsingSignals
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../../PluginFramework.pri)

HEADERS += \
    blog_manager_using_signals.h \
    blog_manager_using_signals_activator.h

SOURCES += \
    blog_manager_using_signals.cpp \
    blog_manager_using_signals_activator.cpp

RESOURCES += Resource.qrc
