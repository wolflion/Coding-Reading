 #include "add08mybutton.h"
#include <QDebug> //这是个新增的

Add08MyButton::Add08MyButton(QWidget *parent) : QPushButton(parent) //修改为QPushButton
{

}


Add08MyButton::~Add08MyButton()
{
    qDebug()<<"Add08MyButton的析构";
}
