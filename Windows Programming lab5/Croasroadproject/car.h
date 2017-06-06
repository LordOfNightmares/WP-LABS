#ifndef CAR_H
#define CAR_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QDebug>
#include <trafficlight.h>

class Car:public TrafficLight
{
public:
    TrafficLight *light,*light1,*light2,*light3;
    Car();
    QString img;
    QPixmap pix;
    int x,y,dir;
    qreal speedx,speedy;
    Car(int, int, int, QString);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
protected:
    void advance(int step) override;
};

#endif // CAR_H
