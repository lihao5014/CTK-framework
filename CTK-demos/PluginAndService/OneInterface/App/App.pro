QT += core gui widgets

TEMPLATE = app
CONFIG += console
TARGET = App
DESTDIR = $$PWD/../bin

include($$PWD/../../../../PluginFramework.pri)

SOURCES += \
    main.cpp
