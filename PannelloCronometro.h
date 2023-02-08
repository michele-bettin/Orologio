#ifndef PANNELLOCRONOMETRO_H
#define PANNELLOCRONOMETRO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QTimer>
#include <QFont>
#include "./Modelli/Cronometro.h"
#include "./Modelli/CallBackTimer.h"
#include "BottoneIcona.h"

class PannelloCronometro : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
    QLabel *cronometroLabel;
    Cronometro *cronometro;
    CallBackTimer *cBT;
    QFrame *frameBottoni;
    QHBoxLayout *frameBottoniLayout;
    BottoneIcona *bottonePlayPausa;
    bool staRiproducendo = false;
    BottoneIcona *bottoneAzzera;
public:
    PannelloCronometro(QWidget *parent = 0);
private slots:
    void mostraCronometro();
    void playPausaCronometro();
    void azzeraCronometro();
};

#endif // PANNELLOCRONOMETRO_H
