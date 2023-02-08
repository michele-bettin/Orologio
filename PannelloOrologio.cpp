#include "PannelloOrologio.h"

PannelloOrologio::PannelloOrologio(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setObjectName("pannello-orologio");

    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);

    //titolo
    titolo = new QLabel("Orologio");
    titolo -> setAlignment(Qt::AlignCenter);
    titolo -> setObjectName("titolo");
    frameLayout -> addWidget(titolo);

    //oggetti per la rappresentazione dell'orologio
    frameOrologio = new QFrame(frame);
    frameLayout -> addWidget(frameOrologio);

    frameOrologioLayout = new QVBoxLayout(frameOrologio);
    frameOrologioLayout -> setContentsMargins(0, 0, 0, 0);
    frameOrologioLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);

    orologio = new Orologio(1);
    cBT = new CallBackTimer();
    orologio -> Avvia(*cBT);

    orologioLabel = new QLabel();
    QFont font("Aria");
    orologioLabel -> setFont(font);
    orologioLabel -> setAlignment(Qt::AlignCenter);
    orologioLabel -> setObjectName("orologio");
    frameOrologioLayout -> addWidget(orologioLabel);

    QTimer *t = new QTimer();
    connect(t, &QTimer::timeout, this, &PannelloOrologio::mostraOrologio);
    t -> start(1);
    mostraOrologio();

    layout -> addWidget(frame);
}

void PannelloOrologio::mostraOrologio()
{
    orologioLabel -> setText(QString::fromStdString(orologio -> ToString()));
}
