TEMPLATE = lib

QT -= gui
QT += core network

#VERSION = 1.0.0

CONFIG(debug, debug|release) {
  TARGET = qsmppd
  OBJECTS_DIR = $${OUT_PWD}/tmp/obj/debug
  MOC_DIR = $${OUT_PWD}/tmp/moc/debug
} else {
  TARGET = qsmpp
  OBJECTS_DIR = $${OUT_PWD}/tmp/obj/release
  MOC_DIR = $${OUT_PWD}/tmp/moc/release
}

PRECOMPILED_HEADER  = global.h

INCLUDEPATH += $$PWD

DEFINES += SMPP_LIBRARY SMPP_VERSION=\\\"$$SMPP_VERSION\\\"

win32: DLLDESTDIR = ../lib

HEADERS += \
    global.h \
    header.h \
    constants.h \
    tlv.h \
    outbind.h \
    submit_sm.h \
    submit_sm_resp.h \
    data_sm.h \
    data_sm_resp.h \
    submit_multi.h \
    submit_multi_resp.h \
    deliver_sm.h \
    deliver_sm_resp.h \
    broadcast_sm.h \
    broadcast_sm_resp.h \
    cancel_sm.h \
    query_sm.h \
    query_sm_resp.h \
    replace_sm.h \
    query_broadcast_sm.h \
    query_broadcast_sm_resp.h \
    cancel_broadcast_sm.h \
    standart_parameters.h \
    types.h \
    command_length.h \
    command_id.h \
    command_status.h \
    sequence_number.h \
    data_functions.h \
    bind_receiver.h \
    bind_receiver_resp.h \
    bind_transceiver.h \
    bind_transceiver_resp.h

SOURCES += \
    header.cpp \
    tlv.cpp \
    outbind.cpp \
    submit_sm.cpp \
    submit_sm_resp.cpp \
    data_sm.cpp \
    data_sm_resp.cpp \
    submit_multi.cpp \
    submit_multi_resp.cpp \
    deliver_sm.cpp \
    deliver_sm_resp.cpp \
    broadcast_sm_resp.cpp \
    broadcast_sm.cpp \
    cancel_sm.cpp \
    query_sm.cpp \
    query_sm_resp.cpp \
    replace_sm.cpp \
    query_broadcast_sm.cpp \
    query_broadcast_sm_resp.cpp \
    bind_receiver.cpp \
    bind_receiver_resp.cpp \
    bind_transceiver.cpp \
    bind_transceiver_resp.cpp
