#include "AggiungiSvegliaDialog.h"

AggiungiSvegliaDialog::AggiungiSvegliaDialog(Orologio *o, ArrayList<SvegliaWidget*>* a, int *n, QWidget *parent)
    : QDialog(parent)
{
    this -> setMinimumSize(500, 300);

    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setObjectName("aggiungi-sveglia-dialog");

    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);

    //titolo
    titolo = new QLabel("Aggiungi una nuova sveglia");
    titolo -> setAlignment(Qt::AlignCenter);
    titolo -> setObjectName("titolo");
    frameLayout -> addWidget(titolo);

    //box titolo nuova sveglia
    titoloSvegliaInput = new QLineEdit();
    titoloSvegliaInput -> setPlaceholderText("Inserisci titolo");
    titoloSvegliaInput -> setObjectName("titolo-sveglia-input");
    frameLayout -> addWidget(titoloSvegliaInput);
    frameLayout -> setAlignment(titoloSvegliaInput, Qt::AlignCenter);

    //oggetti per la realizzazione degli oggetti per realizzazione
    //dell'input di ore, minuti e secondo del nuovo timer
    frameInput = new QFrame();
    frameLayout -> addWidget(frameInput);

    frameInputLayout = new QHBoxLayout(frameInput);
    frameInputLayout -> setContentsMargins(0, 0, 0, 0);
    frameInputLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);
    frameInputLayout -> setSpacing(20);

    oreInput = new QComboBox();
    for (int i = 0; i < 24; ++i)
    {
        oreInput -> addItem(QString::number(i));
    }
    minutiInput = new QComboBox();
    secondiInput = new QComboBox();
    for (int i = 0; i < 60; ++i)
    {
        minutiInput -> addItem(QString::number(i));
        secondiInput -> addItem(QString::number(i));
    }
    frameInputLayout -> addWidget(oreInput);
    frameInputLayout -> addWidget(minutiInput);
    frameInputLayout -> addWidget(secondiInput);

    //bottone aggiungi nuova sveglia
    bottoneAggiungi = new QPushButton("Aggiungi sveglia");
    bottoneAggiungi -> setObjectName("bottone");
    bottoneAggiungi -> setCursor(Qt::PointingHandCursor);
    connect(bottoneAggiungi, &QPushButton::pressed, [o, a, n, this]()
    {
        int ore = oreInput -> currentText().toInt();
        int minuti = minutiInput -> currentText().toInt();
        int secondi = secondiInput -> currentText().toInt();
        QString titoloSvegliaString = titoloSvegliaInput -> text();
        if (titoloSvegliaString == "")
        {
            titoloSvegliaString = "Nuova sveglia";
        }
        SvegliaWidget *sw = new SvegliaWidget(o, titoloSvegliaString, ore, minuti, secondi);
        a -> Aggiungi(sw);
        *n = *n + 1;
        this -> close();
    });
    frameLayout -> addWidget(bottoneAggiungi);
    frameLayout -> setAlignment(bottoneAggiungi, Qt::AlignCenter);

    layout -> addWidget(frame);
}
