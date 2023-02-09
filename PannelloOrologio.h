#ifndef PANNELLOOROLOGIO_H
#define PANNELLOOROLOGIO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QFont>
#include "./Modelli/Orologio.h"

class PannelloOrologio : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
    QFrame *frameOrologio;
    QVBoxLayout *frameOrologioLayout;
    QLabel *orologioLabel;
public:
    PannelloOrologio(Orologio *o, QWidget *parent = 0);
};

#endif // PANNELLOOROLOGIO_H
