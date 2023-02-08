#ifndef PANNELLOCRONOMETRO_H
#define PANNELLOCRONOMETRO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>

class PannelloCronometro : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
    QLabel *cronometroLabel;

public:
    PannelloCronometro(QWidget *parent = 0);
};

#endif // PANNELLOCRONOMETRO_H
