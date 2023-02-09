#ifndef AGGIUNGICUSTOMTIMERDIALOG_H
#define AGGIUNGICUSTOMTIMERDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QPixmap>
#include "./Collezioni/ArrayList.h"
#include "TimerWidget.h"

class AggiungiCustomTimerDialog : public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
    QLineEdit *titoloTimerInput;
    QFrame *frameInput;
    QHBoxLayout *frameInputLayout;
    QComboBox *oreInput;
    QComboBox *minutiInput;
    QComboBox *secondiInput;
    QPushButton *bottoneAggiungi;
public:
    AggiungiCustomTimerDialog(ArrayList<TimerWidget*>* a, int* n, QWidget *parent = 0);
};

#endif // AGGIUNGICUSTOMTIMERDIALOG_H
