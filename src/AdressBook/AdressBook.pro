#-------------------------------------------------
#
# Project created by QtCreator 2014-12-09T13:12:46
#
#-------------------------------------------------

QT       += core
QT       += gui
QT       += widgets

TARGET = AdressBook
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Widgets/contactwidget.cpp \
    Data/contact.cpp \
    Widgets/contactlistwidgetitem.cpp \
    Model/csvcontactserializer.cpp \
    Model/contactserializer.cpp \
    Model/adressbook.cpp \
    Widgets/adressbookwidget.cpp \
    Data/user.cpp

HEADERS += \
    Widgets/contactwidget.h \
    Data/contact.h \
    Widgets/contactlistwidgetitem.h \
    Model/csvcontactserializer.h \
    Model/contactserializer.h \
    Model/adressbook.h \
    Widgets/adressbookwidget.h \
    Data/user.h
