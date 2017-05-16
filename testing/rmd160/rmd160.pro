TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../rmd160-main.cpp

INCLUDEPATH += \
    ../../include

LIBS += \
    -L../.. -lopencl
