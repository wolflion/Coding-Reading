#include "my_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QWidget>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

My_MainWindow::My_MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //01 包含 菜单栏（只能有一个)
    QMenuBar *bar = menuBar();
    // 将菜单栏放入到窗口中
    this->setMenuBar(bar);  //如果没有菜单栏没有菜单，还是没有显示

    //创建文件菜单
    QMenu *fileMenu = bar->addMenu("文件");  // 需要引入<QMenuBar>头文件
    QMenu *editMenu = bar->addMenu("编辑");

    //添加菜单项
    QAction *newAction = fileMenu->addAction("新建");
    // 菜单项之间有个分隔线
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");


    // 02 工具栏  有多个
    // 需要<QToolBar>头文件
    QToolBar *toolBar = new QToolBar(this);
    //addToolBar(toolBar);//这是原有的，默认是停靠在上面
    addToolBar(Qt::LeftToolBarArea,toolBar);

    //设置只停靠在左侧，右侧
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    //设置浮动
    toolBar->setFloatable(false);

    //设置移动（总开关）
    toolBar->setMovable(false);

    // 工具栏添加菜单项
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    // 03设置状态栏，状态栏只有1个
    QStatusBar *stBar = statusBar();
    setStatusBar(stBar);  //把状态栏放入到窗口中
    QLabel *label = new QLabel("提示信息",this);
    stBar->addWidget(label);  //添加提示信息在左侧

    QLabel *labelRight = new QLabel("右侧提示信息");
    stBar->addPermanentWidget(labelRight);  //添加提示信息在右侧

    // 04 锚接控件，也叫 **浮动窗口**，可以有多个
    QDockWidget *dock = new QDockWidget;
    //添加锚接控件到窗口中
    addDockWidget(Qt::BottomDockWidgetArea,dock);  // 因为没有核心部件，所以才显示在上侧

    // 设置停靠范围
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    // 05 核心控件 （只能有一个）
    QTextEdit *edit = new QTextEdit;  //相当于文本编辑框
    setCentralWidget(edit);
}

My_MainWindow::~My_MainWindow()
{
}

