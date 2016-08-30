QT -= gui widgets
CONFIG -= QT

TARGET = QTacitGame
TEMPLATE = lib

include (../QTacitGame.pri)

INCLUDEPATH += ..

OBJECTS_DIR = $$QTACITGAME_OBJ_COMMON
MOC_DIR= $$QTACITGAME_MOC_COMMON

SOURCES += \ 
    ../externals/json.cc \
    gamemap.cpp \
    gamemapbuilder.cpp \
    bid.cpp \
    gamestate.cpp

HEADERS  += \ 
    ../externals/json.h \
    gamemap.hpp \
    gamemapbuilder.hpp \
    utils/json_helper.hpp \
    bid.hpp \
    gamestate.hpp
