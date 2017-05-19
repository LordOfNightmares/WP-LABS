#ifndef BALL_H
#define BALL_H
#include <QWidget>
#include <QColor>
#include <QGridLayout>
#include <QPainter>
using namespace std;
class Ball
{
public:

    QColor color;
    int radius;
    int x,y;
    Ball();
    Ball(QColor,int,int,int);
    void paint(QPainter*);
};

#endif // BALL_H
