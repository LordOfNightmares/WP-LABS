#ifndef WINDOW2_H
#define WINDOW2_H


#include <QWidget>
#include <QGridLayout>
#include <QKeyEvent>
#include<QPainter>
#include<QDebug>
#include <QRadialGradient>
#include <QPushButton>

class Window2:public QWidget

{
public:
    Window2();
public slots:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent*);
    QPoint pos,pos2,pos3;
    int k;
};

#endif // WINDOW2_H
