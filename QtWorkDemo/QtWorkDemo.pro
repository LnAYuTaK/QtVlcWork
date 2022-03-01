#-------------------------------------------------
#
# Project created by QtCreator 2022-02-27T19:52:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtWorkDemo
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

CONFIG += c++11

SOURCES += \
    main.cpp \
    Vlc/vlcthread.cpp \
    MainWidget/widget.cpp \
    Vlc/vlcwidget.cpp \
    SlidePage/slidepage.cpp \
    ToolClass/lktools.cpp

HEADERS += \
    Vlc/vlcthread.h \
    Vlc/include/vlc.h \
    Vlc/include/libvlc_vlm.h \
    Vlc/include/libvlc_version.h \
    Vlc/include/libvlc_renderer_discoverer.h \
    Vlc/include/libvlc_media_player.h \
    Vlc/include/libvlc_media_list_player.h \
    Vlc/include/libvlc_media_list.h \
    Vlc/include/libvlc_media_library.h \
    Vlc/include/libvlc_media_discoverer.h \
    Vlc/include/libvlc_media.h \
    Vlc/include/libvlc_events.h \
    Vlc/include/libvlc_dialog.h \
    Vlc/include/libvlc.h \
    Vlc/include/deprecated.h \
    MainWidget/widget.h \
    Vlc/vlcwidget.h \
    SlidePage/slidepage.h \
    ToolClass/lktools.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    QtWorkDemo.pro

unix:!macx: LIBS += -L$$PWD/Vlc/lib/ -lvlccore

INCLUDEPATH += $$PWD/Vlc/include
DEPENDPATH += $$PWD/Vlc/include

unix:!macx: LIBS += -L$$PWD/Vlc/lib/ -lvlc

INCLUDEPATH += $$PWD/Vlc/lib
DEPENDPATH += $$PWD/Vlc/lib

RESOURCES += \
    image.qrc
