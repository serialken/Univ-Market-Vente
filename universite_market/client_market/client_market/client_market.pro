#-------------------------------------------------
#
# Project created by QtCreator  11-06-20T10:30:52
#
#-------------------------------------------------

QT       += core gui network sql

TARGET = client_market
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    verif.cpp \
    societe.cpp \
    notes.cpp \
    contacts.cpp

HEADERS  += mainwindow.h \
    database.h \
    societe.h \
    notes.h \
    contacts.h

FORMS    += mainwindow.ui

RESOURCES += \
    ../imgs/srcs.qrc
