TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../hasher.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../.. -lopencl
