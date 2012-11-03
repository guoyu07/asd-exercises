#-------------------------------------------------
#
# Project created by QtCreator 2011-08-12T09:51:56
#
#-------------------------------------------------

QT       -= core gui

TARGET = MinMax
TEMPLATE = lib

DEFINES += MINMAX_LIBRARY

SOURCES +=

HEADERS += minmax.h\
        MinMax_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEFCC4149
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = MinMax.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
