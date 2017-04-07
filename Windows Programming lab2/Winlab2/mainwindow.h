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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //static default sizes
    int w=QApplication::desktop()->availableGeometry().width();
    int h=QApplication::desktop()->availableGeometry().height();
    int windW=640;
    int windH=480;

    CreateButton(QString text,int xpos=0,int ypos=0);
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
/*----------------------------------methods applied for click events-----------------------------*/
private slots:
   void showscroll();
   void keyPressEvent(QKeyEvent*);

};

#endif // MAINWINDOW_H
