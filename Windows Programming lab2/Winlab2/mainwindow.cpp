#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{    this->setGeometry((deskw-windw)/2,(deskh-windh)/2,windw,windh); //fix possition size,place
     qDebug() << "Width:"<<this->geometry().width()<<deskw<<"\nHeight:"<< this->height()<<deskh;
     slider = new QSlider();
     slider->setMaximum(359);
     label = new QLabel("No Data");




    //Debugging qDebug() << QApplication::desktop()->availableGeometry(); //q object output
    //Positionform this->setGeometry(QRect(100,100,400,400));

/*
    btn_addscroll->setStyleSheet("background: rgb(255,20,36);" + color);//set style of button CSS format
    btn_addscroll->move(20, 20);        //button possition
    btn_addscroll->setText("Add Scrollbar");//button txt
    btn_addscroll->show();             //show button*/
    QWidget *centralWidget = new QWidget(this);
    layout = new QGridLayout(centralWidget);
    layout->setMargin(0);
     setCentralWidget(centralWidget);
//    layout->setRowStretch(1, 1);
//     layout->setRowStretch(2, 10);


    //QScrollArea* List = new QScrollArea(this);
    listt=new QListWidget(this);

    layout->addWidget(listt,1,2,40,4,Qt::AlignTop);
    QMenuBar *menuBar = new QMenuBar(this);
    layout->addWidget(menuBar,0,1,1,4);

    QMenu *filemenu=new QMenu("File");
    QMenu *filemenu2=new QMenu("Help");
    QMenu *filemenu3=new QMenu("Ok");

    QAction *exit = new QAction("exit");
    QAction *help = new QAction("About");
    QAction *ok = new QAction("ok");

    menuBar->addMenu(filemenu);
    menuBar->addMenu(filemenu2);
    menuBar->addMenu(filemenu3);
    filemenu->addAction(exit);
    filemenu2->addAction(help);
    filemenu3->addAction(ok);
    connect(exit, &QAction::triggered, this, &MainWindow::close);
    connect(help, &QAction::triggered, this, &MainWindow::help);
    connect(ok, &QAction::triggered, this, &MainWindow::ok);


    // connect(, QMenu::triggered, this, MainWindow::help);

    //listt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
     for(int i=1;i<20;i++) {

     listt->addItem("Color" + QString::number(i));

     }connect(listt,QListWidget::itemClicked,this,MainWindow::itclick);

    QString color2 = "yellow";

    // qDebug()<<slider->SLOT(sliderValueChanged(int));
    //

    connect(CreateButton("text"),QPushButton::clicked,this,MainWindow::showscroll);
    //connect slot with signal|connect(object we want to call,source of signal,where whe are going to recieve the signal,what to do);


}

MainWindow::~MainWindow()
{

}
void MainWindow::help()
{
    QMessageBox msgBox;
    msgBox.setText("You get no help from me.\nAsk google.");
    msgBox.exec();
}
void MainWindow::ok()
{
    QMessageBox msgBox;
    msgBox.setText("OK");
    msgBox.exec();
}
void MainWindow::itclick()
{
    listt->setStyleSheet("background:hsl(" +QString::number(360/20*listt->currentRow())+ ",90%,90%);");

}

QPushButton* MainWindow::CreateButton(QString text)
{
     QPushButton* btn=new QPushButton(this);
    //creating button
    layout->addWidget(btn,1,1,1,1,Qt::AlignLeft);
    btn->setStyleSheet("background: rgb(255,30,36);");//set style of button CSS format
    //btn->move(xpos, ypos);        //button possition
    btn->setText(text);//button txt
    btn->show();

    return btn;
}
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
     /* QScrollArea* List = new QScrollArea(this);
       List->setGeometry(0,60,this->geometry().width(),this->geometry().height()-60);
       List->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
       List->show();*/



    qDebug() << layout->geometry();
    layout->addWidget(slider,4,1,2,2);
    layout->addWidget(label,3,1,1,2);
    label->setStyleSheet("background:transparent;");
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(sliderValueChanged(int)));
    //qDebug() <<sliderValueChanged(int);
    qDebug() <<"Scroll";
}
void  MainWindow::sliderValueChanged(int value)
    {
        label->setText("Slider Value is: "+ QString::number(value) );
        this->setStyleSheet("background:hsl("+QString::number(value)+",90%,90%);");

    }
