#include "window2.h"

Window2::Window2()
{

}
void Window2::mousePressEvent(QMouseEvent *me)
{qDebug()<<"window2";


  if(k==0) pos=me->pos();
  if(k==1) pos2=me->pos();
  if(k==2) pos3=me->pos();
  k++;
  this->repaint();
}
void Window2::paintEvent(QPaintEvent *event)
{

    QPainter *painter=new QPainter(this);
        QPainterPath path;
        path.moveTo(pos.x(), pos.y());


            path.cubicTo(

                    pos2.x(),pos2.y(),
                    pos3.x(),pos3.y(),
                    100,100);



    //QPen pen(QColor(n*51,sqrt(255/n)+sqrt(51*n),255/n),n+2);
    //painter->setPen(pen);
    painter->drawPath(path);
}
