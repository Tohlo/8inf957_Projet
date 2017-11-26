#-------------------------------------------------
#
# Project created by QtCreator 2017-10-04T00:49:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_POO
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
#CONFIG += console

include(qtxlsx/src/xlsx/qtxlsx.pri)

SOURCES += \
    src/data/typeArea.cpp \
    src/items/drop.cpp \
    src/items/equipment.cpp \
    src/items/ressource.cpp \
    src/items/skills.cpp \
    src/mobs/attack.cpp \
    src/mobs/buff.cpp \
    src/mobs/mob.cpp \
    src/map/map.cpp \
    src/map/group.cpp \
    src/map/cell.cpp \
    src/mobs/mobSkills.cpp \
    src/windows/attackForm.cpp \
    src/windows/mainwindow.cpp \
    src/windows/settingsDialog.cpp \
    src/main.cpp \
    src/windows/groupForm.cpp \
    src/windows/mainwindow_mobEditionSlots.cpp \
    src/windows/mainwindow_buttonsManageSlots.cpp

HEADERS += \
    inc/data/data.h \
    inc/data/singleton.h \
    inc/data/typeArea.h \
    inc/items/drop.h \
    inc/items/equipment.h \
    inc/items/ressource.h \
    inc/items/skills.h \
    inc/mobs/attack.h \
    inc/mobs/buff.h \
    inc/mobs/mob.h \
    inc/map/map.h \
    inc/map/group.h \
    inc/map/cell.h \
    inc/mobs/mobSkills.h \
    inc/serializer/serializable.h \
    inc/windows/attackForm.h \
    inc/windows/mainwindow.h \
    inc/windows/settingsDialog.h \
    inc/windows/groupForm.h

FORMS += \
    forms/attackForm.ui \
    forms/mainwindow.ui \
    forms/settingsDialog.ui \
    forms/groupForm.ui

RESOURCES += \
    icons.qrc

DISTFILES += \
    assets/icons/others/folder-search.png \
    assets/icons/skills/air.png \
    assets/icons/skills/ap.png \
    assets/icons/skills/ap_removal.png \
    assets/icons/skills/area_mastery.png \
    assets/icons/skills/armor.png \
    assets/icons/skills/block.png \
    assets/icons/skills/ch.png \
    assets/icons/skills/crit_mastery.png \
    assets/icons/skills/crit_resist.png \
    assets/icons/skills/damage_dealt.png \
    assets/icons/skills/distance_mastery.png \
    assets/icons/skills/dodge.png \
    assets/icons/skills/earth.png \
    assets/icons/skills/fire.png \
    assets/icons/skills/heals.png \
    assets/icons/skills/hp.png \
    assets/icons/skills/initiative.png \
    assets/icons/skills/lock.png \
    assets/icons/skills/mastery.png \
    assets/icons/skills/melee_mastery.png \
    assets/icons/skills/mp.png \
    assets/icons/skills/mp_removal.png \
    assets/icons/skills/prospecting.png \
    assets/icons/skills/range.png \
    assets/icons/skills/st_mastery.png \
    assets/icons/skills/water.png \
    assets/icons/skills/wisdom.png
