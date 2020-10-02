#include <iostream>
using std::cout;

class base
{
public:
	base()
	{
		cout << "构造base对象" << endl;
		f();
	}
	virtual void f()
	{
		cout << "调用base::f()" << endl;
	}
};

class derive :public base
{
public:
	derive()
	{
		cout << "构造derive对象" << endl;
		f();
	}
	void f()
	{
		cout << "调用derive::f()" << endl;
	}
};

int main()
{
	derive d;  // 先调用base类，再derive类
	return 0;
}


// 对‘std::ostream::operator<<(std::ostream& (*)(std::ostream&))’未定义的引用，自己用的是gcc编译器

/*输出
构造base对象
调用base::f()
构造derive对象
调用derive::f()
*/