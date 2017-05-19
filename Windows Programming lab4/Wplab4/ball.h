#ifndef BALL_H
#define BALL_H
#include <QWidget>
#include <QColor>
#include <QGridLayout>
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
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
protected:
    void advance(int step) override;
private:
    qreal angle;
    qreal speed;
};

#endif // BALL_H
