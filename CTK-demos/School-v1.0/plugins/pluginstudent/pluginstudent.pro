QT += core

TARGET = pluginstudent
TEMPLATE = lib
CONFIG += plugin c++11
DESTDIR = $$PWD/../../bin/plugins

include($$PWD/../../../../pluginframework.pri)

HEADERS +=  \
	istudent.h  \
	student.h  \
        studentactivator.h

SOURCES +=  \
	student.cpp \
        studentactivator.cpp

RESOURCES += \
    resouce.qrc
