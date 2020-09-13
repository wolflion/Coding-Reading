// 程序9：通过结构体变量赋值来拷贝结构体实例
// 将一个结构体变量的数据拷贝到另外一个结构体变量中
#include <stdio.h>
#include <string.h>

int main()
{
	// 定义结构体
	struct employee
	{
		int id;
		char name[20];
	};

	// 初始化e1
	struct employee e1 = { 10, "Venu" };

	// e2也是结构体变量
	struct employee e2;

	// 将e1的内容拷贝到e2中
	e2 = e1;

	//显示e2的内容
	printf("\nId=%d", e2.id);
	printf("\nName=%s", e2.name);
}