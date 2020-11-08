#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义的信号，要写到 signals 下面

    //+ 返回类型必须是`void`
    //+ 信号只需要声明，不需要实现
    //+ 信号可以有参数，可以重载
    void hungry();

    // 重载
    void hungry(QString foodName);

};

#endif // TEACHER_H
