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
#include "./Modelli/CallBackTimer.h"

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
    Orologio *orologio;
    CallBackTimer *cBT;
    QLabel *orologioLabel;
public:
    PannelloOrologio(QWidget *parent = 0);
private slots:
    void mostraOrologio();
};

#endif // PANNELLOOROLOGIO_H
