#include "car.h"
#include "trafficlight.h"
#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
//#include <QPainter>
#include <QStyleOption>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QString car1="C:\\Users\\Sea of Chaos\\Desktop\\University\\WP labs git\\WP-LABS\\Windows Programming lab5\\Croasroadproject\\car1.png";
    QString car2="C:\\Users\\Sea of Chaos\\Desktop\\University\\WP labs git\\WP-LABS\\Windows Programming lab5\\Croasroadproject\\car2.png";
    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

     scene.addItem(new Car(10,10,0,car1));
     TrafficLight *light=new TrafficLight(20,20,TrafficLight::LEFT,TrafficLight::GREEN);
     (*light)++;

    scene.addItem(light);

    QGraphicsView view(&scene);
    QPixmap pim("C:\\Users\\Sea of Chaos\\Desktop\\University\\WP labs git\\WP-LABS\\Windows Programming lab5\\Croasroadproject\\road.png");
    view.setBackgroundBrush(pim.scaledToWidth(400,Qt::SmoothTransformation));
    //Graphic render cache and boundaries
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "CrossRoad"));
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
