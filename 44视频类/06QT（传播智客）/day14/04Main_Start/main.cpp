#include "my_widget.h"

#include <QApplication>  // 应用程序的头文件

// 程序入口  agrc命令行变量数量； argv命令行变量数组
int main(int argc, char *argv[])
{
    // 应用程序对象a，在QT中有且仅有一个
    QApplication a(argc, argv);

    //创建一个自定义类的对象； My_Widget类的基类是 QWidget
    My_Widget w;

    // 窗口默认是不会弹出的，如果想弹出，调用show()方法
    w.show();

    // a.exec()进入消息循环机制，相当于puase，不然会进入死循环。
    return a.exec();
}
