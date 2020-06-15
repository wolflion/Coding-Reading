#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	//动手脚1，virtual
	virtual void print()  //要虚函数
	{
		cout << "Parent" << endl;
	}
private:
	int a;
};

class Child:public Parent(
{
public:
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
	}
	virtual void print() //子类，可加可不加
	{
		cout << "Child" << endl;
	}
private:
	int b;
};

void HowToPlay(Parent *base)
{
	//动手脚2
	base->print();//会有多态发生
}

int main()
{
	Parent p1; //动手脚3  【**对象模型初探**】，C++会增加一个vptr指针	
	Child c1;
	HowToPlay(&p1);
	HowToPlay(&c1);

	system("pause");
	return 0;
}