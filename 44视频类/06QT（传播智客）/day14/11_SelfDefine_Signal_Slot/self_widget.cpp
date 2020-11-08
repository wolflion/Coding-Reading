#include "self_widget.h"
#include <QPushButton>

//需求：创建两个类 Teacher Studeng
// 下课后，老师 zt会发出一个信号  饿了
// 学生 st 响应信号  处理信号的槽函数 请客吃饭

Self_Widget::Self_Widget(QWidget *parent)
    : QWidget(parent)
{
    zt = new Teacher(this); // 相当于把老师放到了child表里，这样可以自动释放

    //不写这个this时，需要手动析构
    st = new Student(this);


    //连接老师和学生   【时机是，下课后】
    //connect(zt,&Teacher::hungry,st,&Student::treat);

    //有参数的 信号和槽连接
    // 函数指针：执行函数地址
    void(Teacher::*teacherSignal)(QString) = &Teacher::hungry;
    void(Student::*stSlot)(QString) =&Student::treat;

    connect(zt,teacherSignal,st,stSlot);


    // 下课
    classIsOver();

    //13、信号和槽的扩展
    // 点击按钮 才下课
    QPushButton *btn1 = new QPushButton("下课",this);
    //触发无参  信号和槽
    // 信号连接信号
    //connect(btn1,&QPushButton::clicked,zt,&Teacher::hungry);  //错误的原因是hungry不明确
    void(Teacher::*noteacherSignal)(void) = &Teacher::hungry;
    void(Student::*nostSlot)(void) =&Student::treat;
    connect(btn1,&QPushButton::clicked,zt,noteacherSignal);  //信号连接信号

    //connect(btn1,&QPushButton::clicked,this,&QWidget::close); //一个信号可以连接多个槽函数，这个就关闭窗口了。
    connect(zt,noteacherSignal,st,nostSlot);

    // 断开连接，再 点击下课按钮，就不好使了。
    //disconnect(zt,noteacherSignal,st,nostSlot);

    btn1->move(100,200);  //不move()会被后面的btn遮住，自己临时加的；

    //重置大小
    resize(600,400);

    //15， 测试lambda表达式写法
    QPushButton *btn = new QPushButton("aaaa",this);

    // 值传递，这只是函数声明。  【函数调用，后面要加()才行】
    //[](){ //如果前面没有 = 或者 &时，就不行，在这个地方就不行。
    [=](){
        btn->setText("bbbb");
    }();
}


void Self_Widget::classIsOver()
{
    //触发老师饿了的信号
    // 触发自定义信号关键字  emit
    emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

Self_Widget::~Self_Widget()
{
}

