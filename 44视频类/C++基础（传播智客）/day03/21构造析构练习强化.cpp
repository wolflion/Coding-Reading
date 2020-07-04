#include <iostream>
using namespace std;

class ABCD
{
public:
	ABCD(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		cout << "ABCD() construct" << this->a << this->b << this->c << endl;
	}
	~ABCD()
	{
		cout << "ABCD() deconstruct" << this->a << this->b << this->c << endl;
	}

	int getA()
	{
		return this->a;
	}
protected:
private:
	int a;
	int b;
	int c;
};

class MyE
{
public:
	MyE() :abcd1(1, 2, 3), abcd2(4, 5, 6), m(100)
	{
		cout << "MyE()" << endl;
	}
	~MyE()
	{
		cout << "~MyE()" << endl;
	}
	MyE(const MyE& obj) :abcd1(7, 8, 9), abcd2(10, 11, 12), m(100)
	{
		cout << "MyE(const MyE &obj)" << endl;
	}
protected:
//private:
public:
	ABCD abcd1; //C++编译器不知道如何构造abc1
	ABCD abcd2;
	const int m;
};

int doThing(MyE mye1)  //非指针和引用，用实参初始化形参，会调用 拷贝构造函数。
{
	cout << "doThing() mye1.abc1.a" << mye1.abcd1.getA() << endl;
	return 0;
}

int run2()
{
	MyE myE;
	doThing(myE);
	return 0;
}

int run3()
{
	cout << "run3 start" << endl;
	cout << "run3 end" << endl;
	return 0;
}

int main(int argc, char** argv)
{
	run2();
	//run3();

	getchar();
	return 0;
}

//自己要分析一下执行结果；自己先看代码，能不能读懂代码