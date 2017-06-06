#ifndef ROAD_H
#define ROAD_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QDebug>


class Road:public QGraphicsPixmapItem
{
public:
    Road();
    int x,y;
    Road(int, int, QString);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
protected:
    void advance(int step) override;
};

#endif // ROAD_H
