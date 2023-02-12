#include "PannelloTimer.h"

PannelloTimer::PannelloTimer(QWidget *parent)
    : QWidget(parent)
{
    collezioneCustomTimer = ArrayList<TimerWidget*>();

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

    mostraCustomTimer();

    layout -> addWidget(frame);

    //oggetti per la realizzione dei bottoni per la creazione e eliminazione dei timer custom
    frameBottoni = new QFrame(frame);
    layout -> addWidget(frameBottoni);
    layout -> setAlignment(frameBottoni, Qt::AlignBottom | Qt::AlignRight);

    frameBottoniLayout = new QHBoxLayout(frameBottoni);
    frameBottoniLayout -> setContentsMargins(0, 0, 0, 0);
    frameBottoniLayout -> setSpacing(0);

    bottoneEliminazione = new BottoneIcona("delete");
    bottoneEliminazione -> setDisabled(true);
    bottoneEliminazione -> setCursor(Qt::PointingHandCursor);
    connect(bottoneEliminazione, &QPushButton::pressed, this, &PannelloTimer::eliminazioneCustomTimer);
    frameBottoniLayout -> addWidget(bottoneEliminazione);

    bottoneAggiungi = new BottoneIcona("add");
    bottoneAggiungi -> setCursor(Qt::PointingHandCursor);
    connect(bottoneAggiungi, &QPushButton::pressed, this, &PannelloTimer::aggiungiCustomTimer);
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

    TimerWidget *treMinuti = new TimerWidget("3 min", 0, 3, 0, frameStandardTimer);
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

void PannelloTimer::mostraCustomTimer()
{
    scrollCustomTimer = new QScrollArea();
    scrollCustomTimer -> setObjectName("scroll-custom-timer");
    scrollCustomTimer -> setContentsMargins(0, 0, 0, 0);
    scrollCustomTimer -> setWidgetResizable(true);
    scrollCustomTimer -> setFixedHeight(250);
    scrollCustomTimer -> setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollCustomTimer -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    frameCustomTimer = new QFrame(scrollCustomTimer);
    frameCustomTimer -> setObjectName("frame-custom-timer");
    scrollCustomTimer -> setWidget(frameCustomTimer);

    frameCustomTimerLayout = new QHBoxLayout(frameCustomTimer);
    frameCustomTimerLayout -> setContentsMargins(50, 50, 50, 0);
    frameCustomTimerLayout -> setAlignment(Qt::AlignTop | Qt::AlignLeft);
    frameCustomTimerLayout -> setSpacing(50);

    frameLayout -> addWidget(scrollCustomTimer);
    frameLayout -> setAlignment(scrollCustomTimer, Qt::AlignTop);
}

void PannelloTimer::aggiungiCustomTimer()
{
    int dimensioneInApertura = collezioneCustomTimer.GetDimensione();

    actd = new AggiungiCustomTimerDialog(&collezioneCustomTimer);
    actd -> setWindowTitle("Orologio - Aggiungi un nuovo timer");
    actd -> setModal(true);
    actd -> exec();

    //aggiungo il nuovo timer creato
    if (dimensioneInApertura < collezioneCustomTimer.GetDimensione())
    {
        frameCustomTimerLayout -> addWidget(*collezioneCustomTimer.Get(dimensioneInApertura));
    }

    //rendo cliccabile il bottone per la cancellazione dei timer aggiunti
    if (collezioneCustomTimer.GetDimensione() > 0)
    {
        bottoneEliminazione -> setDisabled(false);
    }
}

void PannelloTimer::eliminazioneCustomTimer()
{
    bottoneEliminazione -> setDisabled(true);

    //rimozione TimerWidget dal layout
    while (frameCustomTimerLayout -> count() > 0)
    {
        QLayoutItem *item = frameCustomTimerLayout -> takeAt(0);
        if (item -> widget())
        {
            delete item -> widget();
        }
        delete item;
    }

    //reset dell'array list
    collezioneCustomTimer.RimuoviTutti();
}
