QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ReplayGUIEvent.cpp \
    tst_testcase_Image.cpp \
    tst_testcase_MyTimer.cpp \
    tst_testcase_customView.cpp \
    tst_testcase_window.cpp
