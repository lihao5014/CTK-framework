QT += core

TEMPLATE = lib
TARGET = PluginHelloCTK
CONFIG += plugin
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../PluginFramework.pri)

HEADERS += hello_activator.h \
           hello_impl.h \
           hello_service.h

SOURCES += hello_activator.cpp \
           hello_impl.cpp

RESOURCES += Resource.qrc
