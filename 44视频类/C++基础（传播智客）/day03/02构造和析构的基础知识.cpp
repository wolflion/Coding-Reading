#include <iostream>
using namespace std;


class Test
{};

class Test1{
public:
	Test1()  //无参数构造函数
	{
		cout << "我是一个构造函数" << endl;
	}

	~Test1()
	{
		cout << "我是析构函数" << endl;
	}
};

//给对象搭建一个舞台，研究对象的行为
void objpaly()
{
	Test1 t02;  //局部对象，生命周期结束时，调用析构函数

	//**先创建的对象，后释放**   【先创建before,再创建after】
	Test1 before;
	cout << "分隔一下" << endl;
	Test1 after;
}

int main(int argc, char** argv)
{
	Test t1, t2;//空Test创建对象，编译没有问题

	//Test1 t01;
	objpaly();//这样能看到析构函数的打印输出

	getchar();
	return 0;
}