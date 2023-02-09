#ifndef PANNELLOTIMER_H
#define PANNELLOTIMER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QFrame>
#include <QLabel>
#include "BottoneIcona.h"
#include "TimerWidget.h"
#include "./Collezioni/ArrayList.h"
#include "AggiungiCustomTimerDialog.h"

class PannelloTimer : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;

    QFrame *frameBottoni;
    QHBoxLayout *frameBottoniLayout;
    BottoneIcona *bottoneEliminazione;
    BottoneIcona *bottoneAggiungi;

    void mostraStandardTimer();

    ArrayList<TimerWidget*> collezioneCustomTimer;
    int numeroTimerEsistenti = 0;

    QScrollArea *scrollCustomTimer;
    QFrame *frameCustomTimer;
    QHBoxLayout *frameCustomTimerLayout;
    void mostraCustomTimer();

    AggiungiCustomTimerDialog *actd;
public:
    PannelloTimer(QWidget *parent = 0);
private slots:
    void aggiungiCustomTimer();
    void eliminazioneCustomTimer();
};

#endif // PANNELLOTIMER_H
