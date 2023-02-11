#ifndef APP_H
#define APP_H

#include <QWidget>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QFrame>
#include <QScrollArea>
#include "./Modelli/Orologio.h"
#include "./Modelli/CallBackTimer.h"
#include "BottoneMenu.h"
#include "PannelloOrologio.h"
#include "PannelloSveglia.h"
#include "PannelloTimer.h"
#include "PannelloCronometro.h"
#include "PannelloImpostazioni.h"
#include "./Collezioni/ArrayList.h"
#include "SvegliaWidget.h"
#include "./Parser/MioParserJSON.h"

class App : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout *layout;

    //Oggetti per la realizzazione della menubar superiore
    QMenuBar *menuBar;

    QMenu *fileMenu;
    QAction *salvaActionFileMenu;
    QAction *esciActionFileMenu;

    QMenu *vistaMenu;
    QAction *orologioActionVistaMenu;
    QAction *svegliaActionVistaMenu;
    QAction *timerActionVistaMenu;
    QAction *cronometroActionVistaMenu;
    QAction *impostazioniActionVistaMenu;

    QMenu *infoMenu;
    QAction *informazioniActionInfoMenu;

    //Oggetti per la realizzazione dell'orologio
    Orologio *orologio;
    CallBackTimer *cBT;

    //Oggetti per la realizzazione del menu laterale
    BottoneMenu *bmOrologio;
    BottoneMenu *bmSveglia;
    BottoneMenu *bmTimer;
    BottoneMenu *bmCronometro;
    BottoneMenu *bmImpostazioni;

    //Oggetti per la realizzazione dei pannelli a destra
    PannelloOrologio *pOrologio;
    PannelloSveglia *pSveglia;
    PannelloTimer *pTimer;
    PannelloCronometro *pCronometro;
    PannelloImpostazioni *pImpostazioni;

    //Oggetti per la persistenza dei dati
    ArrayList<SvegliaWidget*> sveglieSalvate;

    void menu();
    void pannelloSinistro();
    void pannelloDestro();
public:
    App(QWidget *parent = 0);
    QAction *apriActionFileMenu;

signals:
    void bmOrologioAction();
    void bmSvegliaAction();
    void bmTimerAction();
    void bmCronometroAction();
    void bmImpostazioniAction();
private slots:
    void mostraInformazioni();
    void orologioActive();
    void svegliaActive();
    void timerActive();
    void cronometroActive();
    void impostazioniActive();
};

#endif // APP_H
