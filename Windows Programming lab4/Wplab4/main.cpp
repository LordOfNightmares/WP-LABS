#include "ball.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsView>
#include <QTimer>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
        //balls.push_back(Ball(QColor(255,i*50,0),50,i * 6.28,i * 6.28))
     scene.addItem(new Ball(QColor(255,0,0),50,100,100));
     scene.addItem(new Ball(QColor(0,255,0),50,30,100));

    QGraphicsView view(&scene);
    //Graphic render cache and boundaries
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Coliding balls"));
    view.resize(620, 620);
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 33);


    return a.exec();
}
