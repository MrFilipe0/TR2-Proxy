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
    analises.cpp \
    requisicao_proxy.cpp \
    resposta_proxy.cpp \
    servidor_proxy.cpp \
    Spider.cpp \
    funcoes.cpp

HEADERS  += proxyui.h\
    requisicao_proxy.hpp \
    resposta_proxy.hpp \
    servidor_proxy.hpp \
    funcoes.hpp \
    Spider.hpp \
    analises.hpp

FORMS    += proxyui.ui