#include "my_widget.h"

#include <QApplication>  // Ӧ�ó����ͷ�ļ�

// �������  agrc�����б��������� argv�����б�������
int main(int argc, char *argv[])
{
    // Ӧ�ó������a����QT�����ҽ���һ��
    QApplication a(argc, argv);

    //����һ���Զ�����Ķ��� My_Widget��Ļ����� QWidget
    My_Widget w;

    // ����Ĭ���ǲ��ᵯ���ģ�����뵯��������show()����
    w.show();

    // a.exec()������Ϣѭ�����ƣ��൱��puase����Ȼ�������ѭ����
    return a.exec();
}
