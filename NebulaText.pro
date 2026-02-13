QT += core gui widgets

CONFIG += c++17
CONFIG += console
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    about.cpp

HEADERS += \
    mainwindow.h \
    about.h

TARGET = NebulaText
TEMPLATE = app
