#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{   //Debugging
    //qDebug() << QApplication::desktop()->availableGeometry(); //q object output
    //this->setGeometry(QRect(100,100,400,400));
    qDebug() << "Width:"<<this->geometry().width()<<deskw<<"\nHeight:"<< this->height()<<deskh;

    QPushButton* btn_addscroll=new QPushButton(this);
    //CreateButton(btn_addscroll,"text",20,20);
    btn_addscroll->setStyleSheet("background: rgb(255,20,36);");//set style of button CSS format
    btn_addscroll->move(20, 20);        //button possition
    btn_addscroll->setText("Add Scrollbar");//button txt
    btn_addscroll->show();             //show button
    this->setGeometry((deskw-windw)/2,(deskh-windh)/2,windw,windh); //fix possition size,place


    //connect slot with signal|connect(object we want to call,source of signal,where whe are going to recieve the signal,what to do);
    connect(btn_addscroll,QPushButton::clicked,this,MainWindow::showscroll);

}

MainWindow::~MainWindow()
{

}

/*void MainWindow::CreateButton(btn,text,xpos,ypos)
{
    //creating button
    btn->setStyleSheet("background: rgb(255,30,36);");//set style of button CSS format
    btn->move(xpos, ypos);        //button possition
    btn->setText(text);//button txt
    btn->show();                   //show button
    return btn;
}*/
void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key() == Qt::Key_A && ke->modifiers().testFlag(Qt::ControlModifier)) {
        windh+=100;
        windw+=100;
        this->setGeometry((deskw-windh)/2,(deskh-windh)/2,windw,windh);
        qDebug() <<"Resize"<<"\nWidth:"<<this->geometry().width() <<"\nHeight:"<< this->height();  }
    if(ke->key() == Qt::Key_S && ke->modifiers().testFlag(Qt::ControlModifier)) {
        windh-=100;
        windw-=100;
        this->setGeometry((deskw-windh)/2,(deskh-windh)/2,windw,windh);
        qDebug() <<"Resize"<<"\nWidth:"<<this->geometry().width() <<"\nHeight:"<< this->height();  }
}

void MainWindow::showscroll()
{
       QScrollArea* List = new QScrollArea(this);
       List->setGeometry(0,60,this->geometry().width(),this->geometry().height()-60);
       List->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
       List->show();
       qDebug() <<"Scroll";
}
