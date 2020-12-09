/*
* 1��������2��new������1�Ľ��������������ȫ���Լ������ˡ�
* 2��
* 3��C++��֧��Ĭ�ϵ�int����ԭ�����Ķ���д��main�����ˣ���֮ǰû������һ�¡�
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
	//cout << A::i << end;  //���i��ô�Ͳ���ȷ���أ�
	//cout << j << endl;  // ����namespace Aʱ����j���ͱ��벻ͨ����
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
	//D2* d2 = new D1();  // ����Ǵ��ˣ�  ���࣬�����û��ഴ����

	D1* d1 = new D2();
	delete d1;

	// ��2�ֳ���
	const Base1 *base1 = new DBase1();  //����ط�Ҫ*���У�
	DBase1* d1 = new DBase1();
	base1->display();  //Base1��display()
	d1->display();    // DBase1��display()


	//2,1,1,2  ��ԭ����ɶ����
	using namespace B;
	fun1();
	fun2();
	fun3();
	fun4();
}

