#include "car.h"
#include "eventpool.h"
#include "trafficlight.h"
#include "road.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QStyleOption>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
EventPool *ep;
 TrafficLight *light,*light1,*light2,*light3;
 int seconds = 0;
void swlights(){
    seconds++;
    if(seconds%3==0){ (*light)++;
  ep->swlights();}
//(*light1)++;
//  ep->swlights();
//(*light2)++;
//  ep->swlights();
//(*light3)++;
//  ep->swlights();

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    ep= new EventPool;
    //ep->add(TrafficLight::GREEN);
    qDebug()<<ep;
    QString car1=":/car1.png";
    QString car2=":/car2.png";
    QString road=":/road.png";
    view.resize(602, 602);
    int h=view.height()-2;
    int w=view.width()-2;
     scene.setSceneRect(-w/2, -h/2, w, h);
     scene.setItemIndexMethod(QGraphicsScene::NoIndex);
     scene.addItem(new Road(-w/2,-h/2,road));

    scene.addItem(light=new TrafficLight(20,20,TrafficLight::UP,TrafficLight::GREEN,ep));
    scene.addItem(light1=new TrafficLight(20,20,TrafficLight::DOWN,TrafficLight::GREEN,ep));
    scene.addItem(light2=new TrafficLight(20,20,TrafficLight::LEFT,TrafficLight::RED,ep));
    scene.addItem(light3=new TrafficLight(20,20,TrafficLight::RIGHT,TrafficLight::RED,ep));



    scene.addItem(new Car(0,0,Car::UP,car1,ep));
    scene.addItem(new Car(0,0,Car::DOWN,car2,ep));
    scene.addItem(new Car(0,0,Car::LEFT,car1,ep));
    scene.addItem(new Car(0,0,Car::RIGHT,car2,ep));

    //Graphic render cache and boundaries
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "CrossRoad"));
    view.show();

    QTimer timerscene;
    QTimer timerlights;
    QObject::connect(&timerlights, &QTimer::timeout, [=](){ swlights(); } );


    QObject::connect(&timerscene, SIGNAL(timeout()), &scene, SLOT(advance()));
    timerlights.start(1000 / 1);
    timerscene.start(1000 / 60);

    // view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.QGraphicsView::setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    return a.exec();
}

