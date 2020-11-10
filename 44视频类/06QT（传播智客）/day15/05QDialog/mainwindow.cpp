#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>

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

        // 06、使用标准对话框 QMessageBox  【静态的成员方法，要注意用法】
        //错误对话框
        //QMessageBox::critical(this, "错误!"，"critical");  //错误是：标题；critical是内容。
        //信息对话框
        QMessageBox::information(this, "信息!"，"info");

        //提问对话框 
        //参数1、父亲 ；参数2 标题；参数3、提示内容；参数4、按键类型；
        //QMessageBox::question(this, "问题?", "question", QMessageBox::Save |  QMessageBox::Cancel, QMessageBox::Cancel);//第5个参数是，关联回车的默认按钮
        //这个返回值的类型，就是参数4的类型
        if (QMessageBox::Save == QMessageBox::question(this, "问题?", "question", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
        {
            qDebug() << "点击的是保存";
        }
        else
        {
            qDebug() << "点击的是取消";
        }

        //警告对话框
        QMessageBox::warning(this, "警告!"，"warning");

        // 07、标准对话框--颜色对话框 和文件对话框
        QColor color = QColorDialog::getColor(QColor(255,0,0));//默认不写是白色 Qt::white
        qDebug() << color.red() << color.green() << color.blue();

        //文件对话框
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "","(*.txt *.png)"); //最后是过滤文件类型
        qDebug() << path;
         
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

