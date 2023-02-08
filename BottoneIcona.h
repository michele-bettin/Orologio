#ifndef BOTTONEICONA_H
#define BOTTONEICONA_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QString>

class BottoneIcona : public QPushButton
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QPixmap icona;
    QLabel *iconaLabel;
public:
    BottoneIcona(QString iconaPercorso, QWidget *parent = 0);
    void setIcona(QString iconaPercorsoNuovo);
};

#endif // BOTTONEICONA_H
