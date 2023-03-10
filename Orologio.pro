QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AggiungiCustomTimerDialog.cpp \
    AggiungiSvegliaDialog.cpp \
    App.cpp \
    BottoneIcona.cpp \
    BottoneMenu.cpp \
    InfoDialog.cpp \
    Modelli/CallBackTimer.cpp \
    Modelli/Cronometro.cpp \
    Modelli/Data.cpp \
    Modelli/Orario.cpp \
    Modelli/Orologio.cpp \
    Modelli/Timer.cpp \
    Modelli/Sveglia.cpp \
    PannelloCronometro.cpp \
    PannelloImpostazioni.cpp \
    PannelloOrologio.cpp \
    PannelloSveglia.cpp \
    PannelloTimer.cpp \
    SvegliaWidget.cpp \
    TimerWidget.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    AggiungiCustomTimerDialog.h \
    AggiungiSvegliaDialog.h \
    App.h \
    BottoneIcona.h \
    BottoneMenu.h \
    Collezioni/ArrayList.h \
    InfoDialog.h \
    MainWindow.h \
    Modelli/CallBackTimer.h \
    Modelli/Cronometro.h \
    Modelli/Data.h \
    Modelli/Orario.h \
    Modelli/Orologio.h \
    Modelli/Timer.h \
    Modelli/Sveglia.h \
    PannelloCronometro.h \
    PannelloImpostazioni.h \
    PannelloOrologio.h \
    PannelloSveglia.h \
    PannelloTimer.h \
    Parser/MioParserJSON.h \
    SvegliaWidget.h \
    TimerWidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    risorse.qrc
