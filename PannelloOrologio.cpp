#include "PannelloOrologio.h"

PannelloOrologio::PannelloOrologio(Orologio *o, QWidget *parent)
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

    orologioLabel = new QLabel();
    QFont font("Aria");
    orologioLabel -> setFont(font);
    orologioLabel -> setAlignment(Qt::AlignCenter);
    orologioLabel -> setObjectName("orologio");
    frameOrologioLayout -> addWidget(orologioLabel);

    QTimer *t = new QTimer();
    connect(t, &QTimer::timeout, [o, this]()
    {
        orologioLabel -> setText(QString::fromStdString(o -> ToString()));
    });
    t -> start(1);

    layout -> addWidget(frame);
}
