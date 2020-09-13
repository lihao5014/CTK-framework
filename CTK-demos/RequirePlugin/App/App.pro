QT += core
QT -= gui

TARGET = RequirePlugin
CONFIG += console c++11
TEMPLATE = app
DESTDIR = $$PWD/../bin

include($$PWD/../../../PluginFramework.pri)

SOURCES += main.cpp
