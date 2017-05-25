#ifndef BALL_H
#define BALL_H
#include <QWidget>
#include <QColor>
#include <QGridLayout>
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
using namespace std;
class Ball:public QGraphicsItem
{
public:

    QColor color;
    int radius;
    int x,y;

    Ball();
    Ball(QColor,int,int,int);
    static vector<Ball> balls;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    void animation();
public slots:

protected:
    void advance(int step) override;
private:
    qreal speedx;
    qreal speedy;
};

#endif // BALL_H
