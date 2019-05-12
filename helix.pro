TEMPLATE = app

DEFINES     += GIT_VERS=\\\"$$system(git describe --always)\\\"
#DEFINES     += GIT_VERS=\\\"-------\\\"

CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        helix.cpp \
        main.cpp

HEADERS += \
    helix.h
