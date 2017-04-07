#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{   QPushButton* btn_addscroll=new QPushButton(this);
    btn_addscroll->setStyleSheet("background: rgb(255,20,36);");//set style of button CSS format
    btn_addscroll->move(20, 20);        //button possition
    btn_addscroll->setText("Add Scrollbar");//button txt
    btn_addscroll->show();             //show button
    this->setGeometry(w/2-windW/2,h/2-windH/2,windW,windH); //fix possition size,place
    //qDebug() << QApplication::desktop()->availableGeometry(); //q object output
    //this->setGeometry(QRect(100,100,400,400));
    //Debugging
    qDebug() << "Width:"<<this->geometry().width() <<"\nHeight:"<< this->height();

    /*connect slot with signal
     *connect(object we want to call,source of signal,where whe are going to recieve the signal,what to do);*/
    connect(btn_addscroll,QPushButton::clicked,this,MainWindow::showscroll);

}

MainWindow::~MainWindow()
{

}
/*
void MainWindow::CreateButton(text,xpos,ypos)
{
    //creating button
    QPushButton* btn_addscroll=new QPushButton(this);
    btn_addscroll->setStyleSheet("background: rgb(255,20,36);");//set style of button CSS format
    btn_addscroll->move(xpos, ypos);        //button possition
    btn_addscroll->setText(text);//button txt
    btn_addscroll->show();                   //show button
    return btn_addscroll;
}*/
void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key() == Qt::Key_A && ke->modifiers().testFlag(Qt::ControlModifier)) {
        windH+=200;
        windW+=200;
        this->setGeometry(w/2-windW/2,h/2-windH/2,windW,windH);
        qDebug() <<"Resize";  }
}

void MainWindow::showscroll()
{
       QScrollArea* List = new QScrollArea(this);
       List->setGeometry(0,60,200,456);
       List->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
       List->show();
       qDebug() <<"Scroll";
}
