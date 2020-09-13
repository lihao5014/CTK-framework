QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = Login
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../PluginFramework.pri)

HEADERS += \
    login_service.h \
    login_impl.h \
    login_activator.h \
    service_tracker.h

SOURCES += \
    login_impl.cpp \
    login_activator.cpp

RESOURCES += Resource.qrc
