#include "window2.h"

Window2::Window2()
{

}
void Window2::mousePressEvent(QMouseEvent *me)
{

  if(k==0) k++;
  qDebug()<<"Window:"<<k;
  if(k==1) pos=me->pos();
  if(k==2) pos2=me->pos();
  if(k==3) pos3=me->pos();
  if(k==4) {pos4=me->pos(); this->repaint();}
  k++;
}
void Window2::paintEvent(QPaintEvent *event)
{
    if (k!=5){
    QPainter *painter=new QPainter(this);
        QPainterPath path;
        path.moveTo(pos.x(), pos.y());


            path.cubicTo(

                    pos2.x(),pos2.y(),
                    pos3.x(),pos3.y(),
                     pos4.x(),pos4.y());

    painter->drawPath(path);
    qDebug()<<"Window:Reset";
    k=0;}
}
