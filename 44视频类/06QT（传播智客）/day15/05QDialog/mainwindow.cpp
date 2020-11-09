#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击新建菜单项，弹出对话框
    //actionNew属于Qaction类
    connect(ui->actionNew,&QAction::triggered,this,[=](){


        //非模态对话框 （堆上会一闪而过）
//        QDialog dlg2(this);
//        dlg2.resize(200,100);
//        dlg2.show(); //创建在栈上，窗口会一闪而过

        QDialog *dlg2 = new QDialog(this);  //创建在堆上，多点几次后，当时不会释放
        dlg2->resize(200,100);
        dlg2->show();
        //需要设置属性dlg2
        // 关闭当前窗口后，手工调用释放
        dlg2->setAttribute(Qt::WA_DeleteOnClose);//本类找不到，就去父类找一下，在文档中

        //模态
//        QDialog dlg(this);
//        dlg.resize(200,100);
//        dlg.exec();  //阻塞操作
//        qDebug()<<"模态对话框关闭后，才弹出对话框!";
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

