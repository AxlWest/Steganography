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
    ExtractWindow.cpp \
    LSB.cpp \
    ImageFile.cpp \
    Bitmap.cpp \
    LSB_1_2_3.cpp \
    LSB_1_3_4.cpp \
    LSB_1_0_0.cpp \
    LSB_2_0_0.cpp \
    LSB_3_0_0.cpp

HEADERS  += MainWindow.h \
    SteganographyWindow.h \
    ExtractWindow.h \
    LSB.h \
    ImageFile.h \
    Bitmap.h \
    LSB_1_2_3.h \
    LSB_1_3_4.h \
    LSB_1_0_0.h \
    LSB_2_0_0.h \
    LSB_3_0_0.h

FORMS    += MainWindow.ui \
    SteganographyWindow.ui \
    ExtractWindow.ui
