#ifndef TrafficLight_H
#define TrafficLight_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QDebug>
#include <QPainter>


class TrafficLight:public QGraphicsPixmapItem
{
public:
    static const int RED = 0;
    static const int YELLOW = 1;
    static const int GREEN = 2;
    static const int UP = 0;
    static const int DOWN = 1;
    static const int LEFT = 2;
    static const int RIGHT = 3;
    TrafficLight();
    int x,y,dir,state,laststate;
    TrafficLight(int, int, int,int);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    void operator ++(int);
protected:
    void advance(int step) override;
};

#endif // TrafficLight_H
