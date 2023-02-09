#include "PannelloImpostazioni.h"

PannelloImpostazioni::PannelloImpostazioni(Orologio *o, QWidget *parent)
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
    titolo -> setAlignment(Qt::AlignCenter);
    frameLayout -> addWidget(titolo);

    //sottotitolo
    sottotitolo = new QLabel("Modifica il fuso orario");
    sottotitolo -> setObjectName("sottotitolo");
    sottotitolo -> setAlignment(Qt::AlignCenter);
    frameLayout -> addWidget(sottotitolo);

    frameLayout -> addSpacing(20);

    fusoOrarioInput = new QComboBox();
    for (int i = -12; i < 14; ++i)
    {
        fusoOrarioInput -> addItem(QString::number(i));
    }

    aggiornaFusoOrarioInput(o);

    frameLayout -> addWidget(fusoOrarioInput);
    frameLayout -> setAlignment(fusoOrarioInput, Qt::AlignCenter);

    //oggetti per la realizzazione dei bottoni
    frameBottoni = new QFrame(frame);
    frameLayout -> addWidget(frameBottoni);

    frameBottoniLayout = new QHBoxLayout(frameBottoni);
    frameBottoniLayout -> setContentsMargins(0, 0, 0, 0);
    frameBottoniLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);
    frameBottoniLayout -> setSpacing(20);

    bottoneReset = new QPushButton("Reset");
    bottoneReset -> setObjectName("bottone");
    bottoneReset -> setCursor(Qt::PointingHandCursor);
    connect(bottoneReset, &QPushButton::pressed, [o, this]()
    {
        o -> ImpostaFusoOrario(1);//fusoOrarioInput -> currentText().toInt()
        aggiornaFusoOrarioInput(o);
    });
    frameBottoniLayout -> addWidget(bottoneReset);

    bottoneModifica = new QPushButton("Modifica");
    bottoneModifica -> setObjectName("bottone");
    bottoneModifica -> setCursor(Qt::PointingHandCursor);
    connect(bottoneModifica, &QPushButton::pressed, [o, this]()
    {
        o -> ImpostaFusoOrario(fusoOrarioInput -> currentText().toInt());
        aggiornaFusoOrarioInput(o);
    });
    frameBottoniLayout -> addWidget(bottoneModifica);

    layout -> addWidget(frame);
}

void PannelloImpostazioni::aggiornaFusoOrarioInput(Orologio *o)
{
    int index = fusoOrarioInput -> findText(QString::fromStdString(std::to_string(o -> getFusoOrario())));
    if (index != -1) {
        fusoOrarioInput -> setCurrentIndex(index);
    }
}
