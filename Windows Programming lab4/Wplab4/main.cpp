#include "ball.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsView>
#include <QTimer>
void mousePressEvent(QMouseEvent*);

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
        //balls.push_back(Ball(QColor(255,i*50,0),50,i * 6.28,i * 6.28))
     scene.addItem(new Ball(QColor(255,0,0),50,0,0));
     //scene.addItem(new Ball(QColor(0,255,0),80,60,60));
    scene.setBackgroundBrush(QBrush(QColor(200,200,200)));
    QGraphicsView view(&scene);
    //Graphic render cache and boundaries
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Coliding balls"));
    view.resize(602, 602);
    //qDebug()<<(view.geometry().width()-2)/2-radius;

    view.show();
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 60);
    // view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.QGraphicsView::setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    qDebug() <<scene.sceneRect();


    return a.exec();
}
/*
void main:(QMouseEvent *me)
{   qDebug()<<SIGNAL(clicked());
    if(me->button()==Qt::LeftButton){
    scene.addItem(new Ball(QColor(255,0,0),50,0,0));}

    //if(me->button()==Qt::RightButton)

}*/

