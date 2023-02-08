#include "PannelloImpostazioni.h"

PannelloImpostazioni::PannelloImpostazioni(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setObjectName("pannello-impostazioni");

    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);

    //titolo
    titolo = new QLabel("Impostazioni");
    titolo -> setObjectName("titolo");
    frameLayout -> addWidget(titolo);

    layout -> addWidget(frame);
}
