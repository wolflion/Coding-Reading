// 程序7：使用结构体指针传递结构体实例
// 使用结构体指针向函数传参
#include <stdio.h>
#include <string.h>

// 全局声明一个结构体
struct student
{
	int rno;
	char name[20];
};

// 用于显示结构体的函数
void display(struct student *ptr);

int main()
{
	// 声明结构体变量
	struct student *s;  // 定义一个s，然后传&s，应该也是一样的吧

	// 存储数据至结构体成员变量
	s->rno = 10;
	strcpy(s->name, "Priya");

	// 调用函数，传递结构体变量
	display(s);
}


void display(struct student *ptr)
{
	printf("\nrno: %d", ptr->rno);
	printf("\nName: %s", ptr->name);
}