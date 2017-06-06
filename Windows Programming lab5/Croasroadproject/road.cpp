#include "road.h"




Road::Road()
{

}
Road::Road(int x, int y,QString img):QGraphicsPixmapItem(QPixmap(img))
{
    this->x=x;
    this->y=y;
    this->setPos(x,y);
    this->setPixmap(this->pixmap().scaledToWidth(600, Qt::SmoothTransformation));


}
/*void Road::paint(QPainter *painter, const QStyleOptionGraphicsItem * qs, QWidget * qw)
{


    QGraphicsPixmapItem::paint(painter,qs,qw);

}*/
QRectF Road::boundingRect() const
{
}

QPainterPath Road::shape() const
{

}

void Road::advance(int step)
{

}

