QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Modelli/CallBackTimer.cpp \
    Modelli/Cronometro.cpp \
    Modelli/Data.cpp \
    Modelli/Orario.cpp \
    Modelli/Orologio.cpp \
    Modelli/Timer.cpp \
    Modelli/Sveglia.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Modelli/CallBackTimer.h \
    Modelli/Cronometro.h \
    Modelli/Data.h \
    MainWindow.h \
    Modelli/Orario.h \
    Modelli/Orologio.h \
    Modelli/Timer.h \
    Modelli/Sveglia.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
