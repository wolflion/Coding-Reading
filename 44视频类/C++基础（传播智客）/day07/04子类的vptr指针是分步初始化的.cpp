#include <iostream>
using namespace std;

//构造函数中调用虚函数能发生多态吗？

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		print();//父类里执行虚函数
	}
	virtual void print()
	{
		cout << "Parent" << endl;
	}
private:
	int a;
};

class Child :public Parent(
{
public:
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
		//todo:
		//第2步，可以在这个地方再加print();,看看执行效果。
	}
	virtual void print()
	{
		cout << "Child" << endl;
	}
private:
	int b;
};

void HowToPlay(Parent *base)
{
	base->print();
}

int main()
{	
	Child c1;  //定义一个子类对象，在这个过程中，在父类构造函数中调用虚函数print会发生多态吗？【**不能**】

	system("pause");
	return 0;
}