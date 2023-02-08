#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "App.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    App *app;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};
#endif // MAINWINDOW_H
