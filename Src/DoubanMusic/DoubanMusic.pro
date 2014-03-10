#-------------------------------------------------
#
# Project created by QtCreator 2014-02-20T00:50:55
#
#-------------------------------------------------
QT       += core gui
QT       += network
QT       += script
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DoubanMusic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    titlewidget.cpp \
    qiplaylabel.cpp \
    qititleclosebtn.cpp \
    qititlelablewidget.cpp \
    playcontrol.cpp \
    qilikewidget.cpp \
    qideletewidget.cpp \
    qinextwidget.cpp \
    requestchannelsobject.cpp \
    requestmusicsobject.cpp \
    domediaplayer.cpp \
    playpausetimewidget.cpp \
    playpausewidget.cpp

HEADERS  += mainwindow.h \
    titlewidget.h \
    qiplaylabel.h \
    qititleclosebtn.h \
    qititlelablewidget.h \
    playcontrol.h \
    qilikewidget.h \
    qideletewidget.h \
    qinextwidget.h \
    requestchannelsobject.h \
    requestmusicsobject.h \
    domediaplayer.h \
    playpausetimewidget.h \
    playpausewidget.h

FORMS    += mainwindow.ui \
    titlewidget.ui \
    playcontrol.ui \
    playpausetimewidget.ui

RESOURCES += \
    DoubanMusicRes.qrc
