#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <qDebug>
#include "ball.h"
#include <vector>
#include <QWidget>
#include <QGridLayout>
#include<QPainter>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;
    vector<Ball> balls;
    void addball(QColor,int,int,int);
    QGridLayout *layout;
    void paintEvent(QPaintEvent*);
    QPainter *painter;


private:
    Ui::MainWindow *ui;
private slots:
    void animate();
};

#endif // MAINWINDOW_H
