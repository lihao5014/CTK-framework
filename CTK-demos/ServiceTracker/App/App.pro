QT += core
QT -= gui

TARGET = ServiceTracker
CONFIG += console
TEMPLATE = app
DESTDIR = $$PWD/../bin

include($$PWD/../../../PluginFramework.pri)

SOURCES += main.cpp
