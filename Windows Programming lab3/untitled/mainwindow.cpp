#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setGeometry(40,40,geometry().width()+200,geometry().height()+200);
    painted=true;
    connect(CreateButton("text"),QPushButton::clicked,this,MainWindow::createwindow);

}

MainWindow::~MainWindow()
{
}
void MainWindow::createwindow(){
    window.resize(this->geometry().width(), this->geometry().height());
    window.setWindowTitle
          (QApplication::translate("childwidget", "Child widget"));
    window.show();
    //connect(&window,Q,this,SLOT(repaint()));

}
void MainWindow::debug()
{
    qDebug()<<SIGNAL(clicked());
}

QPushButton* MainWindow::CreateButton(QString text)
{
     QPushButton* btn=new QPushButton(this);
    //creating button
    //this->addWidget(btn,Qt::AlignRight);
    btn->setStyleSheet("background: rgb(255,30,36);");//set style of button CSS format
    btn->move(geometry().width()-btn->width(), btn->y());        //button possition
    btn->setText(text);//button txt
    btn->show();

    return btn;
}
void MainWindow::keyPressEvent(QKeyEvent *ke)
{ if(ke->key()==Qt::Key_F5) {painted=true;
    repaint();}
}


void MainWindow::mousePressEvent(QMouseEvent *me)
{if(me->button()==Qt::LeftButton){
    mousepoly<<me->pos();
    painted=true;
    repaint();}

    if(me->button()==Qt::RightButton){
        if(m==0) center=me->pos();
        if(m==1) radius=me->pos();
      m++;
      painted=true;
      repaint();
    }

}
void MainWindow::paintEvent(QPaintEvent *event)
{
    if (painted){

    //QWidget *l=new QWidget(this);
    //this->addWidget(l,1,1,1,6);
    QPainter *painter=new QPainter(this);
    int k=0;
    //lines
    for(int i=1;i<=5;i++)
{
    QPen pen(QColor(i*51,sqrt(255/i)+sqrt(51*i),255/i),i+2);
    painter->setPen(pen);
    painter->drawLine(20+k,20+k,300,20+k);
    k+=10;
    }
    //bezier


    for(int n=1;n<=2;n++){
        QPainterPath path;
        path.moveTo(20+n*20, 100);
    for(int i=1;i<=1;i++)
    {path.cubicTo(
                    rand()%geometry().width()/3,rand()%geometry().height()/3,
                    rand()%geometry().width()/3,rand()%geometry().height()/3,
                    rand()%geometry().width()/2,rand()%geometry().height()/2);



    }QPen pen(QColor(n*51,sqrt(255/n)+sqrt(51*n),255/n),n+2);
    painter->setPen(pen);
    painter->drawPath(path);}
    painted=false;

   //4 objects
    QPen pen(QColor(100,30,100),2);
    painter->setPen(pen);
    QBrush brush(QColor(100,30,100));
    painter->setBrush(brush);
    painter->setBackground(brush);
    painter->drawRect(20,150,100,60);
    painter->drawEllipse(20,230,60,60);
    painter->drawPie(100,230,100,100,0,90*16);
    QPolygon polyg;
    polyg<<QPoint(20,400)<<QPoint(100,300)<<QPoint(150, 350)<<QPoint(100, 400);
    painter->drawPolygon(polyg);
    QRadialGradient colorr(100,500,50);
    colorr.setColorAt(0,QColor(255,0,0));
    colorr.setColorAt(1,QColor(0,255,200));
    painter->setBrush(colorr);
    painter->drawEllipse(75,475,50,50);

    //mouse
    if (mousepoly.length()) painter->drawPolygon(mousepoly);
    //mouse2
    if (m>1){int rad=sqrt(pow(center.x()-radius.x(),2)+pow(center.y()-radius.y(),2));
    painter->drawEllipse(center,rad,rad);
    m=0;
}
}
}
