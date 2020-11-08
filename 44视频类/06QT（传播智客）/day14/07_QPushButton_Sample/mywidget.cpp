#include "mywidget.h"
#include <QPushButton>  // 本次新增
#include <add08mybutton.h> //08课新增
#include <QDebug> //这是个新增的

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    // 这是创建按钮的第1种方式，选中用ctrl+/来块注释或释放注释
    //按钮
    QPushButton *btn = new QPushButton;  //调用无参默认构造

    //show是用顶层方式弹出；如果想在MyWidget窗口中显示，就需要依赖MyWidget窗口
    //btn->show();  //这个会在主窗口下面出现

    // 设置 父亲
    btn->setParent(this);  // 这里用this代替

    // 设置文字
    btn->setText("德玛西亚"); // 将char* 隐式类型转为QString

    // 创建按钮的第2种方式，窗口会按照btn2大小进行显示
    QPushButton *btn2 = new QPushButton("第二按钮",this);//有()时，叫有参构造
    this->resize(600,400);

    //移动第2个按钮
    btn2->move(100,100);  //如果不移动，会覆盖第1个按钮，所以要移动一下

    //按钮是否可以 重置大小resize？【答案是可以的，因为他们有共同的父类】
    btn2->resize(50,50);

    //设置窗口标题（原来叫07_QPushButton_Sample）
    setWindowTitle("Qt第一个窗口"); //this可省略

    //设置固定窗口大小
    setFixedSize(600,400);  //这样大家就不能拖放大小

    // 08对象树的知识
    // 一定程度上简化了内存回收机制  对象树（对象模型）的机制，之前new的，可以不用自己释放。

    //创建自己的按钮
    Add08MyButton *myBtn = new Add08MyButton;
    myBtn->setText("我的按钮");
    myBtn->move(200,200);
    myBtn->setParent(this);   //new出来的对象，只要设置了this，就不用自己管。


    // 10信号槽相关知识
    // 点击 myBtn 关闭窗口
    // 参数1 信号的发送者  参数2 发送的信号  参数3 信号的接受者 参数4 处理的槽函数
    connect(myBtn,&Add08MyButton::clicked,this,&MyWidget::close);

    //也可以用父类的进行替换
    //connect(myBtn,&QPushButton::clicked,this,&Widget::close);
}

MyWidget::~MyWidget()
{
     qDebug()<<"MyWidget的析构";  //先打印，找到最后的子节点后，再一层层删，先析构底层。
}
