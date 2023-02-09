#include "PannelloSveglia.h"

PannelloSveglia::PannelloSveglia(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setObjectName("pannello-sveglia");

    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);

    //titolo
    titolo = new QLabel("Sveglia");
    titolo -> setObjectName("titolo");
    frameLayout -> addWidget(titolo);

    layout -> addWidget(frame);


    //oggetti per la realizzione dei bottoni per la creazione e eliminazione delle sveglie
    frameBottoni = new QFrame(frame);
    layout -> addWidget(frameBottoni);
    layout -> setAlignment(frameBottoni, Qt::AlignBottom | Qt::AlignRight);

    frameBottoniLayout = new QHBoxLayout(frameBottoni);
    frameBottoniLayout -> setContentsMargins(0, 0, 0, 0);
    frameBottoniLayout -> setSpacing(0);

    bottoneEliminazione = new BottoneIcona("delete");
    bottoneEliminazione -> setDisabled(true);
    bottoneEliminazione -> setCursor(Qt::PointingHandCursor);
    connect(bottoneEliminazione, &QPushButton::pressed, this, &PannelloSveglia::eliminazioneSveglia);
    frameBottoniLayout -> addWidget(bottoneEliminazione);

    bottoneAggiungi = new BottoneIcona("add");
    bottoneAggiungi -> setCursor(Qt::PointingHandCursor);
    connect(bottoneAggiungi, &QPushButton::pressed, this, &PannelloSveglia::aggiungiSveglia);
    frameBottoniLayout -> addWidget(bottoneAggiungi);
}

void PannelloSveglia::eliminazioneSveglia()
{

}

void PannelloSveglia::aggiungiSveglia()
{

}
