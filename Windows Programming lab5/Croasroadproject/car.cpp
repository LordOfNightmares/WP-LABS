#include "car.h"
#include "trafficlight.h"
Car::Car()
{
}
Car::Car(int x, int y, int dir, QString img):QGraphicsPixmapItem(QPixmap(img))
{
    this->x=x;
    this->y=y;
    this->setPixmap(this->pixmap().scaledToWidth(70, Qt::SmoothTransformation));

}
/*void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen pen(this->color);
    painter->setPen(pen);
    QBrush brush(this->color);
    painter->setBrush(brush);
    painter->setBackground(brush);
    painter->drawEllipse(scenePos().x(),scenePos().y(),this->radius,this->radius);
    //
}*/

QRectF Car::boundingRect() const
{
}

QPainterPath Car::shape() const
{

}

void Car::advance(int step)
{

}
