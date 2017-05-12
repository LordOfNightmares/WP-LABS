#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QKeyEvent>
#include<QPainter>
#include<QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGridLayout* layout;
    void paintEvent(QPaintEvent *event);
    bool painted;
    QPolygon mousepoly;
    QPoint center,radius;
    int m=0;
private:
    Ui::MainWindow *ui;
private slots:
     void keyPressEvent(QKeyEvent*);
     void mousePressEvent(QMouseEvent*);
};

#endif // MAINWINDOW_H
