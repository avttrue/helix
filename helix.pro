TEMPLATE = app

DEFINES     += GIT_VERS=\\\"$$system(git describe --always)\\\"
#DEFINES     += GIT_VERS=\\\"-------\\\"

CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        func.cpp \
        helix.cpp \
        main.cpp

HEADERS += \
    func.h \
    helix.h
