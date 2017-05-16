TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../threeway-main.cpp

INCLUDEPATH += \
    ../../include

LIBS += \
    -L../.. -lopencl
