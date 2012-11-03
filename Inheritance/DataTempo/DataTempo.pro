#-------------------------------------------------
#
# Project created by QtCreator 2011-08-12T13:30:02
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = DataTempo
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    datatempo.cpp \
    ../../Modularity/Data/data.cpp \
    ../../Modularity/Tempo/tempo.cpp

HEADERS += \
    datatempo.h \
    ../../Modularity/Data/data.h \
    ../../Modularity/Tempo/tempo.h
