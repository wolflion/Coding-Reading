#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		a = 0;
		b = 0;
		cout << "无参构造函数 自动被调用" << endl;
	}
	Test(int _a)
	{
		a = _a;
		b = 0;
	}
	Test(const Test& obj)
	{
		a = obj.a + 100;
		b = obj.b + 100;
	}

	void printT()
	{
		cout << a << b << endl;
	}
	~Test()
	{
		cout << "析构函数" << endl;
	}
protected:
private:
	int a;
	int b;
};

int main(int argc, char** argv)
{

	getchar();
	return 0;
}