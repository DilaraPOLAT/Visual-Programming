QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ders_islemleri.cpp \
    main.cpp \
    mainwindow.cpp \
    not_islemleri.cpp \
    ogrenci_islemleri.cpp

HEADERS += \
    ders_islemleri.h \
    mainwindow.h \
    not_islemleri.h \
    ogrenci_islemleri.h

FORMS += \
    ders_islemleri.ui \
    mainwindow.ui \
    not_islemleri.ui \
    ogrenci_islemleri.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
