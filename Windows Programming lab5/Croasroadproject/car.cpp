#include "car.h"
#include "trafficlight.h"
#include <QGraphicsScene>
#include <QGraphicsView>

Car::Car()
{
}

Car::Car(int x, int y, int dir, QString img,EventPool *pool)
{
    this->pool=pool;

    this->x=x;
    this->y=y;
    this->img=img;
    this->dir=dir;
    QPixmap pixx(this->img);
    this->pix=pixx;
    switch(dir)
    { case UP:this->setPos(x-20,y+300);pix = pix.transformed(QTransform().rotate(0));break;
      case DOWN:this->setPos(x-80,y-400);pix = pix.transformed(QTransform().rotate(180));break;
      case LEFT:this->setPos(x-400,y-20);pix = pix.transformed(QTransform().rotate(90));break;
      case RIGHT:this->setPos(x+300,y-80);pix = pix.transformed(QTransform().rotate(270));break;
   }
   // qDebug()<<this->state;

}
void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem * qs, QWidget * qw)
{

        this->setPixmap(pix.scaledToWidth(100, Qt::SmoothTransformation));
        QGraphicsPixmapItem::paint(painter,qs,qw);


}
QRectF Car::boundingRect() const
{
}

QPainterPath Car::shape() const
{

}

void Car::advance(int step)
{   qreal cx,cy;
    step=2;
    cx=scenePos().x();
    cy=scenePos().y();
    //qDebug() << scenePos().x()<< scenePos().y();
   // qDebug() <<cx<<cy;
    qDebug()<<"HERE"<<this->pool->get();
    switch(this->pool->get())
    {   case TrafficLight::RED:
        step=0;
        break;
        case TrafficLight::YELLOW:
        step=step/2;
        break;
        case TrafficLight::GREEN:
        step=step;
        break;
    }
    switch(dir)
    { case UP:
        cy-=step;
        if (cy==-400) cy=300;
        break;
      case DOWN:
        cy+=step;
        if (cy==300) cy=-400;
        break;
      case LEFT:
        cx+=step;
        if (cx==300) cx=-400;
        break;
      case RIGHT:
        cx-=step;
        if (cx==-400) cx=300;
        break;
   }

   setPos(cx,cy);


}
