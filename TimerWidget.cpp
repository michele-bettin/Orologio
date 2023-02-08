#include "TimerWidget.h"

TimerWidget::TimerWidget(QString ti, int o, int m, int s, QWidget *parent)
    : QWidget(parent), ore(o), minuti(m), secondi(s), timer(o, m, s)
{
    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setObjectName("timer-widget");

    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);

    //titolo
    titolo = new QLabel(ti);
    titolo -> setAlignment(Qt::AlignCenter);
    titolo -> setObjectName("timer-widget-titolo");
    frameLayout -> addWidget(titolo);

    //oggetti per la rappresentazione del timer
    cBT = new CallBackTimer();

    timerLabel = new QLabel();
    QFont font("Arial");
    timerLabel -> setFont(font);
    timerLabel -> setAlignment(Qt::AlignCenter);
    timerLabel -> setObjectName("timer-widget-timer");
    frameLayout -> addWidget(timerLabel);

    QTimer *t = new QTimer();
    connect(t, &QTimer::timeout, this, &TimerWidget::mostraTimer);
    t -> start(1);
    mostraTimer();

    //bottoni per la gestione del timer
    frameBottoni = new QFrame(frame);
    frameLayout -> addWidget(frameBottoni);

    frameBottoniLayout = new QHBoxLayout(frameBottoni);
    frameBottoniLayout -> setContentsMargins(0, 0, 0, 0);
    frameBottoniLayout -> setAlignment(Qt::AlignTop | Qt::AlignCenter);
    frameBottoniLayout -> setSpacing(20);

    bottonePlayPausa = new BottoneIcona("play", frameBottoni);
    bottonePlayPausa -> setCursor(Qt::PointingHandCursor);
    connect(bottonePlayPausa, &QPushButton::pressed, this, &TimerWidget::playPausaTimer);
    frameBottoniLayout -> addWidget(bottonePlayPausa);

    bottoneInizializza = new BottoneIcona("stop", frameBottoni);
    bottoneInizializza -> setCursor(Qt::PointingHandCursor);
    connect(bottoneInizializza, &QPushButton::pressed, this, &TimerWidget::inizializzaTimer);
    frameBottoniLayout -> addWidget(bottoneInizializza);

    layout -> addWidget(frame);
}

void TimerWidget::mostraTimer()
{
    timerLabel -> setText(QString::fromStdString(timer.ToString()));
    if (timer.HaFinito())
    {
        i++;
    }
    if (timer.HaFinito() && i == 1)
    {
        QMessageBox msgBox(this);
        QPixmap icona(":Risorse/timer.png");
        msgBox.setIconPixmap(icona);
        msgBox.setObjectName("timer-finito-msg");
        QString msg = "Il timer <<" + titolo -> text() + ">> è terminato!";
        msgBox.setText(msg);
        QPushButton *bottone = msgBox.addButton("Chiudi", QMessageBox::NoRole);
        bottone -> setCursor(Qt::PointingHandCursor);
        msgBox.exec();
        inizializzaTimer();
    }
}

void TimerWidget::playPausaTimer()
{
    if (!staRiproducendo)
    {
        bottonePlayPausa -> setIcona("pause");
        staRiproducendo = !staRiproducendo;
        timer.Avvia(*cBT);
    }
    else
    {
        bottonePlayPausa -> setIcona("play");
        staRiproducendo = !staRiproducendo;
        timer.Ferma(*cBT);
    }
}

void TimerWidget::inizializzaTimer()
{
    int vecchiSecondi = ore * Timer::SECONDI_ORA + minuti * Timer::SECONDI_MINUTO + secondi;
    vecchiSecondi = vecchiSecondi % Timer::SECONDI_GIORNO;
    bottonePlayPausa -> setIcona("play");
    staRiproducendo = false;
    timer.Ferma(*cBT);
    timer.SetSecondi(vecchiSecondi);
    i = 0;
}
