#include "SvegliaWidget.h"

SvegliaWidget::SvegliaWidget(Orologio *o, QString ti, int ore, int minuti, int secondi, QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setObjectName("sveglia-widget");

    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setSpacing(0);
    frameLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);

    //titolo
    titolo = new QLabel(ti);
    titolo -> setAlignment(Qt::AlignLeft);
    titolo -> setObjectName("sveglia-widget-titolo");
    frameLayout -> addWidget(titolo);
    frameLayout -> addSpacing(10);

    //oggetti per la rappresentazione della sveglia
    sveglia = new Sveglia(ore, minuti, secondi, o);

    svegliaLabel = new QLabel(QString::fromStdString(sveglia -> ToString()));
    svegliaLabel -> setObjectName("sveglia");
    svegliaLabel -> setAlignment(Qt::AlignLeft);
    frameLayout -> addWidget(svegliaLabel);

    tempoRimanete = new QLabel();
    tempoRimanete -> setObjectName("sveglia-widget-tempo-rimanente");
    tempoRimanete -> setAlignment(Qt::AlignLeft);
    frameLayout -> addWidget(tempoRimanete);

    t = new QTimer();
    connect(t, &QTimer::timeout, this, &SvegliaWidget::mostraTempoRimanente);
    t -> start(1);
    mostraTempoRimanente();

    layout -> addWidget(frame);
}

void SvegliaWidget::mostraTempoRimanente()
{
    tempoRimanete -> setText("Tempo rimanete: " + QString::fromStdString((sveglia -> GetTempoRimanente()).ToString()));
    if (sveglia -> HaFinito())
    {
        i++;
    }
    if (sveglia -> HaFinito() && i == 1)
    {

        QMessageBox msgBox(this);
        QPixmap icona(":Risorse/alarm.png");
        msgBox.setIconPixmap(icona);
        msgBox.setObjectName("timer-finito-msg");
        QString msg = "La sveglia <<" + titolo -> text() + ">> è terminata!";
        msgBox.setText(msg);
        QPushButton *bottone = msgBox.addButton("Chiudi", QMessageBox::NoRole);
        bottone -> setCursor(Qt::PointingHandCursor);
        msgBox.exec();
        t -> stop();
        this -> setDisabled(true);
    }
}
