#include "car.h"
#include "trafficlight.h"
#include "road.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QStyleOption>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    QString car1=":/car1.png";
    QString car2=":/car2.png";
    QString road=":/road.png";
    view.resize(602, 602);
    int h=view.height()-2;
    int w=view.width()-2;
     scene.setSceneRect(-w/2, -h/2, w, h);
     scene.setItemIndexMethod(QGraphicsScene::NoIndex);
     scene.addItem(new Road(-w/2,-h/2,road));
    TrafficLight *light,*light1,*light2,*light3;
    scene.addItem(light=new TrafficLight(20,20,TrafficLight::UP,TrafficLight::GREEN));
    scene.addItem(light1=new TrafficLight(20,20,TrafficLight::DOWN,TrafficLight::GREEN));
    scene.addItem(light2=new TrafficLight(20,20,TrafficLight::LEFT,TrafficLight::RED));
    scene.addItem(light3=new TrafficLight(20,20,TrafficLight::RIGHT,TrafficLight::RED));
    qDebug()<<light->getstate();
    (*light)++;
    //    (*light1)++;
    //    (*light2)++;
    //    (*light3)++;
    scene.addItem(new Car(0,0,Car::UP,car1));
    scene.addItem(new Car(0,0,Car::DOWN,car2));
    scene.addItem(new Car(0,0,Car::LEFT,car1));
    scene.addItem(new Car(0,0,Car::RIGHT,car2));

    //Graphic render cache and boundaries
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "CrossRoad"));
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));

    timer.start(1000 / 60);

    // view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.QGraphicsView::setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    return a.exec();
}
