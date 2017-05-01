TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../md5.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../.. -lopencl
