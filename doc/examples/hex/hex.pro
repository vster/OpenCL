TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../hex.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../.. -lopencl
