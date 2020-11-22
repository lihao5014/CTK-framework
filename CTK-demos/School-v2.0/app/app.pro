QT += core

TARGET = app
TEMPLATE = app
CONFIG += console c++11
DESTDIR = $$PWD/../bin

include($$PWD/../../../pluginframework.pri)

SOURCES += main.cpp
