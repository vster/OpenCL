TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../rc5-main.cpp

INCLUDEPATH += \
    ../../include

LIBS += \
    -L../.. -lopencl
