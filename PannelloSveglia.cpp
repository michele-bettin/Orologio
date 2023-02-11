#include "PannelloSveglia.h"

PannelloSveglia::PannelloSveglia(Orologio *o, QWidget *parent)
    : QWidget(parent)
{
    collezioneSveglie = ArrayList<SvegliaWidget*>();

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
    titolo -> setAlignment(Qt::AlignCenter);
    frameLayout -> addWidget(titolo);

    //oggetti per la rappresentazione delle sveglie
    scrollSveglie = new QScrollArea();
    scrollSveglie -> setObjectName("scroll-sveglie");
    scrollSveglie -> setContentsMargins(0, 0, 0, 0);
    scrollSveglie -> setWidgetResizable(true);
    scrollSveglie -> setFixedHeight(250);
    scrollSveglie -> setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollSveglie -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    frameSveglie = new QFrame(scrollSveglie);
    frameSveglie -> setObjectName("frame-sveglie");
    scrollSveglie -> setWidget(frameSveglie);

    frameSveglieLayout = new QHBoxLayout(frameSveglie);
    frameSveglieLayout -> setContentsMargins(50, 50, 50, 0);
    frameSveglieLayout -> setAlignment(Qt::AlignTop | Qt::AlignLeft);
    frameSveglieLayout -> setSpacing(50);

    frameLayout -> addWidget(scrollSveglie);
    frameLayout -> setAlignment(scrollSveglie, Qt::AlignTop);

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
    connect(bottoneEliminazione, &QPushButton::pressed, [this]()
    {
        numeroSveglieEsistenti = 0;
        bottoneEliminazione -> setDisabled(true);

        //rimozione SvegliaWidget dal layout
        while (frameSveglieLayout -> count() > 0)
        {
            QLayoutItem *item = frameSveglieLayout -> takeAt(0);
            if (item -> widget())
            {
                delete item -> widget();
            }
            delete item;
        }

        //reset dell'array list
        collezioneSveglie.RimuoviTutti();
    });
    frameBottoniLayout -> addWidget(bottoneEliminazione);

    bottoneAggiungi = new BottoneIcona("add");
    bottoneAggiungi -> setCursor(Qt::PointingHandCursor);
    connect(bottoneAggiungi, &QPushButton::pressed, [o, this]()
    {
        asd = new AggiungiSvegliaDialog(o, &collezioneSveglie, &numeroSveglieEsistenti);
        asd -> setWindowTitle("Orologio - Aggiungi una nuova sveglia");
        asd -> setModal(true);
        asd -> exec();

        //aggiungo la nuova sveglia creata
        if (numeroSveglieEsistenti <= collezioneSveglie.GetDimensione())
        {
            frameSveglieLayout -> addWidget(*collezioneSveglie.Get(numeroSveglieEsistenti - 1));
        }

        //rendo cliccabile il bottone per la cancellazio delle sveglie aggiunte
        if (collezioneSveglie.GetDimensione() > 0)
        {
            bottoneEliminazione -> setDisabled(false);
        }
    });
    frameBottoniLayout -> addWidget(bottoneAggiungi);
}
