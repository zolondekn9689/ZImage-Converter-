QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ImageFactory/Threads/jpgdirectorythread.cpp \
    ImageFactory/Threads/pngdirectorythread.cpp \
    ImageFactory/Threads/tifdirectorybuilder.cpp \
    ImageFactory/abstractimage.cpp \
    ImageFactory/imagefactory.cpp \
    ImageFactory/jpgimage.cpp \
    ImageFactory/pngimage.cpp \
    ImageFactory/tifimage.cpp \
    main.cpp \
    mainwindow.cpp \
    prefdialog.cpp

HEADERS += \
    ImageFactory/Threads/jpgdirectorythread.h \
    ImageFactory/Threads/pngdirectorythread.h \
    ImageFactory/Threads/tifdirectorybuilder.h \
    ImageFactory/abstractimage.h \
    ImageFactory/imagefactory.h \
    ImageFactory/jpgimage.h \
    ImageFactory/pngimage.h \
    ImageFactory/tifimage.h \
    mainwindow.h \
    prefdialog.h

FORMS += \
    mainwindow.ui \
    prefdialog.ui

TRANSLATIONS += \
    ZConverter_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
