#ifndef PANNELLOSVEGLIA_H
#define PANNELLOSVEGLIA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>

class PannelloSveglia : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
public:
    PannelloSveglia(QWidget *parent = 0);
};

#endif // PANNELLOSVEGLIA_H
