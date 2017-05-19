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
void Ball::paint(QPainter* painter)
{
   QPen pen(this->color);
   painter->setPen(pen);
    QBrush brush(this->color);
    painter->setBrush(brush);
    painter->setBackground(brush);
    painter->drawEllipse(this->x,this->y,this->radius,this->radius);

}
