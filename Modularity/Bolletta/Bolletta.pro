#-------------------------------------------------
#
# Project created by QtCreator 2011-08-12T13:26:24
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Bolletta
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    bolletta.cpp \
    ../Data/data.cpp \
    ../Telefonata/telefonata.cpp \
    ../Tempo/tempo.cpp \
    ../../Inheritance/DataTempo/datatempo.cpp

HEADERS += \
    bolletta.h \
    ../Data/data.h \
    ../Telefonata/telefonata.h \
    ../Tempo/tempo.h \
    ../../Inheritance/DataTempo/datatempo.h
