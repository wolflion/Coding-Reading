#include<iostream>
using namespace std;

//定义一个测试类
struct TestClass
{
	int xx;
	TestClass(int x)
	{
		xx = x;
		cout << "构造对象，xx=" << xx << endl;
	}

	~TestClass()
	{
		cout << "析构对象，xx=" << xx << endl;
	}
};


int main()
{
	//使用全局operator new请求一个能存放4个TestClass对象内存块
	TestClass* bp = (TestClass*)::operator new(sizeof(TestClass) * 4);

	//在内存块中使用placement new创建一个对象
	TestClass* p1 = bp;
	new(p1)TestClass(100);

	//显式调用TestClass析构函数销毁对象
	p1->~TestClass();

	//按照上述方法创建第二个对象
	TestClass* p2 = p1 + 1;   //这个我能理解，指向原有分配的地址上。
	new(p2)TestClass(200);  // 疑问：不赋值给一个对象，有点怪异，难道是右值引用？
	p2->~TestClass();

	//释放内存块
	::operator delete(bp);
	return 0;
}