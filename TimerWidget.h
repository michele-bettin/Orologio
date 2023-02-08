#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QFont>
#include <QTimer>
#include <QMessageBox>
#include <QPixmap>
#include <QPushButton>
#include "./Modelli/Timer.h"
#include "./Modelli/CallBackTimer.h"
#include "BottoneIcona.h"

class TimerWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
    int ore;
    int minuti;
    int secondi;
    Timer timer;
    CallBackTimer *cBT;
    QLabel *timerLabel;
    QFrame *frameBottoni;
    QHBoxLayout *frameBottoniLayout;
    BottoneIcona *bottonePlayPausa;
    bool staRiproducendo = false;
    BottoneIcona *bottoneInizializza;
    int i = 0;
public:
    TimerWidget(QString ti = "0 min", int o = 0, int m = 0, int s = 0, QWidget *partent = 0);
private slots:
    void mostraTimer();
    void playPausaTimer();
    void inizializzaTimer();
};

#endif // TIMERWIDGET_H
