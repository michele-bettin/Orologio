#include "PannelloCronometro.h"

PannelloCronometro::PannelloCronometro(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setObjectName("pannello-cronometro");

    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);

    //titolo pannello
    titolo = new QLabel("Cronometro");
    titolo -> setAlignment(Qt::AlignCenter);
    titolo -> setObjectName("titolo");
    frameLayout -> addWidget(titolo);

    //creazione cronometro
    cronometro = new Cronometro();
    cBT = new CallBackTimer();

    //label cronometro
    cronometroLabel = new QLabel();
    QFont font("Arial");
    cronometroLabel -> setFont(font);
    cronometroLabel -> setAlignment(Qt::AlignCenter);
    cronometroLabel -> setObjectName("cronometro");
    frameLayout -> addWidget(cronometroLabel);

    QTimer *t = new QTimer();
    connect(t, &QTimer::timeout, this, &PannelloCronometro::mostraCronometro);
    t -> start(1);
    mostraCronometro();

    //bottoni per la gestione del cronometro
    frameBottoni = new QFrame(frame);

    frameBottoniLayout = new QHBoxLayout(frameBottoni);
    frameBottoniLayout -> setContentsMargins(0, 0, 0, 0);
    frameBottoniLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);
    frameBottoniLayout -> setSpacing(20);

    bottonePlayPausa = new BottoneIcona("play", frameBottoni);
    bottonePlayPausa -> setCursor(Qt::PointingHandCursor);
    connect(bottonePlayPausa, &QPushButton::pressed, this, &PannelloCronometro::playPausaCronometro);
    frameBottoniLayout -> addWidget(bottonePlayPausa);

    bottoneAzzera = new BottoneIcona("stop", frameBottoni);
    bottoneAzzera -> setCursor(Qt::PointingHandCursor);
    connect(bottoneAzzera, &QPushButton::pressed, this, &PannelloCronometro::azzeraCronometro);
    frameBottoniLayout -> addWidget(bottoneAzzera);

    frameLayout -> addWidget(frameBottoni);

    layout -> addWidget(frame);
}

void PannelloCronometro::mostraCronometro()
{
    cronometroLabel -> setText(QString::fromStdString(cronometro -> ToString()));
}

void PannelloCronometro::playPausaCronometro()
{
    if (!staRiproducendo)
    {
        bottonePlayPausa -> setIcona("pause");
        staRiproducendo = !staRiproducendo;
        cronometro -> Avvia(*cBT);
    }
    else
    {
        bottonePlayPausa -> setIcona("play");
        staRiproducendo = !staRiproducendo;
        cronometro -> Ferma(*cBT);
    }
}

void PannelloCronometro::azzeraCronometro()
{
    bottonePlayPausa -> setIcona("play");
    staRiproducendo = false;
    cronometro -> Ferma(*cBT);
    cronometro -> Azzera();
}


