#-------------------------------------------------
#
# Project created by QtCreator 2018-04-23T18:49:22
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gallery-Desktop
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
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
    albumlistwidget.cpp \
    thumbnailproxymodel.cpp \
    albumwidget.cpp \
    picturedelegate.cpp \
    picturewidget.cpp \
    gallerywidget.cpp

HEADERS += \
        mainwindow.h \
    albumlistwidget.h \
    thumbnailproxymodel.h \
    albumwidget.h \
    picturedelegate.h \
    picturewidget.h \
    gallerywidget.h

FORMS += \
        mainwindow.ui \
    albumlistwidget.ui \
    albumwidget.ui \
    picturewidget.ui \
    gallerywidget.ui

RESOURCES += resources.qrc


LIBS += ./../../build-Gallery-Desktop_Qt_5_10_1_GCC_64bit-Debug/Gallery-Core/Gallery-Core -lgallery-core


INCLUDEPATH += $$PWD/../gallery-core
DEPENDPATH += $$PWD/../gallery-gore

RESOURCES += \
    resources.qrc

