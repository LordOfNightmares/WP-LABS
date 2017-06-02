#include "trafficlight.h"

TrafficLight::TrafficLight()
{

}
TrafficLight::TrafficLight(int x, int y, int dir,int state)
{
    this->x=x;
    this->y=y;
    this->state=state;
    this->laststate=state;
    this->dir=dir;

}
void TrafficLight::operator ++(int){
    switch(state)
    { case RED:this->state=YELLOW;this->laststate=RED;break;
      case YELLOW:
        if (this->laststate==RED){this->state=GREEN;}
        if (this->laststate==GREEN){this->state=RED;}
            break;
      case GREEN:this->state=YELLOW;this->laststate=GREEN;break;
   }

}
void TrafficLight::paint(QPainter *painter, const QStyleOptionGraphicsItem * qs, QWidget * qw)
{
    QString img;
        switch(this->state)
        {   case RED:
            img="C:\\Users\\Sea of Chaos\\Desktop\\University\\WP labs git\\WP-LABS\\Windows Programming lab5\\Croasroadproject\\Red.png";
            break;
            case YELLOW:
            img="C:\\Users\\Sea of Chaos\\Desktop\\University\\WP labs git\\WP-LABS\\Windows Programming lab5\\Croasroadproject\\Yellow.png";
            break;
             case GREEN:
            img="C:\\Users\\Sea of Chaos\\Desktop\\University\\WP labs git\\WP-LABS\\Windows Programming lab5\\Croasroadproject\\Green.png";
            break;
        }
        QPixmap pix(img);
        pix = pix.scaledToWidth(20, Qt::SmoothTransformation);
        switch(dir)
        { case UP:pix = pix.transformed(QTransform().rotate(0));break;
          case DOWN:pix = pix.transformed(QTransform().rotate(180));break;
          case LEFT:pix = pix.transformed(QTransform().rotate(90));break;
          case RIGHT:pix = pix.transformed(QTransform().rotate(270));break;
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

