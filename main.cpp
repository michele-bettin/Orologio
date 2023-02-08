#include "MainWindow.h"

#include <QApplication>
#include "./Modelli/Data.h"


int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
    Data* d = new Data;
    std::cout << d->ToString();
    d->Avvia(-12);
    std::cout << d->ToString();
}
