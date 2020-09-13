// 程序6：演示结构传参
// 使用结构体变量向函数传参
#include <stdio.h>
#include <string.h>

// 全局声明一个结构体
struct student
{
	int rno;
	char name[20];
};

// 用于显示结构体的函数
void display(struct student st);

int main()
{
	// 声明结构体变量
	struct student s;

	// 存储数据至结构体成员变量
	s.rno = 10;
	strcpy(s.name, "Priya");

	// 调用函数，传递结构体变量
	display(s);
}


void display(struct student st)
{
	printf("\nrno: %d", st.rno);
	printf("\nName: %s", st.name);
}