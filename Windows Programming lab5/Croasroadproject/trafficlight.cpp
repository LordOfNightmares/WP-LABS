#include "trafficlight.h"


TrafficLight::TrafficLight()
{

}
TrafficLight::TrafficLight(int x, int y, int dir,int state,EventPool* pool)
{   //qDebug() <<pool;
    this->pool=pool;
    this->x=x;
    this->y=y;
    this->state=state;
    this->laststate=state;
    this->dir=dir;


}
void TrafficLight::operator ++(int){
    qDebug() << this->pool;
    switch(state)
    { case RED:this->state=YELLOW;this->laststate=RED;this->pool->add(YELLOW);break;
      case YELLOW:
        if (this->laststate==RED){this->state=GREEN;this->pool->add(GREEN);}
        if (this->laststate==GREEN){this->state=RED;this->pool->add(RED);}
            break;
      case GREEN:this->state=YELLOW;this->laststate=GREEN;this->pool->add(YELLOW);break;
   }

}
void TrafficLight::paint(QPainter *painter, const QStyleOptionGraphicsItem * qs, QWidget * qw)
{

    QString img;
        switch(this->state)
        {   case RED:
            img=":/Red.png";
            break;
            case YELLOW:
            img=":/Yellow.png";
            break;
             case GREEN:
            img=":/Green.png";
            break;
        }
        QPixmap pix(img);
        pix = pix.scaledToWidth(20, Qt::SmoothTransformation);
        switch(dir)
        { case UP:this->setPos(x+55,y+55);pix = pix.transformed(QTransform().rotate(0));break;
          case DOWN:this->setPos(x-115,y-150);pix = pix.transformed(QTransform().rotate(180));break;
          case LEFT:this->setPos(x-150,y+55);pix = pix.transformed(QTransform().rotate(90));break;
          case RIGHT:this->setPos(x+55,y-115);pix = pix.transformed(QTransform().rotate(270));break;
       }
        this->setPixmap(pix);

     QGraphicsPixmapItem::paint(painter,qs,qw);

}

QRectF TrafficLight::boundingRect() const
{
}

QPainterPath TrafficLight::shape() const
{

}

void TrafficLight::advance(int step)
{

}
int TrafficLight::getstate()
{return state;}
