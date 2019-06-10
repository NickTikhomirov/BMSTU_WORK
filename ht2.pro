#-------------------------------------------------
#
# Project created by QtCreator 2019-05-16T23:08:02
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ht2
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

CONFIG += c++17
HEADERS += \
        CursorManager.h \
        Generators/DateGenerator.h \
        Generators/NameGenerator.h \
        Generators/Randomizer.h \
        Graphics/AdditionalWindow.h \
        Graphics/CustomButton.h \
        Graphics/TextButton.h \
        Graphics/TutorialPage.h \
        Graphics/VisitorFace.h \
        Logic/ItemLockable.h \
        Logic/Level.h \
        Logic/Mistakes.h \
        Logic/Visitor.h \
        MyPlayer.h \
        Resizer.h \
        SimpleButton.h \
        SwitchingButton.h \
        TwinButtons.h \
        VeryComplicatedButton.h \
        Windows/AdditionalWindow.h \
        Windows/Game.h \
        Windows/SubWindow.h \
        Windows/WindowManager.h


SOURCES += \
        CursorManager.cpp \
        Generators/DateGenerator.cpp \
        Generators/NameGenerator.cpp \
        Generators/Randomizer.cpp \
        Graphics/CustomButton.cpp \
        Graphics/TextButton.cpp \
        Graphics/TutorialPage.cpp \
        Graphics/VisitorFace.cpp \
        Logic/ItemLockable.cpp \
        Logic/Level.cpp \
        Logic/Mistakes.cpp \
        Logic/Visitor.cpp \
        MyPlayer.cpp \
        Resizer.cpp \
        SimpleButton.cpp \
        SwitchingButton.cpp \
        VeryComplicatedButton.cpp \
        Windows/AdditionalWindow.cpp \
        Windows/Game.cpp \
        Windows/SubWindow.cpp \
        Windows/WindowManager.cpp \
        main.cpp \
        twinbuttons.cpp

#FORMS += \
#        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    fon1.png \
    ht2.pro.user

RESOURCES += \
    backgrounds.qrc \
    buttons.qrc \
    sources.qrc