QT -= gui widgets
CONFIG -= QT

TARGET = tests
TEMPLATE = app

include (../QTacitGame.pri)
include (../gtest.pri)
#include (../gmock.pri)

INCLUDEPATH += ..

LIBS += -L$$QTACITGAME_BIN
LIBS += -lQTacitGame

INCLUDEPATH += $$QTACITGAME_COMMON

OBJECTS_DIR = $$QTACITGAME_OBJ_TESTS
MOC_DIR= $$QTACITGAME_MOC_TESTS

SOURCES += main.cpp \
    testgamemap.cpp \
    testgamemapbuilder.cpp \
    testbid.cpp \
    testgamestate.cpp

HEADERS +=
