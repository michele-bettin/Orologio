#include "MainWindow.h"

#include <QApplication>
#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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
    return a.exec();
}
