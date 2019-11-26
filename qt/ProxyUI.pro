#-------------------------------------------------
#
# Project created by QtCreator 2019-11-24T19:21:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = aracne
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        proxyui.cpp\
    Parser.cpp \
    Request.cpp \
    Response.cpp \
    Servidor_proxy.cpp \
    Spider.cpp \
    Functions_aux.cpp

HEADERS  += proxyui.h\
    Request.hpp \
    Response.hpp \
    Servidor_proxy.hpp \
    Functions_aux.hpp \
    Spider.hpp \
    Parser.hpp

FORMS    += proxyui.ui