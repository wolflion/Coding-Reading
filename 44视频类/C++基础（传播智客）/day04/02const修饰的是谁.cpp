#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b)  // -->Test(Test *this, int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void printT()
	{
		cout << "a:" << a << endl;
		cout << "b:" << this->b << endl;
	}

	//1、const写在什么位置 没有关系

	//const void OpVar(int a, int b)
	void OpVar(int a, int b) const  // ==> void OpVar(Test *this, int a, int b)const
	//2、const修饰的是谁？
	//const 修饰的是形参a？ 不是
	//const 修饰的是属性a? this->a, this->b
	//2-3 const修饰的是this指针所指向的内存空间， 修饰的是this指针

	{
		a = 100;
		//this->a = 100;
		//this->b = 100;
		cout << "a:" << a << endl;
		cout << "b:" << this->b << endl;
	}
protected:
private:
	int a;
	int b;
};

int main(int argc, char** argv)
{
	int *m_space = new int[0];
	if (m_space == NULL)
	{
		return 0;
	}
	getchar();
	return 0;
}