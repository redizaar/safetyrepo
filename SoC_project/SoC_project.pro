TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    user.cpp \
    character.cpp \
    location.cpp \
    mob.cpp \
    game.cpp \
    warrior.cpp \
    mage.cpp \
    tank.cpp \
    priest.cpp \
    boss.cpp \
    charfactory.cpp

HEADERS += \
    user.h \
    character.h \
    location.h \
    mob.h \
    game.h \
    warrior.h \
    mage.h \
    tank.h \
    priest.h \
    boss.h \
    charfactory.h
