#ifndef MY_WIDGET_H
#define MY_WIDGET_H   //防止头文件，多次编译或重引用

#include <QWidget> //基类

class My_Widget : public QWidget
{
    Q_OBJECT   // 这个宏，写了这个宏，就支持了QT中的信号和槽机制；

public:
    My_Widget(QWidget *parent = nullptr);   //默认参数
    ~My_Widget();
};
#endif // MY_WIDGET_H
