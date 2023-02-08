#include "BottoneMenu.h"

BottoneMenu::BottoneMenu(QString iconaPercorso, QString t, QWidget *parent)
    : QPushButton(parent)
{
    this -> setFixedHeight(100);

    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setContentsMargins(0, 0, 0, 0);
    frame -> setObjectName("bottone-menu");
    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setAlignment(Qt::AlignCenter);

    //icona
    icona = QPixmap(":Risorse/" + iconaPercorso + ".png");
    iconaLabel = new QLabel();
    iconaLabel -> setPixmap(icona);
    iconaLabel -> setAlignment(Qt::AlignCenter);
    frameLayout -> addWidget(iconaLabel);

    //testo
    testo = new QLabel(t);
    testo -> setObjectName("bottone-menu-testo");
    frameLayout -> addWidget(testo);

    layout -> addWidget(frame);
}
