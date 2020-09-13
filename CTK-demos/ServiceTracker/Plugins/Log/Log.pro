QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = Log
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../PluginFramework.pri)

HEADERS += \
    log_service.h \
    log_impl.h \
    log_activator.h

SOURCES += \
    log_activator.cpp \
    log_impl.cpp

RESOURCES += Resource.qrc
