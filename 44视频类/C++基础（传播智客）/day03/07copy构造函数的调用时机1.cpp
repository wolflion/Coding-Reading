#include <iostream>
using namespace std;


class Test7
{
public:
	Test7()
	{
		m_a = 0;
		m_b = 0;
		cout << "无参构造函数" << endl;
	}
	Test7(int a, int b)
	{
		m_b = b;
		m_a = a;
		cout << "有参构造函数" << endl;
	}

	//赋值构造函数
	Test7(const Test7& obj)
	{
#if 0
		m_a = obj.m_a;
		m_b = obj.m_b;
#endif
		cout << "我也是构造函数" << endl;
	}

	void printT()
	{
		cout << "普通成员函数" << endl;
	}
private:
	int m_a;
	int m_b;
};

int main(int argc, char** argv)
{
	Test7 t1(1, 2);
	Test7 t0(1, 2);
	//第1种初始化方法：用=号
	Test7 t2 = t1;//用t1来初始化t2;
	t2.printT(); //这是个垃圾数据   【因为我们里面啥也没做】

	t0 = t1;//用t1给t0赋值，【赋值操作和初始化是两个不同的概念】

	//第2种初始化方法，用()号
	Test7 t3(t1);
	t1.printT();

	getchar();
	return 0;
}