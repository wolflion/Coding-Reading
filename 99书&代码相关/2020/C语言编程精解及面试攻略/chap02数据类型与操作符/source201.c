// 程序1：在计算圆面积时使用常量pi
// 本程序演示const关键字的使用
#include <stdio.h>
int main()
{
	// 声明常量PI
	const float PI = 3.14159;
	float radius, area;

	printf("\nEnter radius: ");
	scanf("%f",&radius);

	area = PI*radius*radius;
	printf("\nArea of circle: %f", area);
}