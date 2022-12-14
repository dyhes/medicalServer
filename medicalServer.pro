#-------------------------------------------------
#
# Project created by QtCreator 2022-08-20T11:35:13
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network sql printsupport charts

TARGET = medicalServer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mtcpserver.cpp \
    mthread.cpp \
    mdataframe.cpp \
    msqlservice.cpp \
    patient.cpp \
    waveblock.cpp\
    form.cpp \
    patientinfo.cpp \
    table.cpp \
    datachart.cpp \
    analysisdraw.cpp \
    analysisreport.cpp

HEADERS += \
        mainwindow.h \
    mtcpserver.h \
    helper.h \
    mthread.h \
    mdataframe.h \
    msqlservice.h \
    patient.h \
    waveblock.h\
    form.h \
    patientinfo.h \
    table.h \
    datachart.h \
    analysisdraw.h \
    analysisreport.h

FORMS += \
        mainwindow.ui \
    form.ui \
    patientinfo.ui \
    table.ui \
    analysisreport.ui \
    datachart.ui
