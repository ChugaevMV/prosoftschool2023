#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    window = new QWidget;

    QTimer *timer = new QTimer(this);

    QRandomGenerator rg;

    int snow_interval = rg.global()->bounded(100,1000);

    timer->start(snow_interval);

    window->resize(500,500);

    //-------------------------------------------

    auto button_new = [this,&snow_interval]()
    {
        QRandomGenerator rg1;

        int x = rg1.global()->bounded(window->frameGeometry().width()-35);
        int y = rg1.global()->bounded(100);

        QPushButton *button = new QPushButton("*",window);

        button->resize(30,30);

        button->move(x,y);

        button->show();

        button->setStyleSheet("background-color: white");

        QTimer *timer_ForButton = new QTimer (this);

        QRandomGenerator rg2;

        int speed = rg2.global()->bounded(300,400);

        timer_ForButton->start(speed);

        //----------------------------------------------------------

        connect(button, &QPushButton::clicked,button,[button](){
            button->deleteLater();
        });

        //----------------------------------------------------------

        auto move_button = [this, button] ()
        {
            int speed_button = button->underMouse() ? 20 : 10;

          if(button->y()+60 >= window->frameGeometry().height())
          {
              window->setWindowTitle("You LOOSE!!!");
              window->setStyleSheet("background-color: red");

              button->deleteLater();
          }
          else
          {
              button->move(button->x(),button->y()+speed_button);
          }
        };

        //-------------------------------------------------------------

        connect(timer_ForButton, &QTimer::timeout, button, move_button);

    };

    //-----------------------------------------------------------------

    connect(timer, &QTimer::timeout, this, button_new);

    window->setWindowTitle("Игра 1");

    window->show();

}

MainWindow::~MainWindow()
{
    window->deleteLater();
}



