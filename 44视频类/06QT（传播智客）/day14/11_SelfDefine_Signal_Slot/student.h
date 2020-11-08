#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:  //难怪我的IDE里没有呢，是因为高版本可以去除这个了。

    // 高版本的情况下，可以写在public下，或者 全局函数


    // + 返回类型必须是`void`
    // + 信号需要声明，也需要实现
    // + 信号可以有参数，可以重载
    void treat();

    //重载一下
    void treat(QString foodName);

};

#endif // STUDENT_H
