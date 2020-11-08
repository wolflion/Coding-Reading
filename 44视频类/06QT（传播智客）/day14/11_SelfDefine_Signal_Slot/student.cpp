#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName)
{
    qDebug()<<"请老师吃"<<foodName;

    //输出结果是：  请老师吃 "宫保鸡丁"，想去掉 上面的""
    //QString 转char* 【先转成QByteArray，再转成char*】
    qDebug()<<"请老师吃"<<foodName.toUtf8().data();
}
