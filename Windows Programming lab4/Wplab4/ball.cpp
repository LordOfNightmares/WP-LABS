#include "ball.h"

Ball::Ball()
{

}
Ball::Ball(QColor color,int radius,int x,int y){
    this->color=color;
    this->radius=radius;
    this->x=x;
    this->y=y;
}
void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
   QPen pen(this->color);
   painter->setPen(pen);
    QBrush brush(this->color);
    painter->setBrush(brush);
    painter->setBackground(brush);
    painter->drawEllipse(this->x,this->y,this->radius,this->radius);

}
void Ball::animation(){

}

QRectF Ball::boundingRect() const
{
}

QPainterPath Ball::shape() const
{

}

void Ball::advance(int step)
{   this->x=rand()%((300 - 200));
    this->y=rand()%((300 - 200));
    qDebug()<<this->x<<this->y;

}

