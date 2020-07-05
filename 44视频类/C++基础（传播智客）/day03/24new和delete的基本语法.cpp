#include <iostream>
using namespace std;

//1、new delete操作符是C++的语法（有点像C语言的malloc 和 free）

//2、可以创建基础类型变量，也可以分配置数组变量，分配 复杂类型（比如类类型）


//分配基础类型
int main301(int argc, char** argv)
{
	
	int *a = (int*)malloc(sizeof(int));
	*p = 10;
	free(p);

	int *p2 = new int;
	*p2 = 20;
	delete p2;

	//分配的同时，初始化
	int *p3 = new int(30);
	cout << *p3 << endl;//这时*p3的值是30
	delete p3;

	getchar();
	return 0;
}

//分配数组
void main302()
{
	//int array[10];
	int *p = (int *)malloc(sizeof(int)* 10);
	p[0] = 1;
	free(p);

	//c++分配数组
	int *pArray = new int[10];  //记下这种语法，与格式
	delete[] pArray; //数组不要忘记[]
}

class Test
{
public:
	Test(int _a)
	{
		a = _a;
	}

	~Test()
	{
		cout << "exec deconstructor" << endl;
	}
protected:
private:
	int a;
};

//分配对象
//**虽然new和malloc都能分配空间，但new可以自动调用类写的构造函数，同理，delete会调用析构函数**。
void main()
{
	//C语言
	Test *pT1 = (Test*)malloc(sizeof(Test));
	free(pT1);

	//C++
	Test *pT2 = new Test(10);  //这个时候，会调用构造函数
	delete pT2;
}