#include "AggiungiCustomTimerDialog.h"

AggiungiCustomTimerDialog::AggiungiCustomTimerDialog(ArrayList<TimerWidget*>* a, int* n, QWidget *parent)
    : QDialog(parent)
{
    this -> setMinimumSize(500, 300);

    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setObjectName("aggiungi-custom-timer-dialog");

    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);

    //titolo
    titolo = new QLabel("Aggiungi un nuovo timer");
    titolo -> setAlignment(Qt::AlignCenter);
    titolo -> setObjectName("titolo");
    frameLayout -> addWidget(titolo);

    //box titolo nuovo timer
    titoloTimerInput = new QLineEdit();
    titoloTimerInput -> setPlaceholderText("Inserisci titolo");
    titoloTimerInput -> setObjectName("titolo-timer-input");
    frameLayout -> addWidget(titoloTimerInput);
    frameLayout -> setAlignment(titoloTimerInput, Qt::AlignCenter);

    //oggetti per la realizzazione degli oggetti per la realizzazione
    //dell'input di ore, minuti e secondi del nuovo timer
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

    //bottone aggiungi nuovo timer
    bottoneAggiungi = new QPushButton("Aggiungi timer");
    bottoneAggiungi -> setObjectName("bottone");
    bottoneAggiungi -> setCursor(Qt::PointingHandCursor);
    connect(bottoneAggiungi, &QPushButton::pressed, [a, n, this]()
    {
        int ore = oreInput -> currentText().toInt();
        int minuti = minutiInput -> currentText().toInt();
        int secondi = secondiInput -> currentText().toInt();
        if (ore + minuti + secondi == 0)
        {
            QMessageBox msgErrore(this);
            QPixmap icona(":Risorse/error.png");
            msgErrore.setIconPixmap(icona);
            msgErrore.setObjectName("timer-finito-msg");
            QString msg = "Errore! Inserisci un input maggiore di 0.";
            msgErrore.setText(msg);
            QPushButton *bottone = msgErrore.addButton("Chiudi", QMessageBox::NoRole);
            bottone -> setCursor(Qt::PointingHandCursor);
            msgErrore.exec();
        }
        else
        {
            QString titoloTimerString = titoloTimerInput -> text();
            if (titoloTimerString == "")
            {
                titoloTimerString = "Nuovo timer";
            }
            TimerWidget *tw = new TimerWidget(titoloTimerString, ore, minuti, secondi);
            a -> Aggiungi(tw);
            *n = *n + 1;
            this -> close();
        }
    });
    frameLayout -> addWidget(bottoneAggiungi);
    frameLayout -> setAlignment(bottoneAggiungi, Qt::AlignCenter);

    layout -> addWidget(frame);
}
