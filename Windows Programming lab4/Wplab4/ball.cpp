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
    path.addRect(0,0, 50, 50);
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
    if(cx<=-150) {speedx*=-1;if (speedx>=-150) speedy=ay;}
    if(cx>=+125) {speedx*=-1;if (speedx<=125) speedy=ay;}
    if(cy>=+125) {speedy*=-1;if (speedx<=125) speedx=ax;}
    if(cy<=-150) {speedy*=-1;if (speedy>=-150) speedx=ax;}

    ///qDebug() << scenePos().x()<< scenePos().y();
    QList<QGraphicsItem *> colision = scene()->collidingItems(this);

    foreach (QGraphicsItem *item, colision) {
        if (item == this)
            continue;
        if(this->radius>=((Ball*)item)->radius && colision.size()<=1){

            //scene()->addItem(new Ball(QColor(255,0,0),50,0,0));
            qDebug()<<colision.size();
        }
        speedx*=-1;
        if (speedx>=-125) speedy=ay;
        speedy*=-1;
        if (speedy<=125) speedx=ax;

        }

    setPos(cx,cy);

}

