#-------------------------------------------------
#
# Project created by QtCreator 2016-05-01T12:33:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Laundry
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    hoymefloors.cpp \
    hoymemachines.cpp \
    hoymemachines2.cpp \
    kittfloors.cpp \
    Worker.cpp \
    Socket.cpp \
    CLIENT.cpp

HEADERS  += mainwindow.h \
    hoymefloors.h \
    hoymemachines.h \
    hoymemachines2.h \
    kittfloors.h \
    Socket.h \
    Worker.h \
    CLIENT.h

FORMS    += mainwindow.ui \
    hoymefloors.ui \
    hoymemachines.ui \
    hoymemachines2.ui \
    kittfloors.ui
