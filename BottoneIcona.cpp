#include "BottoneIcona.h"

BottoneIcona::BottoneIcona(QString iconaPercorso, QWidget *parent)
    : QPushButton(parent)
{
    this -> setFixedSize(50, 50);
    this -> setObjectName("bottone-icona-parent");

    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame(this);
    frame -> setContentsMargins(0, 0, 0, 0);
    frame -> setObjectName("bottone-icona");

    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setAlignment(Qt::AlignHCenter);

    //icona
    icona = QPixmap(":Risorse/" + iconaPercorso + ".png");
    iconaLabel = new QLabel();
    iconaLabel -> setPixmap(icona);
    iconaLabel -> setAlignment(Qt::AlignCenter);
    frameLayout -> addWidget(iconaLabel);

    layout -> addWidget(frame);
}

void BottoneIcona::setIcona(QString iconaPercorsoNuovo)
{
    QPixmap iconaNuova = QPixmap(":Risorse/" + iconaPercorsoNuovo + ".png");
    iconaLabel -> setPixmap(iconaNuova);
}
