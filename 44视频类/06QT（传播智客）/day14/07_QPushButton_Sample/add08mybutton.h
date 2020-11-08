#ifndef ADD08MYBUTTON_H
#define ADD08MYBUTTON_H

#include <QWidget>
#include <QPushButton>

class Add08MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit Add08MyButton(QWidget *parent = nullptr);  //这个地方用explicit是啥意思?
    ~Add08MyButton();

signals:

};

#endif // ADD08MYBUTTON_H
