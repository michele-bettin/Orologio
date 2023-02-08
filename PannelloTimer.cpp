#include "PannelloTimer.h"
#include "TimerWidget.h"

PannelloTimer::PannelloTimer(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setObjectName("pannello-timer");

    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setSpacing(0);
    frameLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);

    //titolo
    titolo = new QLabel("Timer");
    titolo -> setAlignment(Qt::AlignCenter);
    titolo -> setObjectName("titolo");
    frameLayout -> addWidget(titolo);

    mostraStandardTimer();

    layout -> addWidget(frame);

    //oggetti per la realizzione dei bottoni per la creazione e eliminazione dei timer custom
    frameBottoni = new QFrame(frame);
    layout -> addWidget(frameBottoni);
    layout -> setAlignment(frameBottoni, Qt::AlignBottom | Qt::AlignRight);

    frameBottoniLayout = new QHBoxLayout(frameBottoni);
    frameBottoniLayout -> setContentsMargins(0, 0, 0, 0);
    frameBottoniLayout -> setSpacing(0);

    bottoneModifica = new BottoneIcona("edit");
    bottoneModifica -> setDisabled(true);
    bottoneModifica -> setCursor(Qt::PointingHandCursor);
    frameBottoniLayout -> addWidget(bottoneModifica);

    bottoneAggiungi = new BottoneIcona("add");
    bottoneAggiungi -> setCursor(Qt::PointingHandCursor);
    frameBottoniLayout -> addWidget(bottoneAggiungi);
}

void PannelloTimer::mostraStandardTimer()
{
    QScrollArea *scrollStandardTimer = new QScrollArea();
    scrollStandardTimer -> setObjectName("scroll-standard-timer");
    scrollStandardTimer -> setContentsMargins(0, 0, 0, 0);
    scrollStandardTimer -> setWidgetResizable(true);
    scrollStandardTimer -> setFixedHeight(220);
    scrollStandardTimer -> setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollStandardTimer -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QFrame *frameStandardTimer = new QFrame(scrollStandardTimer);
    frameStandardTimer -> setObjectName("frame-standard-timer");
    scrollStandardTimer -> setWidget(frameStandardTimer);

    QHBoxLayout *frameStandardTimerLayout = new QHBoxLayout(frameStandardTimer);
    frameStandardTimerLayout -> setContentsMargins(50, 0, 50, 0);
    frameStandardTimerLayout -> setAlignment(Qt::AlignTop | Qt::AlignLeft);
    frameStandardTimerLayout -> setSpacing(50);

    TimerWidget *treMinuti = new TimerWidget("3 min", 0, 0, 3, frameStandardTimer);
    frameStandardTimerLayout -> addWidget(treMinuti);

    TimerWidget *cinqueMinuti = new TimerWidget("5 min", 0, 5, 0, frameStandardTimer);
    frameStandardTimerLayout -> addWidget(cinqueMinuti);

    TimerWidget *dieciMinuti = new TimerWidget("10 min", 0, 10, 0, frameStandardTimer);
    frameStandardTimerLayout -> addWidget(dieciMinuti);

    TimerWidget *quindiciMinuti = new TimerWidget("15 min", 0, 15, 0, frameStandardTimer);
    frameStandardTimerLayout -> addWidget(quindiciMinuti);

    frameLayout -> addWidget(scrollStandardTimer);
    frameLayout -> setAlignment(scrollStandardTimer, Qt::AlignTop);
}
