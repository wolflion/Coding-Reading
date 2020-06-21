#include <iostream>
using namespace std;

//
struct Teacher
{
	char name[64];
	int age;
};

//在被调用函数，获取资源
void getTeacher(Teacher **p)
{
	Teacher *tmp = NULL;
	if (p == NULL)
	{
		return -1;
	}
	tmp = (Teacher *)malloc(sizeof(Teacher);
	if (tmp == NULL)
	{
		return -1;
	}
	tmp->age = 33;
	//p是实参的地址，*实参的地址，去间接的修改实参的值。
	*p = tmp;
}

void main()
{
	Teacher *pT1 = NULL;

	getTeacher(&pT1);//二级指针

	cout << "age" << pT1->age << endl;

	cout << "hello..." << endl;
	system("pause");
}