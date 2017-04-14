#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QDebug>
#include <QDesktopWidget>
#include <QWindow>
#include <QApplication>
#include <QKeyEvent>
#include <QScrollArea>
#include <QMainWindow>
#include <QString>
#include <QSlider>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //static default sizes
    int deskw=QApplication::desktop()->availableGeometry().width();
    int deskh=QApplication::desktop()->availableGeometry().height();
    int windw=640;
    int windh=480;
    //CreateButton(QPushButton* btn,QString text,int xpos=0,int ypos=0);
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
/*----------------------------------methods applied for click events-----------------------------*/
private slots:
   void showscroll();
   void keyPressEvent(QKeyEvent*);

};

#endif // MAINWINDOW_H
