#ifndef BOTTONEMENU_H
#define BOTTONEMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QString>

class BottoneMenu : public QPushButton
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QPixmap icona;
    QLabel *iconaLabel;
    QLabel *testo;
public:
    BottoneMenu(QString iconaPercorso, QString t, QWidget *parent = 0);
};

#endif // BOTTONEMENU_H
