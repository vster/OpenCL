TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../blowfish-main.cpp

INCLUDEPATH += \
    ../../include

LIBS += \
    -L../.. -lopencl
