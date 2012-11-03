#-------------------------------------------------
#
# Project created by QtCreator 2011-08-12T17:12:12
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Collezione
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ../../Modularity/Data/data.cpp \
    ../../Modularity/Telefonata/telefonata.cpp \
    ../../Modularity/Tempo/tempo.cpp \
    ../../Inheritance/DataTempo/datatempo.cpp

HEADERS += \
    collezione.h \
    ../../Modularity/Data/data.h \
    ../../Modularity/Telefonata/telefonata.h \
    ../../Modularity/Tempo/tempo.h \
    ../../Inheritance/DataTempo/datatempo.h
