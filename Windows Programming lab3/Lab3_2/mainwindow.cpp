#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    QPixmap pixmap("background.png");
    QRegion exposed;
    pixmap.load("background.png");
    pixmap.scroll(10, 10, pixmap.rect(), &exposed);



}

MainWindow::~MainWindow()
{
    delete ui;
}
