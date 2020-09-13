// 程序11：用来显示系统日期和时间
// 用来显示系统日期和时间
#include <stdio.h>
#include <dos.h>  // 内置结构体time

int main()
{
	// 创建一个date结构体变量
	struct date d;

	// 创建time结构体变量
	struct time t;

	// 用系统日期填充d
	getdate(&d);

	// 用系统时间填充t
	gettime(&t);

	// 显示系统日期
	printf("\n%2d/%2d/%2d", d.da_day, d.da_mon, d.da_year);

	// 显示系统时间
	printf("\n%2d/%2d/%2d", t.ti_hour,t.ti_min,t.ti_sec);
}