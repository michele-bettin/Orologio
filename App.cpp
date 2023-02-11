#include "App.h"
#include "InfoDialog.h"

App::App(QWidget *parent)
    : QWidget(parent)
{
    sveglieSalvate = ArrayList<SvegliaWidget*>();

    layout = new QHBoxLayout(this);
    layout -> setContentsMargins(0, 0, 0, 0);
    layout -> setSpacing(0);

    orologio = new Orologio(1);
    cBT = new CallBackTimer();
    orologio -> Avvia(*cBT);

    menu();
    pannelloSinistro();
    pannelloDestro();
}

void App::menu()
{
    menuBar = new QMenuBar();

    //realizzazione opzione "File"
    fileMenu = new QMenu("File");
    menuBar -> addMenu(fileMenu);
    apriActionFileMenu = new QAction("Apri", fileMenu);
    apriActionFileMenu -> setIcon(QIcon(":Risorse/open.png"));
    apriActionFileMenu -> setShortcut(Qt::Key_O | Qt::CTRL);




    fileMenu -> addAction(apriActionFileMenu);
    salvaActionFileMenu = new QAction("Salva", fileMenu);
    salvaActionFileMenu -> setIcon(QIcon(":Risorse/save.png"));
    salvaActionFileMenu -> setShortcut(Qt::Key_S | Qt::CTRL);
    connect(salvaActionFileMenu, &QAction::triggered, [this]()
        {
            MioParserJSON::scriviArraySuFileJson("E:/Michele/Scuola/Università/2°Anno/Programmazione a Oggetti/MyClock/Salvataggi/Sveglie.json", sveglieSalvate);
        }
    );
    fileMenu -> addAction(salvaActionFileMenu);
    esciActionFileMenu = new QAction("Esci", fileMenu);
    esciActionFileMenu -> setIcon(QIcon(":Risorse/exit.png"));
    esciActionFileMenu -> setShortcut(Qt::Key_Q | Qt::CTRL);
    connect(esciActionFileMenu, &QAction::triggered, []() {
        QApplication::exit();
    });
    fileMenu -> addSeparator();
    fileMenu -> addAction(esciActionFileMenu);

    //realizzazione opzione "Vista"
    vistaMenu = new QMenu("Visualizza");
    menuBar -> addMenu(vistaMenu);
    orologioActionVistaMenu = new QAction("Orologio", vistaMenu);
    orologioActionVistaMenu -> setIcon(QIcon(":Risorse/globe-black.png"));
    orologioActionVistaMenu  -> setShortcut(Qt::Key_1 | Qt::CTRL);
    connect(orologioActionVistaMenu, &QAction::triggered, this, &App::bmOrologioAction);
    vistaMenu -> addAction(orologioActionVistaMenu);
    svegliaActionVistaMenu = new QAction("Sveglia", vistaMenu);
    svegliaActionVistaMenu -> setIcon(QIcon(":Risorse/alarm-black.png"));
    svegliaActionVistaMenu  -> setShortcut(Qt::Key_2 | Qt::CTRL);
    connect(svegliaActionVistaMenu, &QAction::triggered, this, &App::bmSvegliaAction);
    vistaMenu -> addAction(svegliaActionVistaMenu);
    timerActionVistaMenu = new QAction("Timer", vistaMenu);
    timerActionVistaMenu -> setIcon(QIcon(":Risorse/timer-black.png"));
    timerActionVistaMenu  -> setShortcut(Qt::Key_3 | Qt::CTRL);
    connect(timerActionVistaMenu, &QAction::triggered, this, &App::bmTimerAction);
    vistaMenu -> addAction(timerActionVistaMenu);
    cronometroActionVistaMenu = new QAction("Cronometro", vistaMenu);
    cronometroActionVistaMenu -> setIcon(QIcon(":Risorse/stopwatch-black.png"));
    cronometroActionVistaMenu  -> setShortcut(Qt::Key_4 | Qt::CTRL);
    connect(cronometroActionVistaMenu, &QAction::triggered, this, &App::bmCronometroAction);
    vistaMenu -> addAction(cronometroActionVistaMenu);
    impostazioniActionVistaMenu = new QAction("Impostazioni", vistaMenu);
    impostazioniActionVistaMenu -> setIcon(QIcon(":Risorse/settings-black.png"));
    impostazioniActionVistaMenu  -> setShortcut(Qt::Key_0 | Qt::CTRL);
    connect(impostazioniActionVistaMenu, &QAction::triggered, this, &App::bmImpostazioniAction);
    vistaMenu -> addSeparator();
    vistaMenu -> addAction(impostazioniActionVistaMenu);

    //realizzazione opzione "Info"
    infoMenu = new QMenu("Info");
    menuBar -> addMenu(infoMenu);
    informazioniActionInfoMenu = new QAction("Informazioni su Orologio", infoMenu);
    informazioniActionInfoMenu -> setIcon(QIcon(":Risorse/info.png"));
    informazioniActionInfoMenu -> setShortcut(Qt::Key_I | Qt::CTRL);
    connect(informazioniActionInfoMenu, &QAction::triggered, this, &App::mostraInformazioni);
    infoMenu -> addAction(informazioniActionInfoMenu);

    layout -> setMenuBar(menuBar);
}

void App::pannelloSinistro()
{
    QFrame *psFrame = new QFrame(this);
    psFrame -> setFixedWidth(100);
    psFrame -> setObjectName("pannello-sinistro-menu");

    QVBoxLayout *psFrameLayout = new QVBoxLayout(psFrame);
    psFrameLayout -> setContentsMargins(0, 0, 0, 0);
    psFrameLayout -> setSpacing(0);

    //creazione bottoni menu
    bmOrologio = new BottoneMenu("globe", "Orologio", psFrame);
    bmOrologio -> setCursor(Qt::PointingHandCursor);
    connect(bmOrologio, &QPushButton::pressed, this, &App::bmOrologioAction);
    psFrameLayout -> addWidget(bmOrologio);
    bmSveglia = new BottoneMenu("alarm", "Sveglia", psFrame);
    bmSveglia -> setCursor(Qt::PointingHandCursor);
    connect(bmSveglia, &QPushButton::pressed, this, &App::bmSvegliaAction);
    psFrameLayout -> addWidget(bmSveglia);
    bmTimer = new BottoneMenu("timer", "Timer", psFrame);
    bmTimer -> setCursor(Qt::PointingHandCursor);
    connect(bmTimer, &QPushButton::pressed, this, &App::bmTimerAction);
    psFrameLayout -> addWidget(bmTimer);
    bmCronometro = new BottoneMenu("stopwatch", "Cronometro", psFrame);
    bmCronometro -> setCursor(Qt::PointingHandCursor);
    connect(bmCronometro, &QPushButton::pressed, this, &App::bmCronometroAction);
    psFrameLayout -> addWidget(bmCronometro);

    psFrameLayout -> addStretch();

    bmImpostazioni = new BottoneMenu("settings", "Impostazioni", psFrame);
    bmImpostazioni -> setCursor(Qt::PointingHandCursor);
    connect(bmImpostazioni, &QPushButton::pressed, this, &App::bmImpostazioniAction);
    psFrameLayout -> addWidget(bmImpostazioni);

    layout -> addWidget(psFrame);
}

void App::pannelloDestro()
{
    QScrollArea *scroll = new QScrollArea();
    scroll -> setMinimumWidth(840);
    scroll -> setContentsMargins(0, 0, 0, 0);
    scroll -> setWidgetResizable(true);
    scroll -> setObjectName("scroll");

    QFrame *pdFrame = new QFrame(scroll);
    pdFrame -> setContentsMargins(0, 0, 0, 0);
    pdFrame -> setObjectName("pannello-destro");

    QHBoxLayout *pdFrameLayout = new QHBoxLayout(pdFrame);
    pdFrameLayout -> setContentsMargins(0, 0, 0, 0);
    pdFrameLayout -> setSpacing(0);

    //creazione pannelli a destra
    pOrologio = new PannelloOrologio(orologio, pdFrame);
    connect(this, &App::bmOrologioAction, this, &App::orologioActive);
    pdFrameLayout -> addWidget(pOrologio);
    pSveglia = new PannelloSveglia(orologio, &sveglieSalvate, this);
    connect(this, &App::bmSvegliaAction, this, &App::svegliaActive);
    pdFrameLayout -> addWidget(pSveglia);
    pTimer = new PannelloTimer(pdFrame);
    connect(this, &App::bmTimerAction, this, &App::timerActive);
    pdFrameLayout -> addWidget(pTimer);
    pCronometro = new PannelloCronometro(pdFrame);
    connect(this, &App::bmCronometroAction, this, &App::cronometroActive);
    pdFrameLayout -> addWidget(pCronometro);
    pImpostazioni = new PannelloImpostazioni(orologio, pdFrame);
    connect(this, &App::bmImpostazioniAction, this, &App::impostazioniActive);
    pdFrameLayout -> addWidget(pImpostazioni);

    //connect(apriActionFileMenu, &QAction::triggered, pSveglia, &PannelloSveglia::signalInizializza);
    connect(apriActionFileMenu, &QAction::triggered, [this]()
        {
            sveglieSalvate = ArrayList<SvegliaWidget*>(MioParserJSON::caricaArrayDaFileJson<SvegliaWidget>("E:/Michele/Scuola/Università/2°Anno/Programmazione a Oggetti/MyClock/Salvataggi/Sveglie.json", orologio));

            pSveglia -> inizializzaSveglie(&sveglieSalvate);
        }
    );

    //inizializzazione pannelli a destra
    bmOrologio -> setStyleSheet("background-color: #2e2f30;");
    pSveglia -> setVisible(false);
    pTimer -> setVisible(false);
    pCronometro -> setVisible(false);
    pImpostazioni -> setVisible(false);

    scroll -> setWidget(pdFrame);

    layout -> addWidget(scroll);
}

void App::mostraInformazioni()
{
    InfoDialog i;
    i.setModal(true);
    i.setWindowTitle("Orologio - Informazioni");
    i.exec();
}

void App::orologioActive()
{
    pOrologio -> setVisible(true);
    bmOrologio -> setStyleSheet("background-color: #2e2f30;");
    pSveglia -> setVisible(false);
    bmSveglia -> setStyleSheet("");
    pTimer -> setVisible(false);
    bmTimer -> setStyleSheet("");
    pCronometro -> setVisible(false);
    bmCronometro -> setStyleSheet("");
    pImpostazioni -> setVisible(false);
    bmImpostazioni -> setStyleSheet("");
}

void App::svegliaActive()
{
    pOrologio -> setVisible(false);
    bmOrologio -> setStyleSheet("");
    pSveglia -> setVisible(true);
    bmSveglia -> setStyleSheet("background-color: #2e2f30;");
    pTimer -> setVisible(false);
    bmTimer -> setStyleSheet("");
    pCronometro -> setVisible(false);
    bmCronometro -> setStyleSheet("");
    pImpostazioni -> setVisible(false);
    bmImpostazioni -> setStyleSheet("");
}

void App::timerActive()
{
    pOrologio -> setVisible(false);
    bmOrologio -> setStyleSheet("");
    pSveglia -> setVisible(false);
    bmSveglia -> setStyleSheet("");
    pTimer -> setVisible(true);
    bmTimer -> setStyleSheet("background-color: #2e2f30;");
    pCronometro -> setVisible(false);
    bmCronometro -> setStyleSheet("");
    pImpostazioni -> setVisible(false);
    bmImpostazioni -> setStyleSheet("");
}

void App::cronometroActive()
{
    pOrologio -> setVisible(false);
    bmOrologio -> setStyleSheet("");
    pSveglia -> setVisible(false);
    bmSveglia -> setStyleSheet("");
    pTimer -> setVisible(false);
    bmTimer -> setStyleSheet("");
    pCronometro -> setVisible(true);
    bmCronometro -> setStyleSheet("background-color: #2e2f30;");
    pImpostazioni -> setVisible(false);
    bmImpostazioni -> setStyleSheet("");
}

void App::impostazioniActive()
{
    pOrologio -> setVisible(false);
    bmOrologio -> setStyleSheet("");
    pSveglia -> setVisible(false);
    bmSveglia -> setStyleSheet("");
    pTimer -> setVisible(false);
    bmTimer -> setStyleSheet("");
    pCronometro -> setVisible(false);
    bmCronometro -> setStyleSheet("");
    pImpostazioni -> setVisible(true);
    bmImpostazioni -> setStyleSheet("background-color: #2e2f30;");
}

