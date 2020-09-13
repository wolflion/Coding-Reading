// 程序7：向函数传递结构体指针参数，并从函数返回一个结构体指针
// 结构体指针形参及函数返回结构体指针
#include <stdio.h>
#include <string.h>

// 全局声明一个结构体
struct student
{
	int rno;
	char name[20];
};

struct student s = { 10, "Priya" };  // 初始化
struct student *p1, *p2; // 结构体指针

// 显示结构体的函数，接收一个结构体指针
struct student* display(struct student *ptr);

int main()
{
	// 将结构体地址保存至指针p1中
	p1 = &s;

	// 调用函数，传递结构体指针参数中
	p2 = display(p1);

	printf("\nrno: %d", p2->rno);
	printf("\nName: %s", p2->name);
}

// display函数修改了结构体成员
struct student* display(struct student *ptr)
{
	// 修改结构体成员
	ptr->rno++;
	strpy(ptr->name, "Lakshmi");
	return ptr;
}