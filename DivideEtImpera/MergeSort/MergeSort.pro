#-------------------------------------------------
#
# Project created by QtCreator 2011-08-12T09:52:30
#
#-------------------------------------------------

QT       -= core gui

TARGET = MergeSort
TEMPLATE = lib

DEFINES += MERGESORT_LIBRARY

SOURCES +=

HEADERS += mergesort.h\
        MergeSort_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEC0AAB12
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = MergeSort.dll
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
