#include <iostream>
using namespace std;


class Test2
{
public:
	Test2()
	{
		m_a = 0;
		m_b = 0;
		cout << "无参构造函数" << endl;
	}
	Test2(int a, int b)
	{
		m_b = b;
		m_a = a;
		cout << "有参构造函数" << endl;
	}

	//赋值构造函数
	Test2(const Test2& obj)
	{
		m_a = obj.m_a;
		m_b = obj.m_b;
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

	Test2 t0401;//调用无参构造函数

	//调用有参构造有3种方法
	//Test2 t0402tmp();//这种表示的是【不调用任何构造函数对象，只是个函数声明】
	//t0402tmp.printT();//这个会报错
	//1种、括号法，C++编译器自动调用；
	Test2 t0402(3, 4);//括号法

	//C++对=进行了功能增强
	//2种、=号法，C++编译器自动调用；
	//Test2 t0403 = ( 3, 4 );//这里后面是 逗号表达式，=后面的值是4，相当于调用只有1个参数的 有参构造函数

	//3种、直接调用构造函数  【手动的调用构造函数】
	//直接调用构造函数，完成对t0404的初始化；【只会调用一次构造函数，原来是调用两次的，t4也调用了一次】
	//这是t0404对象的初始化
	Test2 t0404 = Test2(1, 2);  //这里面会存在 匿名对象（匿名对象的生命周期）

	t0401 = t0404;//这是对象的赋值
	
	getchar();
	return 0;
}