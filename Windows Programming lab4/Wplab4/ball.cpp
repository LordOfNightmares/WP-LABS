#include "ball.h"

Ball::Ball()
{

}
Ball::Ball(QColor color,int radius,int x,int y){
    this->color=color;
    this->radius=radius;
    this->x=scenePos().x();
    this->y=scenePos().y();
    this->speedx=-0.1+rand()%10;
    this->speedy=-0.1+rand()%10;
   // this->scene()->
    qDebug() <<scene()->sceneRect();

}
void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen pen(this->color);
    painter->setPen(pen);
    QBrush brush(this->color);
    painter->setBrush(brush);
    painter->setBackground(brush);
    painter->drawEllipse(scenePos().x(),scenePos().y(),this->radius,this->radius);
    //
}
void Ball::animation(){

}

QRectF Ball::boundingRect() const
{    qreal adjust = 0;
     return QRectF(0 - adjust, 0 - adjust,
                   0 + adjust, 0 + adjust);
}

QPainterPath Ball::shape() const
{

    QPainterPath path;
    path.addRect(-20, -20, 40, 40);
    return path;
}

void Ball::advance(int step)

{
    //this->x=rand()%((300 - 200));
    //this->y=rand()%((300 - 200));
    qreal cx,cy;

    //int wx=sceneBoundingRect()/2-this->radius;
    //int wy=(this->geometry().width()-2)/2-this->radius;
    cx=scenePos().x();
    cy=scenePos().y();
    cx+=speedx;
    cy+=speedy;
    qreal ax,ay;
    ax=speedx+1/(1+rand()%10);
    ay=speedy+1/(1+rand()%10);
   //
    //scene()->it
    if(cx<=-100) {speedx*=-1;if (speedx>=-100) speedy=ay;}
    if(cx>=+100) {speedx*=-1;if (speedx<=100) speedy=ay;}
    if(cy>=+100) {speedy*=-1;if (speedx<=100) speedx=ax;}
    if(cy<=-100) {speedy*=-1;if (speedy>=-100) speedx=ax;}

    ///qDebug() << scenePos().x()<< scenePos().y();
   /* QList<QGraphicsItem *> colision = scene()->collidingItems(this);

    foreach (QGraphicsItem *item, colision) {
        if (item == this)
            continue;
            speedx*=-1;
            speedy*=-1;
        if(this->radius> ((Ball*)item)->radius){
            //scene()->addItem(new Ball(QColor(255,0,0),50,0,0));
            qDebug()<<colision.size();
        }

        }*/

    setPos(cx,cy);

}

