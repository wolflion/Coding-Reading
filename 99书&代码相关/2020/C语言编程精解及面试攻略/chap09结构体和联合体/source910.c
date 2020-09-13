// 程序10：理解如何创建和使用嵌套结构体。dob是嵌套在employee结构中的结构体
// 嵌套结构体
#include <stdio.h>
// 存储生日信息的结构体
struct dob
{
	int dd;
	int mm;
	int yy;
};

// 存储雇员结构的结构体
struct employee
{
	int id;
	char name[20];
	struct dob d; // d是一个dob结构体变量
};

int main()
{
	// 声明employee结构体变量
	struct employee e;

	// 从键盘读入一个employee结构体实例
	printf("\nEnter employee id: ");
	scanf("%d", &e.id);
	fflush(stdin);
	printf("\nEnter employee name: ");
	gets(e.name);
	printf("\nEnter date of birth(dd/mm/yy):");
	scanf("%d/%d/%d", &e.d.dd; &e.d.mm;&e.d.yy);

	// 显示employee结构体实例数据
	printf("\nId = %d", e.id);
	printf("\nname = %s", e.name);
	printf("\nDate of birth: %d / %d / %d", e.d.dd,e.d.mm,e.d.yy);
}