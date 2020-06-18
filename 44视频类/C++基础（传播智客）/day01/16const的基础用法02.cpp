#include <iostream>
using namespace std;

struct Teacher
{
	char name[64];
	int age;
};

//指针所指向的内存空间，不能被修改
int operatorTeacher(const Teacher* pT)
{
	//pT->age = 10;
	return 0;
}

//pT不能被修改，【指针变量，本身不能被修改】
int operatorTeacher02(Teacher* const pT)
{
	pT->age = 10;
	//pT = NULL;
	return 0;
}

//都不能被修改
int operatorTeacher03(const Teacher* const pT)
{
	//pT->age = 10;
	//pT = NULL;
	printf("都不能被修改,%d",pT->age);
	return 0;
}

void main()
{

	Teacher t1;
	t1.age = 33;
	operatorTeacher03(&t1);

	cout << "hello..." << endl;
	system("pause");
	return;
}