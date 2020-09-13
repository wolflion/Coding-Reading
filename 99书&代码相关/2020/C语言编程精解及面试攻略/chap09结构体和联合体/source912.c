// 程序12：用来展示创建包含两个数据成员的联合体
// 联合体的行为
#include <stdio.h>

int main()
{
	// 定义一个联合体
	union mixed
	{
		char ch;
		int in;
	};

	// 声明联合体变量 u
	union mixed u;

	// 将字符A保存到u的数据成员ch中
	u.ch = 'A';

	// 显示该联合体实例的两个数据成员
	printf("\nch value=%c", u.ch);
	printf("\nin value=%i", u.in);
}