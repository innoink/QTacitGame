QTACITGAME_ROOT = $$PWD

QTACITGAME_BIN = $$QTACITGAME_ROOT/bin

QTACITGAME_COMMON = $$QTACITGAME_ROOT/common

QTACITGAME_OBJ_COMMON = $$QTACITGAME_ROOT/obj_common

QTACITGAME_OBJ_CLIENT = $$QTACITGAME_ROOT/obj_client

QTACITGAME_MOC_CLIENT = $$QTACITGAME_ROOT/moc_client

QTACITGAME_OBJ_SERVER = $$QTACITGAME_ROOT/obj_server

QTACITGAME_MOC_SERVER = $$QTACITGAME_ROOT/moc_server

DESTDIR = $$QTACITGAME_BIN

CONFIG += c++14

QMAKE_CXXFLAGS += -std=c++14 -g -O0 --coverage -fno-inline -fno-inline-small-functions -fno-default-inline -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings \
                    -Wredundant-decls -Wno-long-long -Wuninitialized

LIBS += --coverage