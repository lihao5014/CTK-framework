QT += core

TEMPLATE = app
CONFIG += console
TARGET = App
DESTDIR = $$PWD/../bin

include($$PWD/../../../../PluginFramework.pri)

SOURCES += \
    main.cpp
