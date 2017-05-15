#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QWidget *centralWidget = new QWidget(this);
    layout = new QGridLayout(centralWidget);
    layout->setMargin(0);
    setCentralWidget(centralWidget);

       QPixmap pix("C:\\Random_pyramids.jpg");

       QLabel *sampleIconLabel = new QLabel();

       QPixmap scaledPixmap = pix.scaledToWidth(500, Qt::SmoothTransformation);
       this->resize(scaledPixmap.width(),scaledPixmap.height());
       sampleIconLabel ->setPixmap(scaledPixmap);
       layout-> addWidget(sampleIconLabel);




}

MainWindow::~MainWindow()
{
    delete ui;
}
