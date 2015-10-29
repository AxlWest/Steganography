#-------------------------------------------------
#
# Project created by QtCreator 2015-10-26T21:07:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Steganography
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    SteganographyWindow.cpp \
    ExtractWindow.cpp

HEADERS  += MainWindow.h \
    SteganographyWindow.h \
    ExtractWindow.h

FORMS    += MainWindow.ui \
    SteganographyWindow.ui \
    ExtractWindow.ui
