QT += core gui widgets

TARGET = QTacitGameClient
TEMPLATE = app

include (../QTacitGame.pri)

LIBS += -L$$QTACITGAME_BIN
LIBS += -lQTacitGame

INCLUDEPATH += $$QTACITGAME_COMMON

OBJECTS_DIR = $$QTACITGAME_OBJ_CLIENT
MOC_DIR= $$QTACITGAME_MOC_CLIENT

SOURCES += main.cpp \
    mainwindow.cpp

HEADERS  += \ 
    mainwindow.hpp 
