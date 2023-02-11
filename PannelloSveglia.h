#ifndef PANNELLOSVEGLIA_H
#define PANNELLOSVEGLIA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QFrame>
#include <QLabel>
#include "AggiungiSvegliaDialog.h"
#include "BottoneIcona.h"
#include "./Modelli/Orologio.h"
#include "SvegliaWidget.h"
#include "./Collezioni/ArrayList.h"

class PannelloSveglia : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;

    ArrayList<SvegliaWidget*> collezioneSveglie;
    int numeroSveglieEsistenti = 0;

    QScrollArea *scrollSveglie;
    QFrame *frameSveglie;
    QHBoxLayout *frameSveglieLayout;

    QFrame *frameBottoni;
    QHBoxLayout *frameBottoniLayout;
    BottoneIcona *bottoneEliminazione;
    BottoneIcona *bottoneAggiungi;

    AggiungiSvegliaDialog *asd;
public:
    PannelloSveglia(Orologio *o, QWidget *parent = 0);
};

#endif // PANNELLOSVEGLIA_H
