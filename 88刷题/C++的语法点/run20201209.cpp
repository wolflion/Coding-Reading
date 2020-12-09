/*
* 1、派生类2，new派生类1的结果情况：【这个完全是自己理解错了】
* 2、
* 3、C++不支持默认的int。【原因把类的定义写在main后面了，在之前没有引用一下】
*/

#include<iostream>
using namespace std;

class Base {
public:
	Base()
	{
		cout << "Base" << endl;
	}
	virtual ~Base() = default;
};

class D1:public Base
{
public:
	D1()
	{
		cout << "D1" << endl;
	}
	virtual ~D1() = default;
};

class D2 :public D1
{
public:
	D2()
	{
		cout << "D2" << endl;
	}
	virtual ~D2() = default;
};

class Base1
{
public:
	virtual void display() const
	{
		cout << "Base1::display()" << endl;
	}
};

class DBase1 :public Base1
{
public:
	virtual void display()
	{
		cout << "DBase1::display()" << endl;
	}
};


int i = 3;
namespace A
{
	int i = 1;
	//int j = 0;
};

namespace B
{
	int i = 2;
	void fun1();
	void fun2();
	void fun3();
	void fun4();
}

void B::fun1()
{
	using namespace A;
	cout << i << endl;
	//cout << A::i << end;  //这个i怎么就不明确了呢？
	//cout << j << endl;  // 不加namespace A时访问j，就编译不通过。
}

void B::fun2()
{
	using A::i;
	cout << i << endl;
}

void B::fun3()
{
	cout << A::i << endl; 
}

void B::fun4()
{
	cout << i << endl;
}


int main()
{
	//D2* d2 = new D1();  // 这个是错了？  子类，不能用基类创建？

	D1* d1 = new D2();
	delete d1;

	// 第2种场景
	const Base1 *base1 = new DBase1();  //这个地方要*才行；
	DBase1* d1 = new DBase1();
	base1->display();  //Base1的display()
	d1->display();    // DBase1的display()


	//2,1,1,2  【原因是啥？】
	using namespace B;
	fun1();
	fun2();
	fun3();
	fun4();
}

