#ifndef WINDOW2_H
#define WINDOW2_H

#include <QWidget>
#include <QGridLayout>
#include <QKeyEvent>
#include <QDebug>
#include <QRadialGradient>
#include <QPushButton>
#include <QKeyEvent>
#include <QPainter>
#include <QDebug>
#include <QLabel>

class Window2:public QWidget

{
public:
    Window2();
public slots:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent*);
    QPoint pos,pos2,pos3,pos4;
    int k=0;

};
#endif // WINDOW2_H
