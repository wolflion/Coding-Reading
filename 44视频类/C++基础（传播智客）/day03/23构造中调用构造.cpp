#include <iostream>
using namespace std;

class MyTest
{
public:
	MyTest(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	MyTest(int a, int b)
	{
		this->a = a;
		this->b = b;
		
		MyTest(a, b, 100);  //直接调用构造函数，会产生一个匿名对象，没有人接，会被销毁掉。
	}

	~MyTest()
	{
		cout << "MyTest~" << a << b << c;
	}
protected:
private:
	int a;
	int b;
	int c;

public:
	int getC() const { return c; }
	void setC(int val) { c = val; }
};

int main(int argc, char** argv)
{
	MyTest t1(1, 2);  //100的那个匿名对象与t1没有关系，所以 出来是 乱码
	cout << "c的值是：" << t1.getC() << endl;  // 这里c不是100，c打出来是乱码。



	getchar();
	return 0;
}