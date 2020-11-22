QT += core

TARGET = pluginteacher
TEMPLATE = lib
CONFIG += plugin c++11
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../pluginframework.pri)

HEADERS +=  \
	iteacher.h  \
	teacher.h  \
        teacheractivator.h

SOURCES +=  \
	teacher.cpp \
        teacheractivator.cpp

RESOURCES +=  \
        resource.qrc
