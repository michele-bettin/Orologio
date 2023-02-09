#ifndef PANNELLOIMPOSTAZIONI_H
#define PANNELLOIMPOSTAZIONI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include "./Modelli/Orologio.h"

class PannelloImpostazioni : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
    QLabel *sottotitolo;
    QComboBox *fusoOrarioInput;
    QFrame *frameBottoni;
    QHBoxLayout *frameBottoniLayout;
    QPushButton *bottoneReset;
    QPushButton *bottoneModifica;

    void aggiornaFusoOrarioInput(Orologio *o);
public:
    PannelloImpostazioni(Orologio *o, QWidget *parent = 0);
};

#endif // PANNELLOIMPOSTAZIONI_H
