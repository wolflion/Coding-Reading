#include <iostream>
using namespace std;

//1、函数默认参数
//void myPrint1(int y, int x=3){}
//void myPrint2(int x=3,int y){}  //这种情况，会编译报错
void myPrint(int x = 3)//多个默认时，最右边必须要有默认参数
{
	cout << "x=" << x << endl;
}

//2、函数占位参数
void func1(int a, int b, int)
{
	cout << "a" << a << "b" << b << endl;
}

//默认参数和占位参数 结合使用
void func2(int a, int b, int = 0)
{
	cout << "a" << a << "b" << b << endl;
}

int main(int argc, char** argv)
{
	myPrint(4);
	myPrint();

	//func1(1, 2);  //这种情况会报错
	func1(1, 2, 3);

	//结合使用时，都没有错误
	func2(1, 2);
	func2(1, 2, 3);
	getchar();
	return 0;
}

