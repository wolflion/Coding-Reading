#ifndef MY_MAINWINDOW_H
#define MY_MAINWINDOW_H

#include <QMainWindow>

class My_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    My_MainWindow(QWidget *parent = nullptr);
    ~My_MainWindow();
};
#endif // MY_MAINWINDOW_H
