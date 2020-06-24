#include <iostream>
using namespace std;

void myPrint(int a)
{
	cout << a << endl;
}

void myPrint(char *p)
{
	cout << *p << endl;
}

void myPrint(int a, int b)
{
	cout << a << b<<endl;
}

/*
int myPrint(int a, int b)  //只是返回值类型不一样，不是函数重载，编译报错
{
	cout << a << b << endl;
}
*/


int add(int a, int b, int c = 0)
{
	return a + b + c;
}

int add(int a, int b)
{
	return a + b;
}

int main(int argc, char** argv)
{
	myPrint(1);
	myPrint("ab");
	myPrint(1, 2);

	//这个会有二义性，编译器不知道调用谁
	//add(3, 4);

	getchar();
	return 0;
}

