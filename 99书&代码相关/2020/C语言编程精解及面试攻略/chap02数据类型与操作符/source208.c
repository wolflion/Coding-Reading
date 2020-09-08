// 程序8：两个整数相除时使用类型转换
// 计算两个整数相除的结果---版本2
#include <stdio.h>
int main()
{
	int x = 3, y = 2;
	float z = (float)x / y;  // 将整数类型转换为浮点数类型

	printf("\nResult of division= %f", z);
}