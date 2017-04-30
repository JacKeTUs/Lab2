QT += core
QT -= gui

TARGET = test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \ 
    ../queue.cpp

HEADERS += \
    ../queue.h