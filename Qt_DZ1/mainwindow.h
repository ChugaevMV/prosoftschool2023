#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <QPushButton>
#include <QRandomGenerator>
//#include <QWidget>
//#include <QObject>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QWidget *window = nullptr;

};
#endif // MAINWINDOW_H
