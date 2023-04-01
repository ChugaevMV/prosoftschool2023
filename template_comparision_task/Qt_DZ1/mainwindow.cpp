#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    window = new QWidget;

    QTimer *timer = new QTimer(this);

    int snow_interval = rg->bounded(100,1000);

    timer->start(snow_interval);

    window->resize(500,500);

    //-------------------------------------------

    auto button_new = [=]()
    {
        int x = rg->bounded(window->frameGeometry().width()-35);
        int y = rg->bounded(100);

        QPushButton *button = new QPushButton("*",window);

        button->resize(30,30);

        button->move(x,y);

        button->show();

        button->setStyleSheet("background-color: white");

        QTimer *timer_ForButton = new QTimer (this);

        int speed = rg->bounded(250,400);

        timer_ForButton->start(speed);

        //--------------------------------------

        auto delete_button = [=] ()
        {
            delete button;
        };

        //----------------------------------------------------------

        connect(button, &QPushButton::clicked,button,delete_button);

        //----------------------------------------------------------

        auto move_button = [=] () mutable
        {
            int y_button, x_button;

            QPoint cursor = window->mapFromGlobal(QCursor::pos());

            if(((cursor.x() > button->x())&&(cursor.x() < button->x()+30)) && ((cursor.y() > button->y())&&(cursor.y() < button->y()+30)))
            {

                timer_ForButton->start(speed/2);
            }
            else
            {
                timer_ForButton->start(speed);
            }


          if(button->y()+60 >= window->frameGeometry().height())
          {
              window->setWindowTitle("You LOOSE!!!");
              window->setStyleSheet("background-color: red");

          }
          else
          {
              y_button = button->y()+10;
              x_button = button->x();

              button->move(x_button,y_button);
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

}



