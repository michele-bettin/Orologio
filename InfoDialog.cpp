#include "InfoDialog.h"

InfoDialog::InfoDialog(QWidget *parent)
    : QDialog(parent)
{
    this -> setMinimumSize(500, 400);

    layout = new QVBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);

    frame = new QFrame();
    frame -> setObjectName("pannello-info");
    frameLayout = new QVBoxLayout(frame);
    frameLayout -> setContentsMargins(0, 0, 0, 0);
    frameLayout -> setAlignment(Qt::AlignCenter);

    //titolo
    titolo = new QLabel("Orologio");
    titolo -> setObjectName("titolo");
    frameLayout -> addWidget(titolo);

    //immagine
    logo = QPixmap(":Risorse/logo.png");
    logo = logo.scaled(128, 128, Qt::KeepAspectRatio);
    logoLabel = new QLabel();
    logoLabel -> setPixmap(logo);
    logoLabel -> setAlignment(Qt::AlignCenter);
    logoLabel -> setObjectName("logo");
    frameLayout -> addWidget(logoLabel);

    //autori section
    autoriTitolo = new QLabel("Autori:");
    autoriTitolo -> setObjectName("autori-titolo");
    autoriTitolo -> setAlignment(Qt::AlignCenter);
    frameLayout -> addWidget(autoriTitolo);

    autore1 = new QLabel("Bettin Michele");
    autore1 -> setAlignment(Qt::AlignCenter);
    autore1 -> setObjectName("autore");
    frameLayout -> addWidget(autore1);
    autore2 = new QLabel("Favaron Riccardo");
    autore2 -> setAlignment(Qt::AlignCenter);
    autore2 -> setObjectName("autore");
    frameLayout -> addWidget(autore2);

    layout -> addWidget(frame);
}
