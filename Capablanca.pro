#-------------------------------------------------
#
# Project created by QtCreator 2014-07-06T15:44:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Capablanca
TEMPLATE = app


SOURCES += main.cpp\
        startwindow.cpp \
    aboutwindow.cpp \
    team.cpp \
    blockparty.cpp \
    ringitup.cpp \
    match.cpp \
    alertwindow.cpp \
    alliance.cpp \
    score.cpp \
    blockpartylogic.cpp \
    hoverrepaint.cpp

HEADERS  += startwindow.h \
    aboutwindow.h \
    team.h \
    blockparty.h \
    ringitup.h \
    match.h \
    alertwindow.h \
    alliance.h \
    score.h \
    blockpartylogic.h \
    hoverrepaint.h

FORMS    += startwindow.ui \
    aboutwindow.ui \
    blockparty.ui \
    ringitup.ui \
    alertwindow.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    default_settings.txt \
    build_info.txt \
    team_name_database.txt
