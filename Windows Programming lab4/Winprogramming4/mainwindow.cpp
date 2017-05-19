#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->resize(this->geometry().width(), this->geometry().height());
    QWidget *centralWidget = new QWidget(this);
    layout = new QGridLayout(centralWidget);
     layout->setMargin(0);
     setCentralWidget(centralWidget);
     QPainter *painter=new QPainter(this);

    //timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    //timer->start(1000);
    ///
    addball(QColor(255,0,0),50,100,100);
    addball(QColor(0,255,0),50,300,300);
    ///

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event){
    if (painter && balls.size()) balls.at(0).paint(painter);
}

void MainWindow::animate()
{
    repaint();

    qDebug()<<"animate";
}
void MainWindow::addball(QColor color, int radius,int x,int y){
     balls.push_back(Ball(color,radius,x,y));
}
