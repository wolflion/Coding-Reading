#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //通过ui寻找控件
    //ui->actionNew->setIcon(QIcon("C:/Windows/Web/Screen/img103.png")); //这是本地的

    //添加资源文件 到项目中

    // 使用资源文件“ : + 前缀名 + 文件名”
    ui->actionNew->setIcon(QIcon(":/Image/v029_24.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

