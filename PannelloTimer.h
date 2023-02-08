#ifndef PANNELLOTIMER_H
#define PANNELLOTIMER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QFrame>
#include <QLabel>
#include "BottoneIcona.h"

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
    BottoneIcona *bottoneModifica;
    BottoneIcona *bottoneAggiungi;

    void mostraStandardTimer();
public:
    PannelloTimer(QWidget *parent = 0);
};

#endif // PANNELLOTIMER_H
