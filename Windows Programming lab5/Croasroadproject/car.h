#ifndef CAR_H
#define CAR_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QDebug>


class Car:public QGraphicsPixmapItem
{
public:

    Car();
    int x,y,dir,state,laststate;
    Car(int, int, int, QString);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
protected:
    void advance(int step) override;
};

#endif // CAR_H
