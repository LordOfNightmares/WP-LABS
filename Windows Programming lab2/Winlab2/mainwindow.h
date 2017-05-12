#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QDebug>
#include <QDesktopWidget>
#include <QWindow>
#include <QApplication>
#include <QKeyEvent>
#include <QScrollArea>
#include <QMainWindow>
#include <QString>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QListWidget>
#include <QMenuBar>
#include <QMessageBox>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //static default sizes
    int deskw=QApplication::desktop()->availableGeometry().width();
    int deskh=QApplication::desktop()->availableGeometry().height();
    int windw=640;
    int windh=480;
    QPushButton* CreateButton(QString);
    MainWindow(QWidget *parent = 0);
    QSlider* slider=nullptr;
    QLabel* label;
    QGridLayout* layout;
    int getsliderval;
    QListWidget* listt;
    ~MainWindow();

public slots:
    void itclick();
    void help();
    void ok();
/*----------------------------------methods applied for click events-----------------------------*/
private slots:
   void showscroll();
   void keyPressEvent(QKeyEvent*);
   void sliderValueChanged(int value);

};

#endif // MAINWINDOW_H
