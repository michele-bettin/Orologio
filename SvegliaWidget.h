#ifndef SVEGLIAWIDGET_H
#define SVEGLIAWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QFont>
#include <QTimer>
#include <QMessageBox>
#include <QPixmap>
#include <QPushButton>
#include "./Modelli/Orologio.h"
#include "./Modelli/Sveglia.h"

class SvegliaWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
    Sveglia *sveglia;
    QLabel *svegliaLabel;
    QLabel *tempoRimanete;
    QTimer *t;
    int i = 0;
public:
    SvegliaWidget(Orologio *o, QString ti = "Nuova sveglia", int ore = 0, int minuti = 0, int secondi = 0, QWidget *parent = 0);
private slots:
    void mostraTempoRimanente();
};

#endif // SVEGLIAWIDGET_H
