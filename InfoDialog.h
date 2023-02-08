#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QPixmap>
#include <QLabel>

class InfoDialog : public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *frameLayout;
    QLabel *titolo;
    QPixmap logo;
    QLabel *logoLabel;
    QLabel *autoriTitolo;
    QLabel *autore1;
    QLabel *autore2;
public:
    InfoDialog(QWidget *parent = 0);
};

#endif // INFODIALOG_H
