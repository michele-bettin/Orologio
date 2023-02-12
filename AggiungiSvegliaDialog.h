#ifndef AGGIUNGISVEGLIADIALOG_H
#define AGGIUNGISVEGLIADIALOG_H

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
#include "SvegliaWidget.h"

class AggiungiSvegliaDialog : public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
    QLineEdit *titoloSvegliaInput;
    QFrame *frameInput;
    QHBoxLayout *frameInputLayout;
    QComboBox *oreInput;
    QComboBox *minutiInput;
    QComboBox *secondiInput;
    QPushButton *bottoneAggiungi;
public:
    AggiungiSvegliaDialog(Orologio *o, ArrayList<SvegliaWidget*>* a, QWidget *parent = 0);
};

#endif // AGGIUNGISVEGLIADIALOG_H
