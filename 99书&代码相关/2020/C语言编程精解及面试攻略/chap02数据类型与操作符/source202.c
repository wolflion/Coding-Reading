// 程序2：在计算圆面积时使用#define语句
#define PI 3.14159
#include <stdio.h>
int main()
{
	float radius, area;

	printf("\nEnter radius: ");
	scanf("%f",&radius);

	area = PI*radius*radius;
	printf("\nArea of circle: %f", area);
}

//define的好处在于  不占用内存