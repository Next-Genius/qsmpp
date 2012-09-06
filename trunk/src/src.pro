TEMPLATE = lib

QT -= gui
QT += core network

VERSION = 1.0.0

TARGET = qsmpp

CONFIG(debug, debug|release) {
  TARGET = $$join(TARGET,,d)
  OBJECTS_DIR = $${OUT_PWD}/tmp/obj/debug
  MOC_DIR = $${OUT_PWD}/tmp/moc/debug
} else {
  OBJECTS_DIR = $${OUT_PWD}/tmp/obj/release
  MOC_DIR = $${OUT_PWD}/tmp/moc/release
}

PRECOMPILED_HEADER  = global.h

INCLUDEPATH += $$PWD

DEFINES += QSMPP_LIBRARY QSMPP_VERSION=\\\"$$QSMPP_VERSION\\\"

win32: DLLDESTDIR = ../lib

HEADERS += \
    global.h \
    header.h

SOURCES += \
    header.cpp
