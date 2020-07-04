#include <iostream>
using namespace std;

class A
{
public:
	A(int _a)
	{
		a = _a;
		cout << "构造函数" << "a" << a << endl;
	}

	~A()
	{
		cout << "析构函数"<<"a" << a << endl;
	}
protected:
private:
	int a;
};

class B
{
public:
protected:
private:
	int b1;
	int b2;
	A a1; //没有合适的构造函数
	A a2;
};

//构造函数的初始化列表 解决：在B类中 组合了一个 A类对象（A类设计了构造函数）
//根据构造函数的调用规则：写了A的构造函数，必须要用，没有机会初始化A
//新的语法：`Construcotr::Contructor():m1(v1),m2(v1,v2),m3(v3)`
class C
{
public:
	//初始化列表 用来 给const属性 赋值
	C(int _b1, int _b1) :a1(1), a2(2) , c(0)
	{
		
	}

	C(int _b1, int _b2, int m, int n) :a1(m), a2(n) , c(0)
	{
		b1 = _b1;
		b2 = _b2;
		cout << "C的构构函数" << endl;
	}

	~C()
	{
		cout << "C的析构函数" << endl;
	}
protected:
private:
	int b1;
	int b2;
	A a1;
	A a2;
	const int c;
};

int main(int argc, char** argv)
{
	A a1(10);
	B objB;//这个会报错，没有初始化A的对象

	C objC(1, 2);
	//1、参数传递
	C objC1(1, 2, 3, 4);

	//2、调用顺序
	// 先执行 被组合对象的构造函数（如果组合对象有多个，按照定义顺序，而不是按照初始化列表的顺序）
	// 析构函数：和构造函数调用顺序相反
	getchar();
	return 0;
}

//被组合对象的构造顺序 与定义顺序有关系，与初始化列表的顺序没有关系