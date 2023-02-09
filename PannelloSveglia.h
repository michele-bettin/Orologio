#ifndef PANNELLOSVEGLIA_H
#define PANNELLOSVEGLIA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QFrame>
#include <QLabel>
#include "BottoneIcona.h"

class PannelloSveglia : public QWidget
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
public:
    PannelloSveglia(QWidget *parent = 0);
private slots:
    void eliminazioneSveglia();
    void aggiungiSveglia();
};

#endif // PANNELLOSVEGLIA_H
