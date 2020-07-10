#include <iostream>
using namespace std;

class Test
{
public:
	int a;
	int b;
public:
	~Test()
	{
		cout << "析构函数自动被调用" << endl;
	}

	Test(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
	}

	//t3 = t1.TestAdd(t2);
	Test TestAdd(Test &t2)
	{
		Test tmp(this->a + t2.a, this->b + t2.b);
		return tmp;
	}

	void printT()
	{
		cout << "a:" << a << "b:" << b << endl;
	}
protected:
private:
};

Test TestAdd(Test &t1, Test &t2)
{
	Test tmp;
	return tmp;
}

//把成员函数 转成 全局函数，多了一个参数
void print(Test *pT)
{
	cout << "a:" << pT->a << "b:" << pT->b << endl;
}

int main(int argc, char** argv)
{
	Test t1(1, 2);
	Test t2(3, 4);

	Test t3;

	//t1 + t2  //暂时通过全局函数来实现
	t3 = TestAdd(t1, t2);

	//先把测试案例写出来  【成员函数方法】
	Test t4 = t1.TestAdd(t2);//匿名对象直接转换为t4
	t4.printT();

	Test t5;
	t5 = t1.TestAdd(t2);   //匿名对象 复制  给t5
	t5.printT();

	getchar();
	return 0;
}