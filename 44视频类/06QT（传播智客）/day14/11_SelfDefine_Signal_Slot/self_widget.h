 #ifndef SELF_WIDGET_H
#define SELF_WIDGET_H

#include <QWidget>
#include "teacher.h"
#include "student.h"

class Self_Widget : public QWidget
{
    Q_OBJECT

public:
    Self_Widget(QWidget *parent = nullptr);
    ~Self_Widget();

    Teacher *zt;
    Student *st;

    //下课后
    void classIsOver();
};
#endif // SELF_WIDGET_H
