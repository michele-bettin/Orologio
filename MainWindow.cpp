#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    app = new App(this);
    setCentralWidget(app);
}

MainWindow::~MainWindow() {}

