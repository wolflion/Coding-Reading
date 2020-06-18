#include <iostream>
using namespace std;

void main()
{
	const int a;
	int const b;  //两个是一样的

	const int *c; //const修饰的是指针所指向的内存空间，不能被修改
	int * const d; //指向的值不能被修改
	const int* const e;
	cout << "hello..." << endl;
	system("pause");
	return;
}