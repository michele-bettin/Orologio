#include "MainWindow.h"

#include <QApplication>
#include <QFile>
#include <QString>
#include "./Modelli/Sveglia.h"
#include "./Parser/MioParserJSON.h"
#include <iostream>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);

    //Creazione file per assiociare lo stile all'applicazione
    QFile file(":Risorse/style.css");
    file.open(QFile::ReadOnly);
    QString foglioStile = QLatin1String(file.readAll());

    //Settaggi generali applicazione
    a.setStyleSheet(foglioStile);
    a.setApplicationName("Orologio");
    a.setWindowIcon(QIcon(":Risorse/logo.png"));

    //Creazione della vista principale
    MainWindow w;
    w.resize(1300, 700);
    w.show();
    return a.exec();*/
    ArrayList<Sveglia*> a1;
    Sveglia* s1 = new Sveglia(15, 15, 0, new Orario);

    a1.Aggiungi(s1);
    MioParserJSON::scriviArraySuFileJson("E:/Michele/Scuola/Università/2°Anno/Programmazione a Oggetti/MyClock/Salvataggi/Sveglie.json", a1);
    std::cout << "Fatto" << std::endl;
}
