#ifndef PANNELLOIMPOSTAZIONI_H
#define PANNELLOIMPOSTAZIONI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>

class PannelloImpostazioni : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
public:
    PannelloImpostazioni(QWidget *parent = 0);
};

#endif // PANNELLOIMPOSTAZIONI_H
