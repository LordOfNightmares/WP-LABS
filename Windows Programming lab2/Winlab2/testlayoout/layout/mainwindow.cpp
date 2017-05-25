#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this-> adjustw();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::adjustw(){
    QWidget *content = new QWidget(this);
    this->setCentralWidget(content);
    qDebug()<<"okokojo";
    QVBoxLayout* Lvertical=new QVBoxLayout;
    QWidget *centers=new QWidget(this);
    content->setStyleSheet("background-color:red;");
    centers->setStyleSheet("background-color:green;");
   // centers->;
    QPushButton *B1=new QPushButton("Button 1");
    QPushButton *B2=new QPushButton("Button 2");
    Lvertical->addWidget(B1,1,Qt::AlignTop);
    Lvertical->addWidget(centers,1,Qt::AlignCenter);
    Lvertical->addWidget(B2,1,Qt::AlignBottom);
    content->setLayout(Lvertical);
    QHBoxLayout * Lhor=new QHBoxLayout;
    centers->setLayout(Lhor);
    centers->setSizePolicy(QSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored));
    QPushButton *B3=new QPushButton("Button 3");
    QPushButton *B4=new QPushButton("Button 4");
    B3->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
    B4->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));

    Lhor->addWidget(B3,1,Qt::AlignLeft);
    QSlider *slider = new QSlider();
    slider->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
    slider->setMaximumHeight(400);
    Lhor->addWidget(slider,1,Qt::AlignCenter);
    Lhor->addWidget(B4,1,Qt::AlignRight);
Lhor->setSpacing(0);
Lvertical->setSpacing(0);
Lvertical->setMargin(100);
Lhor->setStretch(1,1);




//    QHBoxLayout* VH=new QHBoxLayout();
//    R1->setLayout(VH);



}
